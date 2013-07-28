#include "GridIteratorRectTest.h"
#include <iostream>

using namespace std;
using namespace MidpointDisplacement;

void GridIteratorRectTest::run()
{
    float corners[] = {1, 1, 1, 1};
    Grid* test = new Grid(corners, 9, 9);
    
    cout << "%TEST_STARTED% RectCreationBegin (GridIteratorRectTest)" << endl;
    rectCreationBegin(test);
    cout << "%TEST_FINISHED% time=0 RectCreationBegin (GridIteratorRectTest)" << endl;
    
    cout << "%TEST_STARTED% RectCreationEnd (GridIteratorRectTest)" << endl;
    rectCreationEnd(test);
    cout << "%TEST_FINISHED% time=0 RectCreationEnd (GridIteratorRectTest)" << endl;
    
    cout << "%TEST_STARTED% RectEquality (GridIteratorRectTest)" << endl;
    rectEquality(test);
    cout << "%TEST_FINISHED% time=0 RectEquality (GridIteratorRectTest)" << endl;
    
    cout << "%TEST_STARTED% RectInequality (GridIteratorRectTest)" << endl;
    rectInequality(test);
    cout << "%TEST_FINISHED% time=0 RectInequality (GridIteratorRectTest)" << endl;
    
    cout << "%TEST_STARTED% RectIncrement1 (GridIteratorRectTest)" << endl;
    rectIncrement1(test);
    cout << "%TEST_FINISHED% time=0 RectIncrement1 (GridIteratorRectTest)" << endl;
    
    cout << "%TEST_STARTED% RectIncrement2 (GridIteratorRectTest)" << endl;
    rectIncrement2(test);
    cout << "%TEST_FINISHED% time=0 RectIncrement2 (GridIteratorRectTest)" << endl;
    
    delete test;
}

void GridIteratorRectTest::rectCreationBegin (Grid* testGrid)
{
    cout << "GridIteratorRectTest RectCreationBegin" << endl;
    
    try
    {
        Grid::Level_Iterator iterator = testGrid->begin(0, false);
        
        if(!coordinateEqual(iterator->corner1Coor, 0, 0))
        {
            cout << "%TEST_FAILED% time=0 testname=RectCreationEnd (GridIteratorRectTest) "
                    << "message=Incorrect coordinates for corner 1."
                    << getCoordinateString(iterator->corner1Coor)<< endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner2Coor, 8, 0))
        {
            cout << "%TEST_FAILED% time=0 testname=RectCreationEnd (GridIteratorRectTest) "
                    << "message=Incorrect coordinates for corner 2."
                    << getCoordinateString(iterator->corner2Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner3Coor, 8, 8))
        {
            cout << "%TEST_FAILED% time=0 testname=RectCreationEnd (GridIteratorRectTest) "
                    << "message=Incorrect coordinates for corner 3. "
                    << getCoordinateString(iterator->corner3Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner4Coor, 0, 8))
        {
            cout << "%TEST_FAILED% time=0 testname=RectCreationEnd (GridIteratorRectTest) "
                    << "message=Incorrect coordinates for corner 4. "
                    << getCoordinateString(iterator->corner4Coor) << endl;
            return;
        }
        
        if(iterator->corner1 != 1 || iterator->corner2 != 1 || iterator->corner3 != 1 || iterator->corner4 != 1)
        {
            cout << "%TEST_FAILED% time=0 testname=RectCreationEnd (GridIteratorRectTest) "
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
        cout << "%TEST_FAILED% time=0 testname=RectCreationBegin (GridIteratorRectTest) "
                << "message=Failed to create the test object. "
                << ex.what() << endl;
    }
}

void GridIteratorRectTest::rectCreationEnd (Grid* testGrid)
{
    cout << "GridIteratorRectTest RectCreationEnd" << endl;
    
    try
    {
        Grid::Level_Iterator iterator = testGrid->end(0, false);
        
        if(!coordinateEqual(iterator->corner1Coor, -1, -1))
        {
            cout << "%TEST_FAILED% time=0 testname=RectCreationEnd (GridIteratorRectTest) "
                    << "message=Incorrect coordinates for corner 1. "
                    << getCoordinateString(iterator->corner1Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner2Coor, -1, -1))
        {
            cout << "%TEST_FAILED% time=0 testname=RectCreationEnd (GridIteratorRectTest) "
                    << "message=Incorrect coordinates for corner 2. "
                    << getCoordinateString(iterator->corner2Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner3Coor, -1, -1))
        {
            cout << "%TEST_FAILED% time=0 testname=RectCreationEnd (GridIteratorRectTest) "
                    << "message=Incorrect coordinates for corner 3. "
                    << getCoordinateString(iterator->corner3Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner4Coor, -1, -1))
        {
            cout << "%TEST_FAILED% time=0 testname=RectCreationEnd (GridIteratorRectTest) "
                    << "message=Incorrect coordinates for corner 4. "
                    << getCoordinateString(iterator->corner4Coor) << endl;
            return;
        }
        
        if(iterator->corner1 != -1 || iterator->corner2 != -1 || iterator->corner3 != -1 || iterator->corner4 != -1)
        {
            cout << "%TEST_FAILED% time=0 testname=RectCreationEnd (GridIteratorRectTest) "
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
        cout << "%TEST_FAILED% time=0 testname=RectCreationEnd (GridIteratorRectTest) "
                << "message=Failed to create the test object. "
                << ex.what() << endl;
    }
}

void GridIteratorRectTest::rectEquality (Grid* testGrid)
{
    cout << "GridIteratorRectTest RectEquality" << endl;
    
    Grid::Level_Iterator iterator = testGrid->begin(0, false);
    
    Grid::Level_Iterator iterator2 = testGrid->begin(0, false);
    
    // Check the equality of the iterator with itself.
    if(!(iterator == iterator))
    {
        cout << "%TEST_FAILED% time=0 testname=RectEquality (GridIteratorRectTest) "
                << "message=Failed to validate self equality.  " << endl;
        return;
    }
    
    // Check the equality of the iterators generated by the same object and function.
    if(!(iterator == iterator2))
    {
        cout << "%TEST_FAILED% time=0 testname=RectEquality (GridIteratorRectTest) "
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
        cout << "%TEST_FAILED% time=0 testname=RectEquality (GridIteratorRectTest) "
                << "message=Failed to validate equality of corner set."
                << endl;
        return;
    }
}

void GridIteratorRectTest::rectInequality (Grid* testGrid)
{
    cout << "GridIteratorRectTest RectInequality" << endl;
    
    Grid::Level_Iterator iterator = testGrid->begin(0, false);
    
    Grid::Level_Iterator iterator2 = testGrid->begin(0, false);
    
    // Check to make sure the iterators are equal through inequality
    if(iterator != iterator)
    {
        cout << "%TEST_FAILED% time=0 testname=RectInequality (GridIteratorRectTest) "
                << "message=Failed to validate self equality through inequality. "
                << endl;
        return;
    }
    
    // Check to the equality of the iterators generated by the same object and function.
    if(iterator != iterator2)
    {
        cout << "%TEST_FAILED% time=0 testname=RectInequality (GridIteratorRectTest) "
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
        cout << "%TEST_FAILED% time=0 testname=RectInequality (GridIteratorRectTest) "
                << "message=Failed to validate equality of a corner set through "
                << "inequality. " << endl;
        return;
    }
}

void GridIteratorRectTest::rectIncrement1 (Grid* testGrid)
{
    cout << "GridIteratorRectTest RectIncrement1" << endl;
    
    Grid::Level_Iterator iterator = testGrid->begin(1, false);
    
    // Check the first coordinates
    if(!coordinateEqual(iterator->corner1Coor, 0, 0) ||
            !coordinateEqual(iterator->corner2Coor, 4, 0) ||
            !coordinateEqual(iterator->corner3Coor, 4, 4) ||
            !coordinateEqual(iterator->corner4Coor, 0, 4))
    {
        cout << "%TEST_FAILED% time=0 testname=RectIncrement1 (GridIteratorRectTest) "
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
        cout << "%TEST_FAILED% time=0 testname=RectIncrement1 (GridIteratorRectTest) "
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
        cout << "%TEST_FAILED% time=0 testname=RectIncrement1 (GridIteratorRectTest) "
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
        cout << "%TEST_FAILED% time=0 testname=RectIncrement1 (GridIteratorRectTest) "
                << "message=Incorrect coordinates for the fourth iteration."
                << getCornerSetString(*iterator) << endl;
        return;
    }
    
    // Check the fifth iteration coordinates
    iterator++;
    if(!coordinateEqual(iterator->corner1Coor, -1, -1) ||
            !coordinateEqual(iterator->corner2Coor, -1, -1) ||
            !coordinateEqual(iterator->corner3Coor, -1, -1) ||
            !coordinateEqual(iterator->corner4Coor, -1, -1))
    {
        cout << "%TEST_FAILED% time=0 testname=RectIncrement1 (GridIteratorRectTest) "
                << "message=Incorrect coordinates for the final iteration."
                << getCornerSetString(*iterator) << endl;
        return;
    }
    
    if(iterator != testGrid->end(0, false))
    {
        cout << "%TEST_FAILED% time=0 testname=RectIncrement1 (GridIteratorRectTest) "
                << "message=Final iteration not equal to end iterator."
                << getCornerSetString(*iterator) << endl;
        return;
    }
}

void GridIteratorRectTest::rectIncrement2 (Grid* testGrid)
{
    cout << "GridIteratorRectTest RectIncrement2" << endl;
    
    int count = 0;
    
    // Attempt to set up a standard iteration
    for(Grid::Level_Iterator i = testGrid->begin(1, false); i != testGrid->end(1, false); i++)
    {   
        if(count >= 4)
        {
            cout << "%TEST_FAILED% time=0 testname=RectIncrement2 (GridIteratorRectTest) "
                    << "message=Exceeded final iterator. At count " << count << "."
                    << getCornerSetString(*i) << endl;
            return;
        }
        count++;
    }
}