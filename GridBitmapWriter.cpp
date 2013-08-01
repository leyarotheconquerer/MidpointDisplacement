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
            float gradientShade = grid->getShade(i, j);
            if(gradientShade < 0)
            {
                gradientShade = 0;
            }
            else if(gradientShade > 1)
            {
                gradientShade = 1;
            }
        
            char shade = (int)(gradientShade * 255);
            
            this->contents[i][j].r = shade;
            this->contents[i][j].g = shade;
            this->contents[i][j].b = shade;
        }
    }
}
