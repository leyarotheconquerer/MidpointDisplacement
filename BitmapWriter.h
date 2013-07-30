#ifndef BITMAPWRITER_H
#define	BITMAPWRITER_H

#include <string>

using namespace std;

class BitmapWriter {
public:
    BitmapWriter() {}
    BitmapWriter(const BitmapWriter& orig) {}
    virtual ~BitmapWriter() {}
    
    void write(string fileName);
protected:
    struct rgbValue
    {
        char r;
        char g;
        char b;
        char unused;
    };
    
    struct header
    {
        /** Set to "BM" to identify as bitmap */
        unsigned short bmIdentifier;
        /** Set to the number of bytes in the file */
        unsigned int filesize;
        /** Reserved (valued at 0) */
        unsigned int reserved;
        /** The offset from the beginning of the file to the pixel array */
        unsigned int offset;
    };
    
    struct infoHeader
    {
        /** Length of the info header */
        unsigned int infoHeaderLength;
        /** Horizontal width of the pixel array */
        unsigned int contentWidth;
        /** Vertical width of the pixel array */
        unsigned int contentHeight;
        /** Number of color planes */
        unsigned short planes;
        /** Number of colors specified as number of bits per pixel
         * (probably 8 or 16 right now) */
        unsigned short bitsPerPixel;
        /** Compression type (0-none, 1-RLE 8-bit/pixel, 2-RLE 4-bit/pixel) */
        unsigned int compressionType;
        /** Size of the picture in bytes */
        unsigned int contentSize;
        /** Pixel per meter horizontal resolution of the image */
        unsigned int horizontalResolution;
        /** Pixel per meter vertical resolution of the image */
        unsigned int verticalResolution;
        /** Number of colors in the color palette (0 for all colors possible) */
        unsigned int numColorsInPalette;
        /** Number of "important" colors (0 when all colors are used) */
        unsigned int numImportantColors;
    };
    
    rgbValue** contents;
    int contentWidth, contentHeight;
    header header;
    infoHeader infoHeader;
};

#endif

