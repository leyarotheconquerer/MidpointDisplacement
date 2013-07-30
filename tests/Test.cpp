#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "Grid.h"
#include "test/GridTest.h"
#include "TestSuite.h"
#include "test/GridIteratorRectTest.h"
#include "test/GridIteratorDiaTest.h"
#include "test/GridIteratorTest.h"

/*
 * Simple C++ Test Suite
 */

using namespace std;
using namespace MidpointDisplacement;

int main(int argc, char** argv)
{
    // Start the grid tests
    std::cout << "%SUITE_STARTING% GridTest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;
    TestSuite* gridTest = new GridTest();
    gridTest->run();
    delete gridTest;
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;
    
    // Start the rectangle grid iterator tests
    cout << "%SUITE_STARTING% GridIteratorRectTest" << endl;
    cout << "%SUITE_STARTED%" << endl;
    TestSuite* rectIteratorTest = new GridIteratorRectTest();
    rectIteratorTest->run();
    delete rectIteratorTest;
    cout << "%SUITE_FINISHED% time=0" << endl;
    
    // Start the grid iterator tests
    cout << "%SUITE_STARTING% GridIteratorDiaTest" << endl;
    cout << "%SUITE_STARTED%" << endl;
    TestSuite* diaIteratorTest = new GridIteratorDiaTest();
    diaIteratorTest->run();
    delete diaIteratorTest;
    cout << "%SUITE_FINISHED% time=0" << endl;
    
    // Start the general iterator tests
    cout << "%SUITE_STARTING% GridIteratorTest" << endl;
    cout << "%SUITE_STARTED%" << endl;
    TestSuite* iteratorTest = new GridIteratorTest();
    iteratorTest->run();
    delete iteratorTest;
    cout << "%SUITE_FINISHED% time=0" << endl;
    
    return (EXIT_SUCCESS);
}

