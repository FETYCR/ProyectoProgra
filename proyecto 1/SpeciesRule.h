#pragma once
#include "Specie.h"



class SpeciesRule{

	private :
		Specie species[4];
		int tieBreaker;
		int birthSet[8];
		int birthCount;

	public :

        SpeciesRule();
        bool canBirth(int aliveNeighbors) const;
        Specie getSpecies(int index) const;
        void setBirthSet(int values[], int count);
        
        void setTieBreaker(int tie);
        int getTieBreaker() const;
        
        int predominantSpecies(int neighborCountBySpecies[4]) const;
        void loadOfficialConfig();

        
};

