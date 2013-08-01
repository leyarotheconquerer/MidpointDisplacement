#include <iostream>
#include <iomanip>

#include "MidpointGenerator.h"
#include "BitmapWriter.h"
#include "GridBitmapWriter.h"

using namespace std;

struct options
{
    int customSeed;
    double customFactor;
    int customWidth, height;
    string newFileName;
    float* customCorners;
    bool terminate;
};

options getOptions(options curOpt);
options resetOptions();
void generateGrid(options opt);

int main(int argc, char** argv) {
    
    options opt;

    cout << "Welcome to the Midpoint Generator V2." << endl;
    opt = resetOptions();
    cout << endl;
    
    while(!opt.terminate)
    {
        opt = getOptions(opt);
    }
    
    return 0;
}//*/

/**
 * Gets the options of the user.
 * @param The current options.
 * @return Returns a populated structure containing user selected options.
 */
options getOptions(options curOpt)
{   
    int action;
    int seed;
    int width, height;
    string fileName;
    
    cout << "Please enter one of the following options." << endl;
    cout << " 0 - Set random seed." << endl;
    cout << " 1 - Set roughness factor." << endl;
    cout << " 2 - Set dimensions of the generated grid." << endl;
    cout << " 3 - Set the output filename (generated bitmap)." << endl;
    cout << " 4 - Set initial corner shades." << endl;
    cout << " 5 - View current options." << endl;
    cout << " 6 - Generate grid using current options." << endl;
    cout << " 7 - Reset options to default." << endl;
    cout << " 8 - Exit." << endl;
    cout << ": ";
    
    cin >> action;
    cout << endl;
    
    switch(action)
    {
        case 0: // Set a new seed value
            cout << "Please enter the new seed: ";
            cin >> seed;
            cout << endl;
            
            curOpt.customSeed = seed;
            
            break;
        case 1:
            double factor;
            
            cout << "Please enter the new roughness factor: ";
            cin >> factor;
            cout << endl;
            
            curOpt.customFactor = factor;
            
            break;
        case 2:
            cout << "Please enter the new dimensions." << endl;
            
            cout << " Width: ";
            cin >> width;
            cout << endl;
            
            cout << " Height: ";
            cin >> height;
            cout << endl;
            
            curOpt.customWidth = width;
            curOpt.height = height;
            
            break;
        case 3:
            cout << "Please enter the new filename: ";
            
            cin >> fileName;
            cout << endl;
            
            curOpt.newFileName = fileName;
            
            break;
        case 4:
            cout << "Please enter the initial corner shades..." << endl;
            
            cout << " Top Left: ";
            cin >> curOpt.customCorners[0];
            cout << endl;
            
            cout << " Top Right: ";
            cin >> curOpt.customCorners[1];
            cout << endl;
            
            cout << " Bottom Right: ";
            cin >> curOpt.customCorners[2];
            cout << endl;
            
            cout << " Bottom Left: ";
            cin >> curOpt.customCorners[3];
            cout << endl;
            
            break;
        case 5:
            cout << "Your current options are as follows..." << endl;
            cout << " Seed (0-default): " << curOpt.customSeed << endl;
            cout << " Roughness Factor: " << curOpt.customFactor << endl;
            cout << " Dimensions (0x0 -> 129x129 default): " << curOpt.customWidth << "x" << curOpt.height << endl;
            cout << " Initial corners (-1 -> random): (" << curOpt.customCorners[0] << ", " << curOpt.customCorners[1] << ", " << curOpt.customCorners[2] << ", " << curOpt.customCorners[3] << ")" << endl;
            cout << " Filename (output.bmp default): " << curOpt.newFileName << endl;
            cout << endl;
            
            break;
        case 6:
            generateGrid(curOpt);
            
            break;
        case 7:
            curOpt = resetOptions();
            
            break;
        case 8:
            curOpt.terminate = true;
            
            break;
        default:
            break;
    }
    
    return curOpt;
}

void generateGrid(options opt)
{
    MidpointDisplacement::MidpointGenerator* generator = new MidpointDisplacement::MidpointGenerator();
    GridBitmapWriter* testBitmap = new GridBitmapWriter();
    MidpointDisplacement::Grid* grid;
    
    cout << "Generating grid...";
    flush(cout);
    
    // Set the roughness factor of the generation
    if(opt.customSeed != 0)
    {
        generator->setSeed(opt.customSeed);
    }
    
    generator->setRandomFactor(opt.customFactor);
    
    // Generate the grid
    if(opt.customWidth > 0 && opt.customCorners[0] == -1)
    {
        grid = generator->run(opt.customWidth, opt.height);
    }
    else if(opt.customWidth > 0 && opt.customCorners[0] != -1)
    {
        grid = generator->run(opt.customCorners, opt.customWidth, opt.height);
    }
    else if(opt.customWidth <= 0 && opt.customCorners[0] != -1)
    {
        grid = generator->run(opt.customCorners);
    }
    else
    {
        grid = generator->run();
    }
    
    cout << " Done" << endl;
    
    cout << "Generating bitmap...";
    flush(cout);
    
    testBitmap->initialize(grid);
    
    testBitmap->write(opt.newFileName);
    
    cout << " Done" << endl;
    
    delete testBitmap;
    
    delete grid;
    
    cout << "Finished generation..." << endl << endl;
}

options resetOptions()
{
    options temp;
    
    temp.customSeed = 0;
    temp.customFactor = 5;
    temp.customWidth = 0;
    temp.height = 0;
    temp.newFileName = "output.bmp";
    temp.terminate = false;
    
    temp.customCorners = new float[4];
    for(int i = 0; i < 4; i++)
    {
        temp.customCorners[i] = -1;
    }
    
    return temp;
}
