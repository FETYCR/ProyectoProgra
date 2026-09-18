#include "Specie.h"

Specie::Specie(){
    this -> index = 0;
    this -> survivalCount = 0;
    for (int i = 0; i < 8; i++) {
        survivalSet[i] = 0;
    }
}

void Specie::setName(std::string n){
    
    name = n;
}

std::string Specie::getName() const{

    return name;
}

void Specie::setIndex(int i){

    index = i;
}

int Specie::getIndex() const{

    return index;
}

void Specie::setSurvivalSet(int values[], int count){

    for(int i = 0; i < count; i++){
        survivalSet[i] = values[i];
    }
    survivalCount = count;
}

bool Specie::survives(int aliveNei) const{

    for(int i = 0; i < survivalCount; i++){
        if(survivalSet[i] == aliveNei){
            return true;
        }
    }
    return false;
}

int Specie::getSurvivalValue(int position) const{

    return survivalSet[position];
}

int Specie::getSurvivalCount() const{
    
    return survivalCount;
}
