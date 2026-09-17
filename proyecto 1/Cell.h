    #pragma once

using namespace std;

class Cell
{
private:
    int species;

public:

    Cell();

    int getSpecies()const;
    void setSpecies(int newSpecies);
    bool isAlive()const;

};