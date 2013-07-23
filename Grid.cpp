#include "Grid.h"

using namespace MidpointDisplacement;

Grid::Grid(float* corners)
{
    Grid(corners, width, height);
}

Grid::Grid(float* corners, int width, int height)
{
    // Store the dimensions
    this->width = width;
    this->height = height;
    
    // Find the defining maximum dimension
    if(width >= height)
    {
        maxDimension = width;
    }
    else
    {
        maxDimension = height;
    }
    
    // Initialize the grid
    this->grid = new float*[width];
    for(int i = 0; i < width; i++)
    {
        this->grid[i] = new float[height];
    }
    
    // Initialize the grid to invalid values so we can tell if generation is
    // incomplete.
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            this->grid[i][j] = -1;
        }
    }
    
    // Initialize the corners
    this->grid[0][0]                    = corners[0];
    this->grid[width-1][0]              = corners[1];
    this->grid[width-1][height-1]       = corners[2];
    this->grid[0][height-1]             = corners[3];
}

Grid::Grid(const Grid& orig)
{
    // Store the dimensions
    this->width = orig.width;
    this->height = orig.height;
    
    // Initialize the grid
    this->grid = new float*[orig.width];
    
    for(int i = 0; i < orig.width; i++)
    {
        this->grid[i] = new float[orig.height];
    }
    
    // Initialize the grid to invalid values so we can tell if generation is
    // incomplete.
    for(int i = 0; i < orig.width; i++)
    {
        for(int j = 0; j < orig.height; j++)
        {
            this->grid[i][j] = orig.grid[i][j];
        }
    }
}

Grid::~Grid() {
    for(int i = 0; i < this->width; i++)
    {
        delete[] this->grid[i];
    }
    
    delete[] this->grid;
}

void Grid::setShade(float shade, int x, int y)
{
    // Perform some basic validation on input
    if(x >= 0 && x < this->width && y >= 0 && y < this->height)
    {
        this->grid[x][y] = shade;
    }
}

float Grid::getShade(int x, int y)
{
    // Perform some basic validation on input
    if(x < 0 || x >= this->width || y < 0 || y >= this->height)
    {
        return -1;
    }
    
    return this->grid[x][y];
}
