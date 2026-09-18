#include "Specie.h"
#include "SpeciesRule.h"

SpeciesRule::SpeciesRule(){

    this -> tieBreaker = 0;
    this -> birthCount = 0;
    for (int i = 0; i < 8; i++) {
        birthSet[i] = 0;
    }
}

bool SpeciesRule::canBirth(int aliveNeighbors) const{

    for(int i = 0; i < birthCount; i++){
        if(birthSet[i] == aliveNeighbors){
            return true;
        }
    }
    return false;
}

Specie SpeciesRule::getSpecies(int index) const{
    
    return species[index]; 
}

void SpeciesRule::setBirthSet(int values[], int count){

    for(int i = 0; i < count; i++){
        birthSet[i] = values[i];

    }
    birthCount = count;

}

void SpeciesRule::setTieBreaker(int t){
    
    tieBreaker = t;
}

int SpeciesRule::getTieBreaker() const{
    
    return tieBreaker;
}

int SpeciesRule::predominantSpecies(int neighborCount[4]) const{
    
    int speBigger = neighborCount[0];
    for(int i = 1; i < 4; i++){
        if(neighborCount[i] > speBigger){
            speBigger = neighborCount[i];
        }

    }

    for(int i = 0; i < 4; i++){
        if(neighborCount[i] == speBigger){
            return i;
        }
    }


    return 0;
}

void SpeciesRule::loadOfficialConfig(){

species[0].setName("Asuras");
species[0].setIndex(0);
int survivalS1[] = {1,2};
species[0].setSurvivalSet(survivalS1, 2);

species[1].setName("Humanos");
species[1].setIndex(1);
int survivalS2[]= {2,3};
species[1].setSurvivalSet(survivalS2, 2);

species[2].setName("Enanos");
species[2].setIndex(2);
int survivalS3[] = {2};
species[2].setSurvivalSet(survivalS3, 1);

species[3].setName("Elfos");
species[3].setIndex(3);
int survivalS4[] = {1,2,3};
species[3].setSurvivalSet(survivalS4, 3);

int birthValues[] = {2,3};
setBirthSet(birthValues, 2);
int tieBreak = 0;
setTieBreaker(tieBreak);
}
