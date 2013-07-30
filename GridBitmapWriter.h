/* 
 * File:   GridBitmapWriter.h
 * Author: Hazen
 *
 * Created on July 30, 2013, 4:47 PM
 */

#ifndef GRIDBITMAPWRITER_H
#define	GRIDBITMAPWRITER_H

#include "BitmapWriter.h"
#include "Grid.h"

using namespace MidpointDisplacement;

class GridBitmapWriter : public BitmapWriter {
public:
    GridBitmapWriter() {}
    GridBitmapWriter(const GridBitmapWriter& orig) {}
    virtual ~GridBitmapWriter() {}
    
    /**
     * Initializes the Bitmap Writer to write out the data in the grid object.
     * @param grid The Grid object containing data to write out.
     */
    void initialize(Grid* grid);
private:

};

#endif	/* GRIDBITMAPWRITER_H */

