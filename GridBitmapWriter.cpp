/* 
 * File:   GridBitmapWriter.cpp
 * Author: Hazen
 * 
 * Created on July 30, 2013, 4:47 PM
 */

#include "GridBitmapWriter.h"

void GridBitmapWriter::initialize(Grid* grid)
{
    this->contentHeight = grid->getHeight();
    this->contentWidth = grid->getWidth();
    
    this->contents = new rgbValue*[this->contentWidth];
    for(int i = 0; i < this->contentWidth; i++)
    {
        this->contents[i] = new rgbValue[this->contentHeight];
    }
    
    for(int i = 0; i < this->contentWidth; i++)
    {
        for(int j = 0; j < this->contentHeight; j++)
        {
            char shade = (int)(grid->getShade(i, j) * 255);
            
            this->contents[i][j].r = shade;
            this->contents[i][j].g = shade;
            this->contents[i][j].b = shade;
        }
    }
}
