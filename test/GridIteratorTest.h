/* 
 * File:   GridIteratorTest.h
 * Author: Hazen
 *
 * Created on July 28, 2013, 11:59 AM
 */

#ifndef GRIDITERATORTEST_H
#define	GRIDITERATORTEST_H

#include "TestSuite.h"

class GridIteratorTest : public TestSuite {
public:
    GridIteratorTest() {}
    GridIteratorTest(const GridIteratorTest& orig) {}
    virtual ~GridIteratorTest() {}
    
    void run();
private:
    void detail(Grid* testGrid, string testName);
};

#endif	/* GRIDITERATORTEST_H */

