#include <iostream>
#include <cstdlib>
#include "World.h"

World::World(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    this->generation = 0;

    cells = new Cell * [rows];
    for (int i = 0; i < rows; i++) {
        cells[i] = new Cell[cols];
    }
    Rules.loadOfficialConfig();
}

int World::countNeighbors(int row, int col)
{
    int counter = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int neighborRow = row + i;
            int neighborColumn = col + j;

            if (neighborRow >= 0 && neighborRow < rows && neighborColumn >= 0 && neighborColumn < cols && !(i == 0 && j == 0))

              if (cells[neighborRow][neighborColumn].isAlive())  {
                    counter++;
                }
        }
    }
    return counter;
}

int World::countNeighborsBySpecies(int row, int col, int species)
{
    int counter = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++)   {

           int neighborRow = row + i;
           int neighborColumn = col + j;

      if (neighborRow >= 0 && neighborRow < rows && neighborColumn >= 0 && neighborColumn < cols && !(i == 0 && j == 0))  {
            if (cells[neighborRow][neighborColumn].getSpecies() == species) {
                    counter++;
             }
      }
        }
    }
    return counter;
}

int World::predominantSpecies(int row, int col)
{

    int species1 = countNeighborsBySpecies(row, col, 1);
    int species2 = countNeighborsBySpecies(row, col, 2);
    int species3 = countNeighborsBySpecies(row, col, 3);
    int species4 = countNeighborsBySpecies(row, col, 4);


    int highestCount = 0;
    int predominant = 0;
    int tieBreaker = Rules.getTieBreaker();

    if (species1 > highestCount || (species1 == highestCount && tieBreaker != 0)) {
        highestCount = species1;
        predominant = 1;
    }
    if (species2 > highestCount || (species2 == highestCount && tieBreaker != 0)){
        highestCount = species2;
        predominant = 2;
    }
    if (species3 > highestCount || (species3 == highestCount && tieBreaker != 0))  {
        highestCount = species3;
        predominant = 3;
    }
    if (species4 > highestCount || (species4 == highestCount && tieBreaker != 0)) {
        highestCount = species4;
        predominant = 4;
    }

    return predominant;
}

void World::nextGeneration(){

    Cell** nextCells = new Cell * [rows];
    for (int i = 0; i < rows; i++) {
        nextCells[i] = new Cell[cols];
    }

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
      int neighbors = countNeighbors(i, j);

       if (cells[i][j].isAlive()){

          int species = cells[i][j].getSpecies();
         bool survives = false;
     
         if (species == 1 && (neighbors == 1 || neighbors == 2)){
                    survives = true;
         }
         else if (species == 2 && (neighbors == 2 || neighbors == 3)){
              survives = true;
         }
         else if (species == 3 && neighbors == 2) {
                    survives = true;
         }
         else if (species == 4 && (neighbors == 1 || neighbors == 2 || neighbors == 3)){
                    survives = true;
         }

          if (survives) {
                    nextCells[i][j].setSpecies(species);
          }
           else {
                    nextCells[i][j].setSpecies(0);
           }
       }
            else {
                
                if (neighbors == 2 || neighbors == 3) {
                    int newSpecies = predominantSpecies(i, j);
                    nextCells[i][j].setSpecies(newSpecies);
                }
                else {
                    nextCells[i][j].setSpecies(0);
                }
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        delete[] cells[i];
    }
    delete[] cells;

    cells = nextCells;
    generation++;
}



int World::getCols() const{
    return cols;
}

int World::getRows() const{
    return rows;
}

int World::getGeneration() const{
    return generation;
}

int World::getCellSpecies(int row, int cols) const{
    return cells[row][cols].getSpecies();
}

bool World::seedManual(int row, int col, int species){
    if (row < 0 || col < 0 || row >= getRows() || col >= getCols()) {
        return false;
    }
    
    if (species < 1 || species > 4) {
        return false;
    }
    
    cells[row][col].setSpecies(species);
    return true;
    
}

bool World::seedRandom(float density){
    if (density < 0 || density > 1) {
        return false;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            float randomValue = (rand() % 101) / 100.0f;
            if (randomValue < density) {
                int randomSpecie = (rand() % 4) + 1;
                cells[i][j].setSpecies(randomSpecie);
            }
        }
    }

    return true;
}

bool World::seedPattern(int row, int col, int species){
    if (row < 0 || col < 0 || (row + 2) >= getRows() || (row + 1) >= getRows() || (col + 2) >= getCols()|| (col + 1) >= getCols()) {
        return false;
    }
    if (species < 1 || species > 4) {
        return false;
    }

    cells[row][col+1].setSpecies(species);
    cells[row+1][col+2].setSpecies(species);
    cells[row+2][col].setSpecies(species);
    cells[row+2][col+1].setSpecies(species);
    cells[row+2][col+2].setSpecies(species);
    
    return true;
}

int World::countPopulation(int species) const{
    int counter = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (getCellSpecies(i,j) == species) {
                counter++;
            }

        }
    }
    return counter;
}

int World::counterAliveCells() const{
    int counter = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (cells[i][j].isAlive()) {
                counter++;
            }
        }
    }
    return counter;
}

World::~World(){

    for (int i = 0; i < rows; i++) {
        delete[] cells[i];
    }
    delete[] cells;
}
