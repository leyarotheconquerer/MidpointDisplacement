#ifndef MIDPOINTGENERATOR_H
#define	MIDPOINTGENERATOR_H

#include "Grid.h"

namespace MidpointDisplacement
{
    struct CornerSet;
    
    class Grid;
    
    class MidpointGenerator {
    public:
        MidpointGenerator() {}
        MidpointGenerator(const MidpointGenerator& orig) {}
        virtual ~MidpointGenerator() {}
        
        /**
         * Generates a grid using randomly generated shades for each of the 4
         * corners. Uses a standard resolution of 129x129.
         * @return A completed grid using the Midpoint Displacement algorithm.
         */
        Grid* run();
        
        /**
         * Generates a grid using randomly generated shades for each of the 4
         * corners, using the given resolution.
         * @param width The width of the generated grid.
         * @param height The height of the generated grid.
         * @return A completed grid using the Midpoint Displacement algorithm.
         */
        Grid* run(int width, int height);
        
        /**
         * Generates a grid using given shades for each of the 4 corners. Uses
         * a standard resolution of 129x129.
         * @param corners An array containing shades for each of the corners.
         * @return A completed grid using the Midpoint Displacement algorithm.
         */
        Grid* run(float* corners);
        
        /**
         * Generates a grid using given shades for each of the 4 corners, using
         * the given resolution.
         * @param corners An array containing shades for each of the corners.
         * @param width The width of the generated grid.
         * @param height The height of the generated grid.
         * @return A completed grid using the Midpoint Displacement algorithm.
         */
        Grid* run(float* corners, int width, int height);
        
        /**
         * Generates a grid using an initialized Grid object.
         * @param grid A Grid object with the 4 corners initialized.
         * @return A completed grid using the Midpoint Displacement algorithm.
         * Shades are values between 0 and 1.
         */
        Grid* run(Grid* grid);
    private:
        /**
         * Fills the center coordinate with the calculated shade.
         * @param grid The grid to modify.
         * @param corners The corner set which will be averaged.
         */
        void fillCenterCoor(Grid* grid, CornerSet corners);
        
        /**
         * Calculates the smallest dimension needed to get make a valid grid
         * object that encapsulates the given dimension.
         * @param dimension The target dimension for the grid object.
         * @return A power of 2 plus 1, thus a valid grid dimension.
         */
        int calculateDimension(int dimension);
    };

}

#endif	/* MIDPOINTGENERATOR_H */

