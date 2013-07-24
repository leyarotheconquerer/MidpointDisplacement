#include <stdlib.h>
#include <iostream>
#include "Grid.h"

/*
 * Simple C++ Test Suite
 */

using namespace std;
using namespace MidpointDisplacement;

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
    }
    
    if(!test)
    {
        cout << "%TEST_FAILED% time=0 testname=GridCreation1 (GridTest) "
                << "message=Failed to create the test object." << endl;
    }
    
    if(test->getWidth() != 100 || test->getHeight() != 100)
    {
        cout << "%TEST_FAILED% time=0 testname=GridCreation1 (GridTest) "
                << "message=Incorrect Grid dimensions. " 
                << "(" << test->getWidth() << ", " << test->getHeight() << ")"
                << endl;
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
    }
    
    if(!test)
    {
        cout << "%TEST_FAILED% time=0 testname=GridCreation2 (GridTest) "
                << "message=Failed to create the test object." << endl;
    }
    
    if(test->getWidth() != 50 || test->getHeight() != 50)
    {
        cout << "%TEST_FAILED% time=0 testname=GridCreation2 (GridTest) "
                << "message=Incorrect Grid dimensions. "
                << "(" << test->getWidth() << ", " << test->getHeight() << ")"
                << endl;
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
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% GridTest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;
    
    cout << "%TEST_STARTED% GridCreation1 (GridTest)" << endl;
    gridCreation1();
    cout << "%TEST_FINISHED% time=0 GridCreation1 (GridTest)" << endl;
    
    cout << "%TEST_STARTED% GridCreation2 (GridTest)" << endl;
    gridCreation2();
    cout << "%TEST_FINISHED% time=0 GridCreation2 (GridTest)" << endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

