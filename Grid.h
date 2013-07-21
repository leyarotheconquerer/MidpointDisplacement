#ifndef GRID_H
#define	GRID_H

namespace MidpointDisplacement
{

    class Grid {
    public:
        /**
         * Generates a grid object with randomly generated shades for each of
         * the 4 corners. Uses a default resolution of 100x100.
         */
        Grid();
        
        /**
         * Generates a grid object with the 4 corners initialized to the given
         * values. Uses a default resolution of 100x100.
         * @param corners An array containing the shades for the 4 corners.
         */
        Grid(float* corners);
        
        /**
         * Generates a grid object with randomly generated shades for each of
         * the 4 corners. Uses the custom resolution of the given dimensions.
         * @param width The width of the Grid object.
         * @param height The height of the Grid object.
         */
        Grid(int width, int height);
        
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
         * Gets the shade of a specific coordinate in the grid.
         * @param x The x coordinate. (Column/horizontal coordinate)
         * @param y The y coordinate. (Row/vertical coordinate)
         * @return A shade valued from 0 to 1. Returns -1 if the value is
         * uninitialized.
         */
        float getShade(int x, int y);
        
    private:
        float** grid;
    };

}

#endif	/* GRID_H */

