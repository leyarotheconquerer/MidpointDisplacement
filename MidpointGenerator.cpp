#include "MidpointGenerator.h"
#include "TestSuite.h"
#include <cstdlib>
#include <iostream>

using namespace MidpointDisplacement;

Grid* MidpointGenerator::run()
{
    this->run(129, 129);
}

Grid* MidpointGenerator::run(int width, int height)
{
    float corners[4];
    
    corners[0] = (rand() % 100) / 100.0;
    corners[1] = (rand() % 100) / 100.0;
    corners[2] = (rand() % 100) / 100.0;
    corners[3] = (rand() % 100) / 100.0;
    
    return this->run(corners, width, height);
}

Grid* MidpointGenerator::run(float* corners)
{
    return this->run(corners, 129, 129);
}

Grid* MidpointGenerator::run(float* corners, int width, int height)
{
    // Calculate the true dimensions (2^n + 1)
    int trueWidth = calculateDimension(width);
    int trueHeight = calculateDimension(height);
    
    // Generate an appropriate grid object
    Grid* grid = new Grid(corners, trueWidth, trueHeight);
    
    // Run the midpoint generator
    grid = run(grid);
    
    // Create return grid
    Grid* returnGrid = new Grid(corners, width, height);
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            returnGrid->setShade(grid->getShade(i, j), i, j);
        }
    }
    
    // Delete the construction grid
    delete grid;
    
    // Return the trimmed grid
    return returnGrid;
}

Grid* MidpointGenerator::run(Grid* grid)
{
    srand(randomSeed);
    
    // Calculate the maximum dimensions
    int maxLevel = round(log2(grid->getMaxDimension()));
    
    // Go through each level
    for(int i = 0; i < maxLevel; i++)
    {
        // Iterate through each rectangle
        for(Grid::Level_Iterator j = grid->begin(i, false); j != grid->end(i, false); j++)
        {
            fillCenterCoor(grid, *j);
        }
        
        // Iterate through each diamond
        for(Grid::Level_Iterator k = grid->begin(i, true); k != grid->end(i, true); k++)
        {
            fillCenterCoor(grid, *k);
        }
    }
    
    return grid;
}

void MidpointGenerator::fillCenterCoor(Grid* grid, CornerSet corners)
{
    int count = 0;
    double total = 0;
    int totalX = 0;
    int totalY = 0;
    
    double shade;
    int x, y;
    
    // Average the corners that are in range
    if(corners.corner1 >= 0 && corners.corner1 <= 1)
    {
        total += corners.corner1;
        count++;
    }
    
    totalX += corners.corner1Coor[0];
    totalY += corners.corner1Coor[1];
    
    if(corners.corner2 >= 0 && corners.corner2 <= 1)
    {
        total += corners.corner2;
        count++;
    }
    
    totalX += corners.corner2Coor[0];
    totalY += corners.corner2Coor[1];
    
    if(corners.corner3 >= 0 && corners.corner3 <= 1)
    {
        total += corners.corner3;
        count++;
    }
    
    totalX += corners.corner3Coor[0];
    totalY += corners.corner3Coor[1];
    
    if(corners.corner4 >= 0 && corners.corner4 <= 1)
    {
        total += corners.corner4;
        count++;
    }
    
    totalX += corners.corner4Coor[0];
    totalY += corners.corner4Coor[1];
    
    shade = total / count;
    x = totalX / 4;
    y = totalY / 4;
    
    // Add a random factor to the shade
    shade += ((rand() % 100) / 100.0 * (randomFactor / 100.0)) - 0.025;
    
    // Set the shade of the calculated average coordinate
    grid->setShade(shade, x, y);
}

int MidpointGenerator::calculateDimension(int dimension)
{
    int testDimension = 3;
    
    // Find the first valid value above the given dimension
    while(testDimension < dimension)
    {
        // Go back to a power of 2 
        --testDimension;
        // Go to the next power of 2
        testDimension *= 2;
        // Go to the power of 2 plus 1
        ++testDimension;
    }
    
    return testDimension;
}

void MidpointGenerator::setRandomFactor(double factor)
{
    this->randomFactor = factor;
}

void MidpointGenerator::setSeed(int seed)
{
    this->randomSeed = seed;
}
