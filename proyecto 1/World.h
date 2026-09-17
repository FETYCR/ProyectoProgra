#pragma once
#include "Cell.h"

const int ROWS = 20;
const int COLS = 20;

class World
{
private:
    Cell cells[ROWS][COLS];
    int rows;
    int cols;
    int generation;

public:
    World(int rows, int cols);
    int countNeighbors(int row, int col);
    int countNeighborsBySpecies(int row, int col, int species);
    int predominantSpecies(int row, int col);
    void nextGeneration(Cell nextCells[ROWS][COLS]);


    int getCols() const;
    int getRows() const;
    int getGeneration() const;
    int getCellSpecies(int row,int cols) const;
    bool seedManual(int row, int cols, int species);
    bool seedRandom(float density);
    bool seedPattern(int rows, int cols, int species);

};