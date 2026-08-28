#pragma once
#include <string>




class Specie {

private:
	std::string name;
	int index;

	int survivalSet[8];
	int survivalCount;



public:

	Specie();
	void setName(std::string n);
	std::string getName() const;

	void setIndex(int i);
	int getIndex() const;

	void setSurvivalSet(int values[], int count);
	bool survives(int aliveNeighbors) const;
	int getSurvivalValue(int position) const;
	int getSurvivalCount() const;

};

