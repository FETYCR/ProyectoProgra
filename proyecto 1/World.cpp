#include <iostream>
#include "World.h"

World::World(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;
    this->generation = 0;
}

int World::countNeighbors(int row, int column)
{
    int counter = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int neighborRow = row + i;
            int neighborColumn = column + j;

            if (neighborRow >= 0 && neighborRow < rows && neighborColumn >= 0 && neighborColumn < columns && !(i == 0 && j == 0))

              if (cells[neighborRow][neighborColumn].isAlive())  {
                    counter++;
                }
        }
    }
    return counter;
}

int World::countNeighborsBySpecies(int row, int column, int species)
{
    int counter = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++)   {

           int neighborRow = row + i;
           int neighborColumn = column + j;

      if (neighborRow >= 0 && neighborRow < rows && neighborColumn >= 0 && neighborColumn < columns && !(i == 0 && j == 0))  {
            if (cells[neighborRow][neighborColumn].getSpecies() == species) {
                    counter++;
             }
      }
        }
    }
    return counter;
}

int World::predominantSpecies(int row, int column)
{

    int species1 = countNeighborsBySpecies(row, column, 1);
    int species2 = countNeighborsBySpecies(row, column, 2);
    int species3 = countNeighborsBySpecies(row, column, 3);
    int species4 = countNeighborsBySpecies(row, column, 4);


    int highestCount = 0;
    int predominant = 0;

    if (species1 > highestCount) {
        highestCount = species1;
        predominant = 1;
    }
    if (species2 > highestCount){
        highestCount = species2;
        predominant = 2;
    }
    if (species3 > highestCount)  {
        highestCount = species3;
        predominant = 3;
    }
    if (species4 > highestCount) {
        highestCount = species4;
        predominant = 4;
    }

    return predominant;
}

void World::nextGeneration(Cell nextCells[ROWS][COLUMNS])
{
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
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
}