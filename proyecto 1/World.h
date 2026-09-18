#pragma once
#include "SpeciesRule.h"
#include "Cell.h"

    
class World
{
private:
    Cell** cells;
    int rows;
    int cols;
    int generation;
    SpeciesRule Rules;

public:
    World(int rows, int cols);
    int countNeighbors(int row, int col);
    int countNeighborsBySpecies(int row, int col, int species);
    int predominantSpecies(int row, int col);
    void nextGeneration();


    int getCols() const;
    int getRows() const;
    int getGeneration() const;
    int getCellSpecies(int row,int col) const;
    bool seedManual(int row, int col, int species);
    bool seedRandom(float density);
    bool seedPattern(int row, int col, int species);
    int countPopulation(int species) const;
    int counterAliveCells() const;

    ~World();
};