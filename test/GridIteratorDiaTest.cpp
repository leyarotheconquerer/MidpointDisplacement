/* 
 * File:   GridIteratorDiaTest.cpp
 * Author: Hazen
 * 
 * Created on July 27, 2013, 6:00 PM
 */

#include "GridIteratorDiaTest.h"
#include "TestSuite.h"

using namespace std;
using namespace MidpointDisplacement;

void GridIteratorDiaTest::run()
{
    float corners[] = {1, 1, 1, 1};
    Grid* test = new Grid(corners, 9, 9);
    
    cout << "%TEST_STARTED% DiamondCreationBegin (GridIteratorDiaTest)" << endl;
    diaCreationBegin(test);
    cout << "%TEST_FINISHED% time=0 DiamondCreationBegin (GridIteratorDiaTest)" << endl;
    
    cout << "%TEST_STARTED% DiamondCreationEnd (GridIteratorDiaTest)" << endl;
    diaCreationEnd(test);
    cout << "%TEST_FINISHED% time=0 DiamondCreationEnd (GridIteratorDiaTest)" << endl;
    
    cout << "%TEST_STARTED% DiamondEquality (GridIteratorDiaTest)" << endl;
    diaEquality(test);
    cout << "%TEST_FINISHED% time=0 DiamondEquality (GridIteratorDiaTest)" << endl;
    
    cout << "%TEST_STARTED% DiamondInequality (GridIteratorDiaTest)" << endl;
    diaInequality(test);
    cout << "%TEST_FINISHED% time=0 DiamondInequality (GridIteratorDiaTest)" << endl;
    
    cout << "%TEST_STARTED% DiamondIncrement1 (GridIteratorDiaTest)" << endl;
    diaIncrement1(test);
    cout << "%TEST_FINISHED% time=0 DiamondIncrement1 (GridIteratorDiaTest)" << endl;
    
    cout << "%TEST_STARTED% DiamondIncrement2 (GridIteratorDiaTest)" << endl;
    diaIncrement2(test);
    cout << "%TEST_FINISHED% time=0 DiamondIncrement2 (GridIteratorDiaTest)" << endl;
    
    cout << "%TEST_STARTED% DiaDetail (GridIteratorDiaTest)" << endl;
    diaDetail(test);
    cout << "%TEST_FINISHED% time=0 DiaDetail (GridIteratorDiaTest)" << endl;
    
    delete test;
}

void GridIteratorDiaTest::diaCreationBegin (Grid* testGrid)
{
    cout << "GridIteratorDiaTest DiaCreationBegin" << endl;
    
    try
    {
        Grid::Level_Iterator iterator = testGrid->begin(0, true);
        
        if(!coordinateEqual(iterator->corner1Coor, 4, -4))
        {
            cout << "%TEST_FAILED% time=0 testname=DiaCreationEnd (GridIteratorDiaTest) "
                    << "message=Incorrect coordinates for corner 1."
                    << getCoordinateString(iterator->corner1Coor)<< endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner2Coor, 8, 0))
        {
            cout << "%TEST_FAILED% time=0 testname=DiaCreationEnd (GridIteratorDiaTest) "
                    << "message=Incorrect coordinates for corner 2."
                    << getCoordinateString(iterator->corner2Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner3Coor, 4, 4))
        {
            cout << "%TEST_FAILED% time=0 testname=DiaCreationEnd (GridIteratorDiaTest) "
                    << "message=Incorrect coordinates for corner 3. "
                    << getCoordinateString(iterator->corner3Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner4Coor, 0, 0))
        {
            cout << "%TEST_FAILED% time=0 testname=DiaCreationEnd (GridIteratorDiaTest) "
                    << "message=Incorrect coordinates for corner 4. "
                    << getCoordinateString(iterator->corner4Coor) << endl;
            return;
        }
        
        if(iterator->corner1 != -1 || iterator->corner2 != 1 || iterator->corner3 != -1 || iterator->corner4 != 1)
        {
            cout << "%TEST_FAILED% time=0 testname=DiaCreationEnd (GridIteratorDiaTest) "
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
        cout << "%TEST_FAILED% time=0 testname=DiaCreationBegin (GridIteratorDiaTest) "
                << "message=Failed to create the test object. "
                << ex.what() << endl;
    }
}

void GridIteratorDiaTest::diaCreationEnd (Grid* testGrid)
{
    cout << "GridIteratorDiaTest DiaCreationEnd" << endl;
    
    try
    {
        Grid::Level_Iterator iterator = testGrid->end(0, true);
        
        if(!coordinateEqual(iterator->corner1Coor, -1, -1))
        {
            cout << "%TEST_FAILED% time=0 testname=DiaCreationEnd (GridIteratorDiaTest) "
                    << "message=Incorrect coordinates for corner 1. "
                    << getCoordinateString(iterator->corner1Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner2Coor, -1, -1))
        {
            cout << "%TEST_FAILED% time=0 testname=DiaCreationEnd (GridIteratorDiaTest) "
                    << "message=Incorrect coordinates for corner 2. "
                    << getCoordinateString(iterator->corner2Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner3Coor, -1, -1))
        {
            cout << "%TEST_FAILED% time=0 testname=DiaCreationEnd (GridIteratorDiaTest) "
                    << "message=Incorrect coordinates for corner 3. "
                    << getCoordinateString(iterator->corner3Coor) << endl;
            return;
        }
        
        if(!coordinateEqual(iterator->corner4Coor, -1, -1))
        {
            cout << "%TEST_FAILED% time=0 testname=DiaCreationEnd (GridIteratorDiaTest) "
                    << "message=Incorrect coordinates for corner 4. "
                    << getCoordinateString(iterator->corner4Coor) << endl;
            return;
        }
        
        if(iterator->corner1 != -1 || iterator->corner2 != -1 || iterator->corner3 != -1 || iterator->corner4 != -1)
        {
            cout << "%TEST_FAILED% time=0 testname=DiaCreationEnd (GridIteratorDiaTest) "
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
        cout << "%TEST_FAILED% time=0 testname=DiaCreationEnd (GridIteratorDiaTest) "
                << "message=Failed to create the test object. "
                << ex.what() << endl;
    }
}

void GridIteratorDiaTest::diaEquality (Grid* testGrid)
{
    cout << "GridIteratorDiaTest DiaEquality" << endl;
    
    Grid::Level_Iterator iterator = testGrid->begin(0, true);
    
    Grid::Level_Iterator iterator2 = testGrid->begin(0, true);
    
    // Check the equality of the iterator with itself.
    if(!(iterator == iterator))
    {
        cout << "%TEST_FAILED% time=0 testname=DiaEquality (GridIteratorDiaTest) "
                << "message=Failed to validate self equality.  " << endl;
        return;
    }
    
    // Check the equality of the iterators generated by the same object and function.
    if(!(iterator == iterator2))
    {
        cout << "%TEST_FAILED% time=0 testname=DiaEquality (GridIteratorDiaTest) "
                << "message=Failed to validate equality of similar object. "
                << endl;
        return;
    }
    
    // Check the equality of a corner set and an iterator.
    CornerSet corners;
    corners.corner1Coor[0] = 4;
    corners.corner1Coor[1] = -4;
    corners.corner2Coor[0] = 8;
    corners.corner2Coor[1] = 0;
    corners.corner3Coor[0] = 4;
    corners.corner3Coor[1] = 4;
    corners.corner4Coor[0] = 0;
    corners.corner4Coor[1] = 0;
    
    if(!(iterator == corners))
    {
        cout << "%TEST_FAILED% time=0 testname=DiaEquality (GridIteratorDiaTest) "
                << "message=Failed to validate equality of corner set."
                << endl;
        return;
    }
}

void GridIteratorDiaTest::diaInequality (Grid* testGrid)
{
    cout << "GridIteratorDiaTest DiaInequality" << endl;
    
    Grid::Level_Iterator iterator = testGrid->begin(0, true);
    
    Grid::Level_Iterator iterator2 = testGrid->begin(0, true);
    
    // Check to make sure the iterators are equal through inequality
    if(iterator != iterator)
    {
        cout << "%TEST_FAILED% time=0 testname=DiaInequality (GridIteratorDiaTest) "
                << "message=Failed to validate self equality through inequality. "
                << endl;
        return;
    }
    
    // Check to the equality of the iterators generated by the same object and function.
    if(iterator != iterator2)
    {
        cout << "%TEST_FAILED% time=0 testname=DiaInequality (GridIteratorDiaTest) "
                << "message=Failed to validate equality of similar objects through"
                << "inequality. " << endl;
        return;
    }
    
    // Check the equality of a corner set and an iterator
    CornerSet corners;
    corners.corner1Coor[0] = 4;
    corners.corner1Coor[1] = -4;
    corners.corner2Coor[0] = 8;
    corners.corner2Coor[1] = 0;
    corners.corner3Coor[0] = 4;
    corners.corner3Coor[1] = 4;
    corners.corner4Coor[0] = 0;
    corners.corner4Coor[1] = 0;
    
    if(iterator != corners)
    {
        cout << "%TEST_FAILED% time=0 testname=DiaInequality (GridIteratorDiaTest) "
                << "message=Failed to validate equality of a corner set through "
                << "inequality. " << endl;
        return;
    }
}

void GridIteratorDiaTest::diaIncrement1 (Grid* testGrid)
{
    cout << "GridIteratorDiaTest DiaIncrement1" << endl;
    
    Grid::Level_Iterator iterator = testGrid->begin(0, true);
    
    // Check the first coordinates
    if(!coordinateEqual(iterator->corner1Coor, 4, -4) ||
            !coordinateEqual(iterator->corner2Coor, 8, 0) ||
            !coordinateEqual(iterator->corner3Coor, 4, 4) ||
            !coordinateEqual(iterator->corner4Coor, 0, 0))
    {
        cout << "%TEST_FAILED% time=0 testname=DiaIncrement1 (GridIteratorDiaTest) "
                << "message=Incorrect coordinates for the first iteration."
                << getCoordinateString(iterator->corner1Coor)
                << getCoordinateString(iterator->corner2Coor)
                << getCoordinateString(iterator->corner3Coor)
                << getCoordinateString(iterator->corner4Coor) << endl;
        return;
    }
    
    // Check the second iteration coordinates
    iterator++;
    if(!coordinateEqual(iterator->corner1Coor, 8, 0) ||
            !coordinateEqual(iterator->corner2Coor, 12, 4) ||
            !coordinateEqual(iterator->corner3Coor, 8, 8) ||
            !coordinateEqual(iterator->corner4Coor, 4, 4))
    {
        cout << "%TEST_FAILED% time=0 testname=DiaIncrement1 (GridIteratorDiaTest) "
                << "message=Incorrect coordinates for the second iteration."
                << getCornerSetString(*iterator) << endl;
        return;
    }
    
    // Check the third iteration coordinates
    iterator++;
    if(!coordinateEqual(iterator->corner1Coor, 0, 0) ||
            !coordinateEqual(iterator->corner2Coor, 4, 4) ||
            !coordinateEqual(iterator->corner3Coor, 0, 8) ||
            !coordinateEqual(iterator->corner4Coor, -4, 4))
    {
        cout << "%TEST_FAILED% time=0 testname=DiaIncrement1 (GridIteratorDiaTest) "
                << "message=Incorrect coordinates for the third iteration."
                << getCornerSetString(*iterator) << endl;
        return;
    }
    
    // Check the fourth iteration coordinates
    iterator++;
    if(!coordinateEqual(iterator->corner1Coor, 4, 4) ||
            !coordinateEqual(iterator->corner2Coor, 8, 8) ||
            !coordinateEqual(iterator->corner3Coor, 4, 12) ||
            !coordinateEqual(iterator->corner4Coor, 0, 8))
    {
        cout << "%TEST_FAILED% time=0 testname=DiaIncrement1 (GridIteratorDiaTest) "
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
        cout << "%TEST_FAILED% time=0 testname=DiaIncrement1 (GridIteratorDiaTest) "
                << "message=Incorrect coordinates for the final iteration."
                << getCornerSetString(*iterator) << endl;
        return;
    }
    
    if(iterator != testGrid->end(0, false))
    {
        cout << "%TEST_FAILED% time=0 testname=DiaIncrement1 (DiaIteratorRectTest) "
                << "message=Final iteration not equal to end iterator."
                << getCornerSetString(*iterator) << endl;
        return;
    }
}

void GridIteratorDiaTest::diaIncrement2 (Grid* testGrid)
{
    cout << "GridIteratorDiaTest DiaIncrement2" << endl;
    
    int count = 0;
    
    // Attempt to set up a standard iteration
    for(Grid::Level_Iterator i = testGrid->begin(1, false); i != testGrid->end(0, true); i++)
    {   
        if(count >= 4)
        {
            cout << "%TEST_FAILED% time=0 testname=DiaIncrement2 (GridIteratorDiaTest) "
                    << "message=Exceeded final iterator. At count " << count << "."
                    << getCornerSetString(*i) << endl;
            return;
        }
        count++;
    }
}

void GridIteratorDiaTest::diaDetail(Grid* testGrid)
{
    cout << "GridIteratorDiaTest DiaDetail" << endl;
    
    int maxLevel = round(sqrt(testGrid->getMaxDimension()));
    
    // Level iteration
    for(int i = 0; i <= maxLevel; i++)
    {
        // Rectangle iteration phase
        int count = 0;
        
        for(Grid::Level_Iterator j= testGrid->begin(i, false); j != testGrid->end(i, false); j++)
        {
            if(count >= pow(2, 2*i))
            {
                cout << "%TEST_FAILED% time=0 testname=DiaDetail (GridIteratorDiaTest) "
                        << "message=Exceeded maximum rectangle iterations. "
                        << count << " out of " << pow(2, 2*i)
                        << " at level " << i << "."
                        << getCornerSetString(*j) << endl;
                return;
            }
            count++;
        }
        
        cout << "    Finished rectangle iterations at " << count << " of " << pow(2, 2*i) << " at level " << i << endl;
        
        // Diamond iteration phase
        if(i < maxLevel)
        {
            count = 0;

            for(Grid::Level_Iterator k = testGrid->begin(i, true); k != testGrid->end(i, false); k++)
            {
                if(count >= (pow(2, 2*i + 1)) * (pow(2, 2*i) + 1))
                {
                    cout << "%TEST_FAILED% time=0 testname=DiaDetail (GridIteratorDiaTest) "
                            << "message=Exceeded maximum diamond iterations. "
                            << count << " out of " << pow(2, 2*i + 1) * (pow(2, 2*i) + 1)
                            << " at level " << i << "."
                            << getCornerSetString(*k) << endl;
                    return;
                }
                count++;
            }

            cout << "    Finished diamond iterations at " << count << " of " << pow(2, 2*i + 1) * (pow(2, 2*i) + 1) << " at level " << i << endl;
        }
        
        if(i > 3)
        {
            cout << "%TEST_FAILED% time=0 testname=DiaDetail (GridIteratorDiaTest) "
                    << "message=Exceeded maximum expected level. "
                    << i << endl;
            return;
        }
    }
    
    cout << "Max level of " << maxLevel << endl;
}
