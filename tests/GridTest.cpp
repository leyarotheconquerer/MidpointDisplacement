#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "Grid.h"

/*
 * Simple C++ Test Suite
 */

using namespace std;
using namespace MidpointDisplacement;

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

void gridCreation1()
{
    cout << "GridTest GridCreation1" << endl;
    
    Grid* test = NULL;
    
    float corners[] = {0, .333, .666, 1};
    try
    {
        test = new Grid(corners);
    }
    catch (exception ex)
    {
        cout << "%TEST_FAILED% time=0 testname=GridCreation1 (GridTest) "
                << "message=Failed to create the test object. "
                << ex.what() << endl;
        return;
    }
    
    if(!test)
    {
        cout << "%TEST_FAILED% time=0 testname=GridCreation1 (GridTest) "
                << "message=Failed to create the test object." << endl;
        return;
    }
    
    if(test->getWidth() != 100 || test->getHeight() != 100)
    {
        cout << "%TEST_FAILED% time=0 testname=GridCreation1 (GridTest) "
                << "message=Incorrect Grid dimensions. " 
                << "(" << test->getWidth() << ", " << test->getHeight() << ")"
                << endl;
        return;
    }
    
    try
    {
        delete test;
    }
    catch (exception ex)
    {
        cout << "%TEST_FAILED% time=0 testname=GridCreation1 (GridTest) "
                << "message=Failed to delete the test object. "
                << ex.what() << endl;
        return;
    }
}

void gridCreation2()
{
    cout << "GridTest GridCreation2" << endl;
    
    Grid* test = NULL;
    
    float corners[] = {0, .333, .666, 1};
    try
    {
        test = new Grid(corners, 50, 50);
    }
    catch (exception ex)
    {
        cout << "%TEST_FAILED% time=0 testname=GridCreation2 (GridTest) "
                << "message=Failed to create the test object. "
                << ex.what() << endl;
        return;
    }
    
    if(!test)
    {
        cout << "%TEST_FAILED% time=0 testname=GridCreation2 (GridTest) "
                << "message=Failed to create the test object." << endl;
        return;
    }
    
    if(test->getWidth() != 50 || test->getHeight() != 50)
    {
        cout << "%TEST_FAILED% time=0 testname=GridCreation2 (GridTest) "
                << "message=Incorrect Grid dimensions. "
                << "(" << test->getWidth() << ", " << test->getHeight() << ")"
                << endl;
        return;
    }
    
    try
    {
        delete test;
    }
    catch (exception ex)
    {
        cout << "%TEST_FAILED% time=0 testname=GridCreation2 (GridTest) "
                << "message=Failed to delete the test object. "
                << ex.what() << endl;
        return;
    }
}

void gridInitialization()
{
    cout << "GridTest GridInitialization" << endl;
    
    float corner[] = {-1, -1, -1, -1};
    Grid* test = new Grid(corner, 10, 10);
    
    for(int i = 0; i < test->getWidth(); i++)
    {
        for(int j = 0; j < test->getHeight(); j++)
        {
            if(test->getShade(i, j) != -1)
            {
                cout << "%TEST_FAILED% time=0 testname=GridInitialization "
                        << "(GridTest) message=Uninitialized value. "
                        << "(" << i << ", " << j << ") = " << test->getShade(i,j)
                        << endl;
                return;
            }
        }
    }
    
    delete test;
}

void gridFilling()
{
    cout << "GridTest GridFilling" << endl;
    
    float corner[] = {1,1,1,1};
    Grid* test = new Grid(corner, 10, 10);
    
    for(int i = 0; i < test->getWidth(); i++)
    {
        for(int j = 0; j < test->getHeight(); j++)
        {
            test->setShade(1, i, j);
        }
    }
    
    for(int i = 0; i < test->getWidth(); i++)
    {
        for(int j = 0; j < test->getHeight(); j++)
        {
            if(test->getShade(i, j) != 1)
            {
                cout << "%TEST_FAILED% time=0 testname=GridFilling "
                        << "(GridTest) message=Incorrect value. "
                        << "(" << i << ", " << j << ") = " << test->getShade(i,j)
                        << endl;
            }
        }
    }
}

void gridTest ()
{
    std::cout << "%SUITE_STARTING% GridTest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;
    
    cout << "%TEST_STARTED% GridCreation1 (GridTest)" << endl;
    gridCreation1();
    cout << "%TEST_FINISHED% time=0 GridCreation1 (GridTest)" << endl;
    
    cout << "%TEST_STARTED% GridCreation2 (GridTest)" << endl;
    gridCreation2();
    cout << "%TEST_FINISHED% time=0 GridCreation2 (GridTest)" << endl;
    
    cout << "%TEST_STARTED% GridInitialization (GridTest)" << endl;
    gridInitialization();
    cout << "%TEST_FINISHED% time=0 GridInitialization (GridTest)" << endl;
    
    cout << "%TEST_STARTED% GridFilling (GridTest)" << endl;
    gridFilling();
    cout << "%TEST_FINISHED% time=0 GridFilling (GridTest)" << endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;
}

void iteratorCreationBegin (Grid* testGrid)
{
    cout << "GridIteratorTest IteratorCreationBegin" << endl;
    
    try
    {
        Grid::Level_Iterator iterator = testGrid->begin(0, false);
        
        if(!coordinateEqual(iterator->corner1Coor, 0, 0))
        {
            cout << "%TEST_FAILED% time=0 testName=IteratorCreationEnd (GridIteratorTest) "
                    << "message=Incorrect coordinates for corner 1."
                    << getCoordinateString(iterator->corner1Coor)<< endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner2Coor, 8, 0))
        {
            cout << "%TEST_FAILED% time=0 testName=IteratorCreationEnd (GridIteratorTest) "
                    << "message=Incorrect coordinates for corner 2."
                    << getCoordinateString(iterator->corner2Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner3Coor, 8, 8))
        {
            cout << "%TEST_FAILED% time=0 testName=IteratorCreationEnd (GridIteratorTest) "
                    << "message=Incorrect coordinates for corner 3. "
                    << getCoordinateString(iterator->corner3Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner4Coor, 0, 8))
        {
            cout << "%TEST_FAILED% time=0 testName=IteratorCreationEnd (GridIteratorTest) "
                    << "message=Incorrect coordinates for corner 4. "
                    << getCoordinateString(iterator->corner4Coor) << endl;
            return;
        }
        
        if(iterator->corner1 != 1 || iterator->corner2 != 1 || iterator->corner3 != 1 || iterator->corner4)
        {
            cout << "%TEST_FAILED% time=0 testName=IteratorCreationEnd (GridIteratorTest) "
                    << "message=Incorrect corner shade. "
                    << "(" << iterator->corner1 << ", "
                    << iterator->corner2 << ", "
                    << iterator->corner3 << ", "
                    << iterator->corner4 << ")" << endl;
            return;
        }
    }
    catch (exception ex)
    {
        cout << "%TEST_FAILED% time=0 testName=IteratorCreationBegin (GridIteratorTest) "
                << "message=Failed to create the test object. "
                << ex.what() << endl;
    }
}

void iteratorCreationEnd (Grid* testGrid)
{
    cout << "GridIteratorTest IteratorCreationEnd" << endl;
    
    try
    {
        Grid::Level_Iterator iterator = testGrid->end(0, false);
        
        if(!coordinateEqual(iterator->corner1Coor, -1, -1))
        {
            cout << "%TEST_FAILED% time=0 testName=IteratorCreationEnd (GridIteratorTest) "
                    << "message=Incorrect coordinates for corner 1. "
                    << getCoordinateString(iterator->corner1Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner2Coor, -1, -1))
        {
            cout << "%TEST_FAILED% time=0 testName=IteratorCreationEnd (GridIteratorTest) "
                    << "message=Incorrect coordinates for corner 2. "
                    << getCoordinateString(iterator->corner2Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner3Coor, -1, -1))
        {
            cout << "%TEST_FAILED% time=0 testName=IteratorCreationEnd (GridIteratorTest) "
                    << "message=Incorrect coordinates for corner 3. "
                    << getCoordinateString(iterator->corner3Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner4Coor, -1, -1))
        {
            cout << "%TEST_FAILED% time=0 testName=IteratorCreationEnd (GridIteratorTest) "
                    << "message=Incorrect coordinates for corner 4. "
                    << getCoordinateString(iterator->corner4Coor) << endl;
            return;
        }
        
        if(iterator->corner1 != 1 || iterator->corner2 != 1 || iterator->corner3 != 1 || iterator->corner4)
        {
            cout << "%TEST_FAILED% time=0 testName=IteratorCreationEnd (GridIteratorTest) "
                    << "message=Incorrect corner shade. "
                    << "(" << iterator->corner1 << ", "
                    << iterator->corner2 << ", "
                    << iterator->corner3 << ", "
                    << iterator->corner4 << ")" << endl;
            return;
        }
    }
    catch(exception ex)
    {
        cout << "%TEST_FAILED% time=0 testName=IteratorCreationEnd (GridIteratorTest) "
                << "message=Failed to create the test object. "
                << ex.what() << endl;
    }
}

void iteratorEquality (Grid* testGrid)
{
    cout << "GridIteratorTest IteratorEquality" << endl;
    
    Grid::Level_Iterator iterator = testGrid->begin(0, false);
    
    Grid::Level_Iterator iterator2 = testGrid->begin(0, false);
    
    // Check the equality of the iterator with itself.
    if(!(iterator == iterator))
    {
        cout << "%TEST_FAILED% time=0 testName=IteratorEquality (GridIteratorTest) "
                << "message=Failed to validate self equality.  " << endl;
        return;
    }
    
    // Check the equality of the iterators generated by the same object and function.
    if(!(iterator == iterator2))
    {
        cout << "%TEST_FAILED% time=0 testName=IteratorEquality (GridIteratorTest) "
                << "message=Failed to validate equality of similar object. "
                << endl;
        return;
    }
    
    // Check the equality of a corner set and an iterator.
    CornerSet corners;
    corners.corner1Coor[0] = 0;
    corners.corner1Coor[1] = 0;
    corners.corner2Coor[0] = 8;
    corners.corner2Coor[1] = 0;
    corners.corner3Coor[0] = 8;
    corners.corner3Coor[1] = 8;
    corners.corner4Coor[0] = 0;
    corners.corner4Coor[1] = 8;
    
    if(!(iterator == corners))
    {
        cout << "%TEST_FAILED% time=0 testName=IteratorEquality (GridIteratorTest) "
                << "message=Failed to validate equality of corner set."
                << endl;
        return;
    }
}

void iteratorInequality (Grid* testGrid)
{
    cout << "GridIteratorTest IteratorInequality" << endl;
    
    Grid::Level_Iterator iterator = testGrid->begin(0, false);
    
    Grid::Level_Iterator iterator2 = testGrid->begin(0, false);
    
    // Check to make sure the iterators are equal through inequality
    if(iterator != iterator)
    {
        cout << "%TEST_FAILED% time=0 testName=IteratorInequality (GridIteratorTest) "
                << "message=Failed to validate self equality through inequality. "
                << endl;
        return;
    }
    
    // Check to the equality of the iterators generated by the same object and function.
    if(iterator != iterator2)
    {
        cout << "%TEST_FAILED% time=0 testName=IteratorInequality (GridIteratorTest) "
                << "message=Failed to validate equality of similar objects through"
                << "inequality. " << endl;
        return;
    }
    
    // Check the equality of a corner set and an iterator
    CornerSet corners;
    corners.corner1Coor[0] = 0;
    corners.corner1Coor[1] = 0;
    corners.corner2Coor[0] = 8;
    corners.corner2Coor[1] = 0;
    corners.corner3Coor[0] = 8;
    corners.corner3Coor[1] = 8;
    corners.corner4Coor[0] = 0;
    corners.corner4Coor[1] = 8;
    
    if(iterator != corners)
    {
        cout << "%TEST_FAILED% time=0 testName=IteratorInequality (GridIteratorTest) "
                << "message=Failed to validate equality of a corner set through "
                << "inequality. " << endl;
        return;
    }
}

void iteratorIncrement1 (Grid* testGrid)
{
    cout << "GridIteratorTest IteratorIncrement1" << endl;
    
    Grid::Level_Iterator iterator = testGrid->begin(1, false);
    
    // Check the first coordinates
    if(!coordinateEqual(iterator->corner1Coor, 0, 0) ||
            !coordinateEqual(iterator->corner2Coor, 4, 0) ||
            !coordinateEqual(iterator->corner3Coor, 4, 4) ||
            !coordinateEqual(iterator->corner4Coor, 0, 4))
    {
        cout << "%TEST_FAILED% time=0 testName=IteratorIncrement1 (GridIteratorTest) "
                << "message=Incorrect coordinates for the first iteration."
                << getCoordinateString(iterator->corner1Coor)
                << getCoordinateString(iterator->corner2Coor)
                << getCoordinateString(iterator->corner3Coor)
                << getCoordinateString(iterator->corner4Coor) << endl;
        return;
    }
    
    // Check the second iteration coordinates
    iterator++;
    if(!coordinateEqual(iterator->corner1Coor, 4, 0) ||
            !coordinateEqual(iterator->corner2Coor, 8, 0) ||
            !coordinateEqual(iterator->corner3Coor, 8, 4) ||
            !coordinateEqual(iterator->corner4Coor, 4, 4))
    {
        cout << "%TEST_FAILED% time=0 testName=IteratorIncrement1 (GridIteratorTest) "
                << "message=Incorrect coordinates for the second iteration."
                << getCornerSetString(*iterator) << endl;
        return;
    }
    
    // Check the third iteration coordinates
    iterator++;
    if(!coordinateEqual(iterator->corner1Coor, 4, 4) ||
            !coordinateEqual(iterator->corner2Coor, 8, 4) ||
            !coordinateEqual(iterator->corner3Coor, 8, 8) ||
            !coordinateEqual(iterator->corner4Coor, 4, 8))
    {
        cout << "%TEST_FAILED% time=0 testName=IteratorIncrement1 (GridIteratorTest) "
                << "message=Incorrect coordinates for the third iteration."
                << getCornerSetString(*iterator) << endl;
        return;
    }
    
    // Check the fourth iteration coordinates
    iterator++;
    if(!coordinateEqual(iterator->corner1Coor, 0 ,4) ||
            !coordinateEqual(iterator->corner2Coor, 4, 4) ||
            !coordinateEqual(iterator->corner3Coor, 4, 8) ||
            !coordinateEqual(iterator->corner4Coor, 0, 8))
    {
        cout << "%TEST_FAILED% time=0 testName=IteratorIncrement1 (GridIteratorTest) "
                << "message=Incorrect coordinates for the fourth iteration."
                << getCornerSetString(*iterator) << endl;
        return;
    }
}

void gridIteratorTest ()
{
    cout << "%SUITE_STARTING% GridIteratorTest" << endl;
    cout << "%SUITE_STARTED%" << endl;
    
    float corners[] = {1, 1, 1, 1};
    Grid* test = new Grid(corners, 9, 9);
    
    cout << "%TEST_STARTED% IteratorCreationBegin (GridIteratorTest)" << endl;
    iteratorCreationBegin(test);
    cout << "%TEST_FINISHED% time=0 IteratorCreationBegin (GridIteratorTest)" << endl;
    
    cout << "%TEST_STARTED% IteratorCreationEnd (GridIteratorTest)" << endl;
    iteratorCreationEnd(test);
    cout << "%TEST_FINISHED% time=0 IteratorCreationEnd (GridIteratorTest)" << endl;
    
    cout << "%TEST_STARTED% IteratorEquality (GridIteratorTest)" << endl;
    iteratorEquality(test);
    cout << "%TEST_FINISHED% time=0 IteratorEquality (GridIteratorTest)" << endl;
    
    cout << "%TEST_STARTED% IteratorInequality (GridIteratorTest)" << endl;
    iteratorInequality(test);
    cout << "%TEST_FINISHED% time=0 IteratorInequality (GridIteratorTest)" << endl;
    
    cout << "%TEST_STARTED% IteratorIncrement1 (GridIteratorTest)" << endl;
    iteratorIncrement1(test);
    cout << "%TEST_FINISHED% time=0 IteratorIncrement1 (GridIteratorTest)" << endl;
    
    delete test;
    
    cout << "%SUITE_FINISHED% time=0" << endl;
}

int main(int argc, char** argv)
{
    // Start the grid tests
    gridTest();
    
    // Start the grid iterator tests
    gridIteratorTest();
    
    return (EXIT_SUCCESS);
}

