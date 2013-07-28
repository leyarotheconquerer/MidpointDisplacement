#ifndef GRIDITERATORDIATEST_H
#define	GRIDITERATORDIATEST_H

#include "TestSuite.h"

class GridIteratorDiaTest : public TestSuite {
public:
    GridIteratorDiaTest() {};
    GridIteratorDiaTest(const GridIteratorDiaTest& orig) {};
    virtual ~GridIteratorDiaTest() {};
    
    void run();
    
private:
    void diaCreationBegin(Grid* testGrid);
    void diaCreationEnd(Grid* testGrid);
    void diaEquality(Grid* testGrid);
    void diaInequality(Grid* testGrid);
    void diaIncrement1(Grid* testGrid);
    void diaIncrement2(Grid* testGrid);
    void diaDetail(Grid* testGrid);
};

#endif	/* GRIDITERATORDIATEST_H */

