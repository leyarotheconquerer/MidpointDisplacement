/* 
 * File:   GridIteratorTest.cpp
 * Author: Hazen
 * 
 * Created on July 28, 2013, 11:59 AM
 */

#include "GridIteratorTest.h"
#include <iostream>
#include "../Grid.h"

using namespace std;
using namespace MidpointDisplacement;

void GridIteratorTest::run()
{
    cout << "%TEST_STARTED% StandardDetail (GridIteratorTest)" << endl;
    float corners[] = {1, 1, 1, 1};
    Grid* standard = new Grid(corners, 129, 129);
    detail(standard, "StandardDetail");
    delete standard;
    cout << "%TEST_FINISHED% time=0 StandardDetail (GridIteratorTest)" << endl;
    
    /*
    // Even doesn't work. Consider changing the iterator to make even work.
    cout << "%TEST_STARTED% EvenDetail (GridIteratorTest)" << endl;
    Grid* even = new Grid(corners, 8, 8);
    detail(even, "EvenDetail");
    delete even;
    cout << "%TEST_FINISHED% time=0 EvenDetail (GridIteratorTest)" << endl;
    //*/
    
    cout << "%TEST_STARTED% StressDetail (GridIteratorTest)" << endl;
    Grid* stress = new Grid(corners, 1025, 1025);
    detail(stress, "StressDetail");
    delete stress;
    cout << "%TEST_FINISHED% time=0 StressDetail (GridIteratorTest)" << endl;
}

void GridIteratorTest::detail(Grid* testGrid, string testName)
{
    cout << "GridIteratorTest " << testName << endl;
    
    int maxLevel = round(log2(testGrid->getMaxDimension()));
    
    cout << "Max level of " << maxLevel << endl;
    
    // Level iteration
    for(int i = 0; i <= maxLevel; i++)
    {
        // Rectangle iteration phase
        int count = 0;
        
        for(Grid::Level_Iterator j= testGrid->begin(i, false); j != testGrid->end(i, false); j++)
        {
            if(count >= pow(2, 2*i))
            {
                cout << "%TEST_FAILED% time=0 testname=" << testName << " (GridIteratorTest) "
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
                    cout << "%TEST_FAILED% time=0 testname=" << testName << " (GridIteratorTest) "
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
        
        if(i > maxLevel)
        {
            cout << "%TEST_FAILED% time=0 testname=" << testName << " (GridIteratorTest) "
                    << "message=Exceeded maximum expected level. "
                    << i << endl;
            return;
        }
    }
}

