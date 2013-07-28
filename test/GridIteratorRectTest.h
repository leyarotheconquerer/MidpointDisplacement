#ifndef GRIDITERATORRECTTEST_H
#define	GRIDITERATORRECTTEST_H

#include "TestSuite.h"
#include "../Grid.h"

using namespace MidpointDisplacement;

class GridIteratorRectTest : public TestSuite {
public:
    GridIteratorRectTest() {}
    GridIteratorRectTest(const GridIteratorRectTest& orig) {}
    virtual ~GridIteratorRectTest() {}
    
    void run();
private:
    void rectCreationBegin(Grid* testGrid);
    void rectCreationEnd(Grid* testGrid);
    void rectEquality(Grid* testGrid);
    void rectInequality(Grid* testGrid);
    void rectIncrement1(Grid* testGrid);
    void rectIncrement2(Grid* testGrid);
};

#endif

