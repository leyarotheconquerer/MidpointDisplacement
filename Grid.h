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
         * @return Width of the Grid.
         */
        int getWidth();
        
        /**
         * @return Height of the Grid.
         */
        int getHeight();
        
        /**
         * @return The maximum dimension of the Grid.
         */
        int getMaxDimension();
        
        /**
         * Iterates through each Corner set at a given level. Levels are
         * integers ranging from 0 (the top level) to maxDimension/2?
         */
        class Level_Iterator : public std::iterator<std::forward_iterator_tag, CornerSet>
        {
        public:
            void initialize(Grid* parent, CornerSet initial)
            {
                // Store the parent object
                this->parent = parent;
                
                // Calculate the distance for each iteration
                iterateWidth = (parent->width - 1) / pow(2, initial.level);
                iterateHeight = (parent->height - 1) / pow(2, initial.level);
                
                // Store the mode in which to begin
                p = initial;
                
                // Set up the coordinates
                if(p.corner1Coor[0] == -1 && p.corner1Coor[1] == -1 &&
                        p.corner2Coor[0] == -1 && p.corner2Coor[1] == -1 &&
                        p.corner3Coor[0] == -1 && p.corner3Coor[1] == -1 &&
                        p.corner4Coor[0] == -1 && p.corner4Coor[1] == -1)
                {
                    // Do nothing. This is a null iterator... This should probably
                    // be handled more cleanly.
                }
                else if(!initial.diamondMode)
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
                    std::cout << "Warning: Iterator returned invalid values." << std::endl;
                }
            }
            
            Level_Iterator(Grid* parent, CornerSet initial)
            {
                initialize(parent, initial);
            }
            
            Level_Iterator(Grid* parent, int level, bool diamondMode)
            {
                CornerSet temp;
                temp.level = level;
                temp.diamondMode = diamondMode;
                initialize(parent, temp);
            }
            
            virtual ~Level_Iterator() {}
            
            /**
             * Pre-increment
             */
            Level_Iterator& operator++()
            {   
                int level = p.level;
                
                if(!p.diamondMode)
                {
                    p = getNextRectangle();
                    p.diamondMode = false;
                }
                else
                {
                    p = getNextDiamond();
                    p.diamondMode = true;
                }
                
                p.level = level;
                
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
                return (p.corner1Coor[0] == other.p.corner1Coor[0] &&
                        p.corner1Coor[1] == other.p.corner1Coor[1] &&
                        p.corner2Coor[0] == other.p.corner2Coor[0] &&
                        p.corner2Coor[1] == other.p.corner2Coor[1] &&
                        p.corner3Coor[0] == other.p.corner3Coor[0] &&
                        p.corner3Coor[1] == other.p.corner3Coor[1] &&
                        p.corner4Coor[0] == other.p.corner4Coor[0] &&
                        p.corner4Coor[1] == other.p.corner4Coor[1] &&
                        parent == other.parent);
            }
            
            bool operator==(const CornerSet& other)
            {
                return (p.corner1Coor[0] == other.corner1Coor[0] &&
                        p.corner1Coor[1] == other.corner1Coor[1] &&
                        p.corner2Coor[0] == other.corner2Coor[0] &&
                        p.corner2Coor[1] == other.corner2Coor[1] &&
                        p.corner3Coor[0] == other.corner3Coor[0] &&
                        p.corner3Coor[1] == other.corner3Coor[1] &&
                        p.corner4Coor[0] == other.corner4Coor[0] &&
                        p.corner4Coor[1] == other.corner4Coor[1]);
            }
            
            bool operator!=(const Level_Iterator& other)
            {
                return (!(*this == other));
            }
            
            bool operator!=(const CornerSet& other)
            {
                return (!(*this == other));
            }
            
            CornerSet operator*()
            {
                return p;
            }
            
            CornerSet* operator->()
            {
                return &p;
            }
            
            const CornerSet* operator->() const
            {
                return &p;
            }
            
        private:
            CornerSet p;
            int iterateWidth, iterateHeight;
            Grid* parent;
            
            CornerSet getFirstRectangle()
            {
                CornerSet temp;
                
                temp.corner1Coor[0] = 0;
                temp.corner1Coor[1] = 0;
                
                temp.corner2Coor[0] = iterateWidth;
                temp.corner2Coor[1] = 0;
                
                temp.corner4Coor[0] = 0;
                temp.corner4Coor[1] = iterateHeight;
                
                temp.corner3Coor[0] = iterateWidth;
                temp.corner3Coor[1] = iterateHeight;
                
                temp.level = p.level;
                temp.diamondMode = p.diamondMode;
                
                return temp;
            }
            
            CornerSet getFirstDiamond()
            {
                CornerSet temp;
                
                temp.corner1Coor[0] = iterateWidth / 2;
                temp.corner1Coor[1] = -iterateHeight / 2;
                
                temp.corner2Coor[0] = iterateWidth;
                temp.corner2Coor[1] = 0;
                
                temp.corner3Coor[0] = iterateWidth / 2;
                temp.corner3Coor[1] = iterateHeight / 2;
                
                temp.corner4Coor[0] = 0;
                temp.corner4Coor[1] = 0;
                
                temp.level = p.level;
                temp.diamondMode = p.diamondMode;
                
                return temp;
            }
            
            CornerSet getNextRectangle()
            {
                CornerSet tmp;
                
                // Check to see if the x coordinate has reached the width
                if((iterateWidth > 0 && p.corner3Coor[0] >= parent->width-1) ||
                        (iterateWidth < 0 && p.corner4Coor[0] <= 0))
                {
                    // Stay on the same column
                    tmp.corner1Coor[0] = p.corner1Coor[0];
                    tmp.corner2Coor[0] = p.corner2Coor[0];
                    tmp.corner3Coor[0] = p.corner3Coor[0];
                    tmp.corner4Coor[0] = p.corner4Coor[0];
                    
                    // Move to the next row
                    tmp.corner1Coor[1] = p.corner1Coor[1] + iterateHeight;
                    tmp.corner2Coor[1] = p.corner2Coor[1] + iterateHeight;
                    tmp.corner3Coor[1] = p.corner3Coor[1] + iterateHeight;
                    tmp.corner4Coor[1] = p.corner4Coor[1] + iterateHeight;
                    
                    if(tmp.corner2Coor[1] >= parent->height-1)
                    {
                        tmp.corner1Coor[0] = -1;
                        tmp.corner1Coor[1] = -1;
                        
                        tmp.corner2Coor[0] = -1;
                        tmp.corner2Coor[1] = -1;
                        
                        tmp.corner3Coor[0] = -1;
                        tmp.corner3Coor[1] = -1;
                        
                        tmp.corner4Coor[0] = -1;
                        tmp.corner4Coor[1] = -1;
                    }
                    
                    // Flip horizontal delta
                    iterateWidth = -iterateWidth;
                }
                else
                {
                    // Move to the next column
                    tmp.corner1Coor[0] = p.corner1Coor[0] + iterateWidth;
                    tmp.corner2Coor[0] = p.corner2Coor[0] + iterateWidth;
                    tmp.corner3Coor[0] = p.corner3Coor[0] + iterateWidth;
                    tmp.corner4Coor[0] = p.corner4Coor[0] + iterateWidth;
                    
                    // Stay on the same level
                    tmp.corner1Coor[1] = p.corner1Coor[1];
                    tmp.corner2Coor[1] = p.corner2Coor[1];
                    tmp.corner3Coor[1] = p.corner3Coor[1];
                    tmp.corner4Coor[1] = p.corner4Coor[1];
                }
                
                tmp.diamondMode = p.diamondMode;
                tmp.level = p.level;
                
                return tmp;
            }
            
            CornerSet getNextDiamond()
            {
                CornerSet temp;
                
                // Check to see if the x coordinate has reached the width
                if((iterateWidth > 0 && p.corner2Coor[0] >= parent->width-1) ||
                        (iterateWidth < 0 && p.corner1Coor[0] <= 0))
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
                    
                    if(p.corner2Coor[1] >= parent->height-1)
                    {
                        temp.corner1Coor[0] = -1;
                        temp.corner1Coor[1] = -1;
                        
                        temp.corner2Coor[0] = -1;
                        temp.corner2Coor[1] = -1;
                        
                        temp.corner3Coor[0] = -1;
                        temp.corner3Coor[1] = -1;
                        
                        temp.corner4Coor[0] = -1;
                        temp.corner4Coor[1] = -1;
                    }
                    
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
                
                temp.diamondMode = p.diamondMode;
                temp.level = p.level;
                
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
        
        /**
         * Get an iterator for the beginning of the current object.
         * @param level The level of subdivision for the iterator.
         * @param diamondMode Whether or not the iterator should return diamonds
         * or rectangles.
         * @return The iterator.
         */
        Level_Iterator& begin(int level, bool diamondMode)
        {
            Level_Iterator* temp = new Level_Iterator(this, level, diamondMode);
            return *temp;
        }
        
        /**
         * Get an iterator for the end of the current object.
         * @param level The level of subdivision for the iterator.
         * @param diamondMode Whether or not the iterator should return diamonds
         * or rectangles.
         * @return The iterator.
         */
        Level_Iterator& end(int level, bool diamondMode)
        {
            CornerSet corners;
            corners.corner1Coor[0] = -1;
            corners.corner1Coor[1] = -1;
            corners.corner2Coor[0] = -1;
            corners.corner2Coor[1] = -1;
            corners.corner3Coor[0] = -1;
            corners.corner3Coor[1] = -1;
            corners.corner4Coor[0] = -1;
            corners.corner4Coor[1] = -1;
            corners.level = level;
            corners.diamondMode = diamondMode;
            Level_Iterator* temp = new Level_Iterator(this, corners);
            
            return *temp;
        }
        
    private:
        float** grid;
        int width, height;
        int maxDimension;
        
        void initialize(float* corners, int width, int height);
    };

}

#endif	/* GRID_H */

