#include "BitmapWriter.h"
#include <fstream>
#include <iostream>

void BitmapWriter::write(string fileName)
{
    fstream outputFile(fileName.c_str(), ios_base::out | ios_base::binary); 
    
    // Generate header information
    this->header.bmIdentifier = 0x4D42;
    this->header.filesize = sizeof(header) + sizeof(infoHeader) +
            sizeof(rgbValue) * contentHeight * contentWidth - 2; // There are 2 extra bytes in header for some reason
    this->header.reserved = 0;
    this->header.offset = sizeof(header) + sizeof(infoHeader) - 2;
    
    // Generate information header information
    this->infoHeader.infoHeaderLength = sizeof(infoHeader);
    this->infoHeader.contentWidth = this->contentWidth;
    this->infoHeader.contentHeight = this->contentHeight;
    this->infoHeader.planes = 1;
    this->infoHeader.bitsPerPixel = 24;
    this->infoHeader.compressionType = 0;
    this->infoHeader.contentSize = sizeof(rgbValue)
            * this->contentWidth * this->contentHeight;
    this->infoHeader.horizontalResolution = 1;
    this->infoHeader.verticalResolution = 1;
    this->infoHeader.numColorsInPalette = 0;
    this->infoHeader.numImportantColors = 0;
    
    // Write the headers
    // Extended writing method
    outputFile.write((char*)&header.bmIdentifier, sizeof(header.bmIdentifier));
    outputFile.write((char*)&header.filesize, sizeof(header.filesize));
    outputFile.write((char*)&header.reserved, sizeof(header.reserved));
    outputFile.write((char*)&header.offset, sizeof(header.offset));
    
    outputFile.write((char*)&infoHeader.infoHeaderLength, sizeof(infoHeader.infoHeaderLength));
    outputFile.write((char*)&infoHeader.contentWidth, sizeof(infoHeader.contentWidth));
    outputFile.write((char*)&infoHeader.contentHeight, sizeof(infoHeader.contentHeight));
    outputFile.write((char*)&infoHeader.planes, sizeof(infoHeader.planes));
    outputFile.write((char*)&infoHeader.bitsPerPixel, sizeof(infoHeader.bitsPerPixel));
    outputFile.write((char*)&infoHeader.compressionType, sizeof(infoHeader.compressionType));
    outputFile.write((char*)&infoHeader.contentSize, sizeof(infoHeader.contentSize));
    outputFile.write((char*)&infoHeader.horizontalResolution, sizeof(infoHeader.horizontalResolution));
    outputFile.write((char*)&infoHeader.verticalResolution, sizeof(infoHeader.verticalResolution));
    outputFile.write((char*)&infoHeader.numColorsInPalette, sizeof(infoHeader.numColorsInPalette));
    outputFile.write((char*)&infoHeader.numImportantColors, sizeof(infoHeader.numImportantColors));
    
    // Write the file contents
    for(int i = 0; i < this->contentHeight; i++)
    {
        for(int j = 0; j < this->contentWidth; j++)
        {
            outputFile.write((char*)(&(this->contents[j][i])), sizeof(this->contents[j][i]));
        }
        // Pad to the end of the nearest byte
        //int paddingSize = 4 - (sizeof(rgbValue) * this->contentWidth) % 4;
        int paddingSize = this->contentWidth % 4;
        int zero = 0; // There's got to be a better way of doing this...
        outputFile.write((char*)&zero, paddingSize);
    }
    
    outputFile.close();
}