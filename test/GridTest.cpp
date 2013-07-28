#include "GridTest.h"
#include <iostream>
#include "../Grid.h"

using namespace std;

void GridTest::run()
{
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
}

void GridTest::gridCreation1()
{
    cout << "GridTest GridCreation1" << endl;
    
    MidpointDisplacement::Grid* test = NULL;
    
    float corners[] = {0, .333, .666, 1};
    try
    {
        test = new MidpointDisplacement::Grid(corners);
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

void GridTest::gridCreation2()
{
    cout << "GridTest GridCreation2" << endl;
    
    MidpointDisplacement::Grid* test = NULL;
    
    float corners[] = {0, .333, .666, 1};
    try
    {
        test = new MidpointDisplacement::Grid(corners, 50, 50);
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

void GridTest::gridInitialization()
{
    cout << "GridTest GridInitialization" << endl;
    
    float corner[] = {-1, -1, -1, -1};
    MidpointDisplacement::Grid* test = new MidpointDisplacement::Grid(corner, 10, 10);
    
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

void GridTest::gridFilling()
{
    cout << "GridTest GridFilling" << endl;
    
    float corner[] = {1,1,1,1};
    MidpointDisplacement::Grid* test = new MidpointDisplacement::Grid(corner, 10, 10);
    
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
