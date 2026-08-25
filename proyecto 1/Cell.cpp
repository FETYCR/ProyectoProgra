#include "Cell.h"

Cell::Cell() {
	species = 0;
}

int Cell::getSpecies() const {
	return species;
}

void Cell::setSpecies(int newSpecies) {
	species = newSpecies;
}

bool Cell::isAlive() const {
	if (species == 0)
	{
		return false;
	}

	return true;
}

