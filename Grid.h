#ifndef GRID_H
#define	GRID_H

#include "MidpointGenerator.h"
#include <math.h>
#include <iostream>

namespace MidpointDisplacement
{

    struct CornerSet
    {
        int corner1Coor[2]; // Top left/Top
        int corner2Coor[2]; // Top right/Right
        int corner3Coor[2]; // Bottom right/Bottom
        int corner4Coor[2]; // Bottom left/Left
        float corner1, corner2, corner3, corner4;
        int level;
        bool diamondMode;
    };
    
    class Grid {
    public:
        /**
         * Generates a grid object with the 4 corners initialized to the given
         * values. Uses a default resolution of 100x100.
         * @param corners An array containing the shades for the 4 corners.
         */
        Grid(float* corners);
        
        /**
         * Generates a grid object with the 4 corners initialized to the given
         * values. Uses the custom resolution of the given dimensions.
         * @param corners An array containing the shades for the 4 corners.
         * @param width The width of the Grid object.
         * @param height The height of the Grid object.
         */
        Grid(float* corners, int width, int height);
        
        Grid(const Grid& orig);
        virtual ~Grid();
        
        /**
         * Sets the shade of a specific coordinate in the grid.
         * @param shade The shade to set the coordinate to.
         * @param x The x coordinate. (Column/horizontal coordinate)
         * @param y The y coordinate. (Row/vertical coordinate)
         */
        void setShade(float shade, int x, int y);
        
        /**
         * Gets the shade of a specific coordinate in the grid.
         * @param x The x coordinate. (Column/horizontal coordinate)
         * @param y The y coordinate. (Row/vertical coordinate)
         * @return A shade valued from 0 to 1. Returns -1 if the value is
         * uninitialized.
         */
        float getShade(int x, int y);
        
        /**
         * Iterates through each Corner set at a given level. Levels are
         * integers ranging from 0 (the top level) to maxDimension/2?
         */
        class Level_Iterator : public std::iterator<std::forward_iterator_tag, CornerSet>
        {
        public:
            Level_Iterator(Grid* parent, int level, bool diamondMode)
            {
                // Store the parent object
                this->parent = parent;
                
                // Calculate the distance for each iteration
                iterateWidth = (parent->width - 1) / pow(2, level);
                iterateHeight = (parent->height - 1) / pow(2, level);
                
                // Store the mode in which to begin
                p.diamondMode = diamondMode;
                
                // Set up the coordinates2222
                if(!diamondMode)
                {
                    p = getFirstRectangle();
                }
                else
                {
                    p = getFirstDiamond();
                }
                
                // Calculate the shade of each corner in the iterator
                calculateShades();
                
                // Validate that the iterator is valid (debugging purposes)
                if(p.corner1 == -1 || p.corner2 == -1 ||
                        p.corner4 == -1 || p.corner3 == -1)
                {
                    std::cerr << "Warning: Iterator returned invalid values.";
                }
            }
            
            virtual ~Level_Iterator() {}
            
            /**
             * Pre-increment
             */
            Level_Iterator& operator++()
            {
                if(!p.diamondMode)
                {
                    p = getNextRectangle();
                }
                else
                {
                    p = getNextDiamond();
                }
                
                calculateShades();
                
                return *this;
            }
            
            /**
             * Post increment
             */
            Level_Iterator operator++(int)
            {
                Level_Iterator temp(*this);
                operator++();
                temp.calculateShades(); // Shouldn't be necessary, but just to be sure.
                return temp;
            }
            
            bool operator==(const Level_Iterator& other)
            {
                return (p.corner1 == other.p.corner1 &&
                        p.corner2 == other.p.corner2 &&
                        p.corner3 == other.p.corner3 &&
                        p.corner4 == other.p.corner4);
            }
            
            bool operator!=(const Level_Iterator& other)
            {
                return (p.corner1 != other.p.corner1 ||
                        p.corner2 != other.p.corner2 ||
                        p.corner3 != other.p.corner3 ||
                        p.corner4 != other.p.corner4);
            }
            
            CornerSet* operator*()
            {
                return &p;
            }
            
        private:
            CornerSet p;
            int iterateWidth, iterateHeight;
            Grid* parent;
            
            CornerSet getFirstRectangle()
            {
                p.corner1Coor[0] = 0;
                p.corner1Coor[1] = 0;
                
                p.corner2Coor[0] = iterateWidth;
                p.corner2Coor[1] = 0;
                
                p.corner4Coor[0] = 0;
                p.corner4Coor[1] = iterateHeight;
                
                p.corner3Coor[0] = iterateWidth;
                p.corner3Coor[1] = iterateHeight;
            }
            
            CornerSet getFirstDiamond()
            {
                p.corner1Coor[0] = iterateWidth / 2;
                p.corner1Coor[1] = -iterateHeight / 2;
                
                p.corner2Coor[0] = iterateWidth;
                p.corner2Coor[1] = 0;
                
                p.corner3Coor[0] = iterateWidth / 2;
                p.corner3Coor[1] = iterateHeight / 2;
                
                p.corner4Coor[0] = 0;
                p.corner4Coor[1] = 0;
            }
            
            CornerSet getNextRectangle()
            {
                CornerSet temp;
                
                // Move to the next column
                temp.corner1Coor[0] = p.corner1Coor[0] + iterateWidth;
                temp.corner2Coor[0] = p.corner2Coor[0] + iterateWidth;
                temp.corner3Coor[0] = p.corner3Coor[0] + iterateWidth;
                temp.corner4Coor[0] = p.corner4Coor[0] + iterateWidth;
                
                // Check to see if the x coordinate has reached the width
                if(p.corner3Coor[0] >= parent->width)
                {
                    // Move to the next row
                    temp.corner1Coor[1] = p.corner1Coor[1] + iterateHeight;
                    temp.corner2Coor[1] = p.corner2Coor[1] + iterateHeight;
                    temp.corner3Coor[1] = p.corner3Coor[1] + iterateHeight;
                    temp.corner4Coor[1] = p.corner4Coor[1] + iterateHeight;
                    
                    // Flip horizontal delta
                    iterateWidth = -iterateWidth;
                }
                else
                {
                    // Stay on the same level
                    temp.corner1Coor[1] = p.corner1Coor[1];
                    temp.corner2Coor[1] = p.corner2Coor[1];
                    temp.corner3Coor[1] = p.corner3Coor[1];
                    temp.corner4Coor[1] = p.corner4Coor[1];
                }
                
                return temp;
            }
            
            CornerSet getNextDiamond()
            {
                CornerSet temp;
                
                // Check to see if the x coordinate has reached the width
                if(p.corner1Coor[0] >= parent->width)
                {
                    // Get the positive shift width for the row shift
                    int posIterateWidth;
                    if(iterateWidth < 0)
                    {
                        posIterateWidth = -iterateWidth;
                    }
                    else
                    {
                        posIterateWidth = iterateWidth;
                    }
                    
                    // Shift right horizontally
                    temp.corner1Coor[0] = p.corner1Coor[0] + (posIterateWidth / 2);
                    temp.corner2Coor[0] = p.corner2Coor[0] + (posIterateWidth / 2);
                    temp.corner3Coor[0] = p.corner3Coor[0] + (posIterateWidth / 2);
                    temp.corner4Coor[0] = p.corner4Coor[0] + (posIterateWidth / 2);
                    
                    // Shift down vertically
                    temp.corner1Coor[1] = p.corner1Coor[1] + (iterateHeight / 2);
                    temp.corner2Coor[1] = p.corner2Coor[1] + (iterateHeight / 2);
                    temp.corner3Coor[1] = p.corner3Coor[1] + (iterateHeight / 2);
                    temp.corner4Coor[1] = p.corner4Coor[1] + (iterateHeight / 2);
                    
                    iterateWidth = -iterateWidth;
                }
                else
                {
                    // Shift horizontally
                    temp.corner1Coor[0] = p.corner1Coor[0] + iterateWidth;
                    temp.corner2Coor[0] = p.corner2Coor[0] + iterateWidth;
                    temp.corner3Coor[0] = p.corner3Coor[0] + iterateWidth;
                    temp.corner4Coor[0] = p.corner4Coor[0] + iterateWidth;
                    
                    // Stay on the same level
                    temp.corner1Coor[1] = p.corner1Coor[1];
                    temp.corner2Coor[1] = p.corner2Coor[1];
                    temp.corner3Coor[1] = p.corner3Coor[1];
                    temp.corner4Coor[1] = p.corner4Coor[1];
                }
                
                return temp;
            }
            
            void calculateShades()
            {
                p.corner1 = parent->getShade(p.corner1Coor[0], p.corner1Coor[1]);
                p.corner2 = parent->getShade(p.corner2Coor[0], p.corner2Coor[1]);
                p.corner4 = parent->getShade(p.corner4Coor[0], p.corner4Coor[1]);
                p.corner3 = parent->getShade(p.corner3Coor[0], p.corner3Coor[1]);
            }
        };
        
    private:
        float** grid;
        int width, height;
        int maxDimension;
    };

}

#endif	/* GRID_H */

