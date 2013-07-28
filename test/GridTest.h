#ifndef GRIDTEST_H
#define	GRIDTEST_H

#include "TestSuite.h"

class GridTest : public TestSuite {
public:
    GridTest() {}
    GridTest(const GridTest& orig) {}
    virtual ~GridTest() {}
    
    void run();
private:

    void gridCreation1();
    void gridCreation2();
    void gridInitialization();
    void gridFilling();
};

#endif	/* GRIDTEST_H */

