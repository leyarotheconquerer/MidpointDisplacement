#include <iostream>
#include <iomanip>

#include "MidpointGenerator.h"
#include "BitmapWriter.h"
#include "GridBitmapWriter.h"

using namespace std;

int main(int argc, char** argv) {

    MidpointDisplacement::MidpointGenerator* generator = new MidpointDisplacement::MidpointGenerator();
    GridBitmapWriter* testBitmap = new GridBitmapWriter();
    MidpointDisplacement::Grid* grid;
    
    cout << "Generating grid...";
    
    // Set the roughness factor of the generation
    generator->setRandomFactor(3.5);
    
    // Generate the grid
    grid = generator->run(513, 513);
    
    cout << " Done" << endl;
    
    cout << "Generating bitmap...";
    
    testBitmap->initialize(grid);
    
    testBitmap->write("output.bmp");
    
    cout << " Done" << endl;
    
    delete testBitmap;
    
    delete grid;
    
    cout << "Finished grid..." << endl;
    
    return 0;
}

