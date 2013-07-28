#ifndef TESTSUITE_H
#define	TESTSUITE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Grid.h"

using namespace std;
using namespace MidpointDisplacement;

class TestSuite
{
public:
    virtual ~TestSuite() {}
    
    // Runs the test
    virtual void run() = 0;
    
protected:
    string getCoordinateString (int* coordinates)
    {
        stringstream oss;

        oss << " (" << coordinates[0] << ", " << coordinates[1] << ")";

        return oss.str();
    }

    string getCornerSetString (CornerSet corners)
    {
        stringstream oss;

        oss << getCoordinateString(corners.corner1Coor)
                << getCoordinateString(corners.corner2Coor)
                << getCoordinateString(corners.corner3Coor)
                << getCoordinateString(corners.corner4Coor);

        return oss.str();
    }

    bool coordinateEqual (int* coor1, int coor2X, int coor2Y)
    {
        return (coor1[0] == coor2X && coor1[1] == coor2Y);
    }
};

#endif
