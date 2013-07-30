#include <iostream>
#include <iomanip>

#include "MidpointGenerator.h"

using namespace std;

int main(int argc, char** argv) {

    MidpointDisplacement::MidpointGenerator* generator = new MidpointDisplacement::MidpointGenerator();
    
    cout << "Generating grid..." << endl;
    
    MidpointDisplacement::Grid* grid = generator->run(9, 9);
    
    cout << "Displaying grid..." << endl;
    
    for(int i = 0; i < grid->getHeight(); i++)
    {
        for(int j = 0; j < grid->getWidth(); j++)
        {
            cout << std::setw(10) << grid->getShade(j, i) << " ";
        }
        cout << endl;
    }
    
    cout << "Finished grid..." << endl;
    
    return 0;
}

