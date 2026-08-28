#pragma once
#include "Cell.h"

const int ROWS = 20;
const int COLUMNS = 20;

class World
{
private:
    Cell cells[ROWS][COLUMNS];
    int rows;
    int columns;
    int generation;

public:
    World(int rows, int columns);
    int countNeighbors(int row, int column);
    int countNeighborsBySpecies(int row, int column, int species);
    int predominantSpecies(int row, int column);
    void nextGeneration(Cell nextCells[ROWS][COLUMNS]);
};