#include <iostream>
#include <iomanip>

#include "MidpointGenerator.h"
#include "BitmapWriter.h"
#include "GridBitmapWriter.h"
#include <sstream>
#include <string>
#include <stack>
#include <cstdlib>

using namespace std;

struct options
{
    int seed;
    double factor;
    int width, height;
    string fileName;
    float* corners;
    bool terminate;
    bool generate;
};

options parseTerminalParams(int argc, char** argv);
options resolveParameter(string argument, string param, options opt);
options resolveArgument(string argument, options opt);
options getOptions(options curOpt);
options resetOptions();
void generateGrid(options opt);

int main(int argc, char** argv) {
    
    options opt;

    cout << "Welcome to the Midpoint Generator V2." << endl;
    cout << endl;
    
    opt = parseTerminalParams(argc, argv);
    
    while(!opt.terminate)
    {
        opt = getOptions(opt);
    }
    
    if(opt.generate)
    {
        generateGrid(opt);
    }
    
    return 0;
}//*/

/**
 * Parses the command line arguments and returns the appropriate options.
 * @param argc The number of arguments.
 * @param argv A list of command line arguments.
 * @return An initialized options structure.
 */
options parseTerminalParams(int argc, char** argv)
{
    options opt;
    stack<string> arguments;
    
    // Start with the default options
    opt = resetOptions();
    opt.terminate = true; // Default to no menu
    opt.generate = true; // Default to generation
    
    // Iterate through the command line arguments
    for(int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-')
        {
            arguments.push(argv[i]);
        }
        else
        {   
            // Resolve this parameter using the last given argument
            opt = resolveParameter(arguments.top(), argv[i], opt);
            arguments.pop();
        }
    }
    
    // Resolve any unmatched arguments
    while(arguments.size() > 0)
    {
        opt = resolveArgument(arguments.top(), opt);
        arguments.pop();
    }
    
    return opt;
}

options resolveArgument(string argument, options opt)
{
    if(argument == "-m")
    {
        opt.terminate = false;
        opt.generate = false;
    }
    else
    {
        cout << "Usage:" << endl;
        cout << "    midpoint2.exe [options]" << endl;
        cout << "Options:" << endl;
        cout << "    -m  Use menu interface to enter options." << endl;
        cout << "    -w  Width of the generated grid." << endl;
        cout << "    -h  Height of the generated grid." << endl;
        cout << "    -s  Seed for random generator (Integer)." << endl;
        cout << "    -r  Roughness factor (Percentage)." << endl;
        cout << "    -c1 Top left corner shade (from 0 to 1)." << endl;
        cout << "    -c2 Top right corner shade (from 0 to 1)." << endl;
        cout << "    -c3 Bottom right corner shade (from 0 to 1)." << endl;
        cout << "    -c4 Bottom left corner shade (from 0 to 1)." << endl;
        cout << "    -f  Output filename (bitmap)." << endl;
        exit(1);
    }
    
    return opt;
}

/**
 * Resolves a command line argument/parameter by evaluating its effects on an option structure.
 * @param argument The argument name/type.
 * @param param The parameter to the argument (if it needs one)
 * @param opt The current option object.
 * @return 
 */
options resolveParameter(string argument, string param, options opt)
{
    stringstream paramStream(param);
    
    if(param == "")
    {
        cout << "Usage:" << endl;
        cout << "    midpoint2.exe [options]" << endl;
        cout << "Options:" << endl;
        cout << "    -m  Use menu interface to enter options." << endl;
        cout << "    -w  Width of the generated grid." << endl;
        cout << "    -h  Height of the generated grid." << endl;
        cout << "    -s  Seed for random generator (Integer)." << endl;
        cout << "    -r  Roughness factor (Percentage)." << endl;
        cout << "    -c1 Top left corner shade (from 0 to 1)." << endl;
        cout << "    -c2 Top right corner shade (from 0 to 1)." << endl;
        cout << "    -c3 Bottom right corner shade (from 0 to 1)." << endl;
        cout << "    -c4 Bottom left corner shade (from 0 to 1)." << endl;
        cout << "    -f  Output filename (bitmap)." << endl;
        exit(1);
    }
    else if(argument == "-w")
    {
        paramStream >> opt.width;
    }
    else if(argument == "-h")
    {
        paramStream >> opt.height;
    }
    else if(argument == "-s")
    {
        paramStream >> opt.seed;
    }
    else if(argument == "-r")
    {
        paramStream >> opt.factor;
    }
    else if(argument == "-c1")
    {
        paramStream >> opt.corners[0];
    }
    else if(argument == "-c2")
    {
        paramStream >> opt.corners[1];
    }
    else if(argument == "-c3")
    {
        paramStream >> opt.corners[2];
    }
    else if(argument == "-c4")
    {
        paramStream >> opt.corners[3];
    }
    else if(argument == "-f")
    {
        paramStream >> opt.fileName;
    }
    else
    {
        cout << "Usage:" << endl;
        cout << "    midpoint2.exe [options]" << endl;
        cout << "Options:" << endl;
        cout << "    -m  Use menu interface to enter options." << endl;
        cout << "    -w  Width of the generated grid." << endl;
        cout << "    -h  Height of the generated grid." << endl;
        cout << "    -s  Seed for random generator (Integer)." << endl;
        cout << "    -r  Roughness factor (Percentage)." << endl;
        cout << "    -c1 Top left corner shade (from 0 to 1)." << endl;
        cout << "    -c2 Top right corner shade (from 0 to 1)." << endl;
        cout << "    -c3 Bottom right corner shade (from 0 to 1)." << endl;
        cout << "    -c4 Bottom left corner shade (from 0 to 1)." << endl;
        cout << "    -f  Output filename (bitmap)." << endl;
        exit(1);
    }
    
    return opt;
}

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
            
            curOpt.seed = seed;
            
            break;
        case 1:
            double factor;
            
            cout << "Please enter the new roughness factor: ";
            cin >> factor;
            cout << endl;
            
            curOpt.factor = factor;
            
            break;
        case 2:
            cout << "Please enter the new dimensions." << endl;
            
            cout << " Width: ";
            cin >> width;
            cout << endl;
            
            cout << " Height: ";
            cin >> height;
            cout << endl;
            
            curOpt.width = width;
            curOpt.height = height;
            
            break;
        case 3:
            cout << "Please enter the new filename: ";
            
            cin >> fileName;
            cout << endl;
            
            curOpt.fileName = fileName;
            
            break;
        case 4:
            cout << "Please enter the initial corner shades..." << endl;
            
            cout << " Top Left: ";
            cin >> curOpt.corners[0];
            cout << endl;
            
            cout << " Top Right: ";
            cin >> curOpt.corners[1];
            cout << endl;
            
            cout << " Bottom Right: ";
            cin >> curOpt.corners[2];
            cout << endl;
            
            cout << " Bottom Left: ";
            cin >> curOpt.corners[3];
            cout << endl;
            
            break;
        case 5:
            cout << "Your current options are as follows..." << endl;
            cout << " Seed (0-default): " << curOpt.seed << endl;
            cout << " Roughness Factor: " << curOpt.factor << endl;
            cout << " Dimensions (0x0 -> 129x129 default): " << curOpt.width << "x" << curOpt.height << endl;
            cout << " Initial corners (-1 -> random): (" << curOpt.corners[0] << ", " << curOpt.corners[1] << ", " << curOpt.corners[2] << ", " << curOpt.corners[3] << ")" << endl;
            cout << " Filename (output.bmp default): " << curOpt.fileName << endl;
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
    if(opt.seed != 0)
    {
        generator->setSeed(opt.seed);
    }
    
    generator->setRandomFactor(opt.factor);
    
    // Generate the grid
    if(opt.width > 0 && opt.corners[0] == -1)
    {
        grid = generator->run(opt.width, opt.height);
    }
    else if(opt.width > 0 && opt.corners[0] != -1)
    {
        grid = generator->run(opt.corners, opt.width, opt.height);
    }
    else if(opt.width <= 0 && opt.corners[0] != -1)
    {
        grid = generator->run(opt.corners);
    }
    else
    {
        grid = generator->run();
    }
    
    cout << " Done" << endl;
    
    cout << "Generating bitmap...";
    flush(cout);
    
    testBitmap->initialize(grid);
    
    testBitmap->write(opt.fileName);
    
    cout << " Done" << endl;
    
    delete testBitmap;
    
    delete grid;
    
    cout << "Finished generation..." << endl << endl;
}

options resetOptions()
{
    options temp;
    
    temp.seed = 0;
    temp.factor = 5;
    temp.width = 0;
    temp.height = 0;
    temp.fileName = "output.bmp";
    temp.terminate = false;
    temp.generate = false;
    
    temp.corners = new float[4];
    for(int i = 0; i < 4; i++)
    {
        temp.corners[i] = -1;
    }
    
    return temp;
}
