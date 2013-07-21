#ifndef MIDPOINTGENERATOR_H
#define	MIDPOINTGENERATOR_H

#include "Grid.h"


namespace MidpointDisplacement
{

    class MidpointGenerator {
    public:
        MidpointGenerator();
        MidpointGenerator(const MidpointGenerator& orig);
        virtual ~MidpointGenerator();
        
        /**
         * Generates a grid using randomly generated shades for each of the 4
         * corners.
         * @return A completed grid using the Midpoint Displacement algorithm.
         */
        Grid* run();
        
        /**
         * Generates a grid using given shades for each of the 4 corners.
         * @param corners An array containing shades for each of the corners.
         * @return A completed grid using the Midpoint Displacement algorithm.
         */
        Grid* run(float* corners);
        
        /**
         * Generates a grid using an initialized Grid object.
         * @param grid A Grid object with the 4 corners initialized.
         * @return A completed grid using the Midpoint Displacement algorithm.
         * Shades are values between 0 and 1.
         */
        Grid* run(Grid* grid);
    private:

    };

}

#endif	/* MIDPOINTGENERATOR_H */

