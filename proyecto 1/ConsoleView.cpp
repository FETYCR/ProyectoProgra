#include "ConsoleView.h"
#include <iostream>

void ConsoleView::printWorld(const World& world){
	char symbol[5] = { '.', '#', '$','@','&' };

	for (int i = 0; i < world.getRows(); i++) {
		for (int j = 0; j < world.getCols(); j++) {
			std::cout << symbol[world.getCellSpecies(i, j)];
		}
		std::cout << std::endl;
	}
}

void ConsoleView::printStats(const World& world){
	std::cout << "Generacion: " << world.getGeneration() << std::endl;
	
	std::cout << "Asuras vivos: " << world.countPopulation(1) << std::endl;
	std::cout << "Humanos vivos: " << world.countPopulation(2) << std::endl;
	std::cout << "Enanos vivos: " << world.countPopulation(3) << std::endl;
	std::cout << "Elfos vivos: " << world.countPopulation(4) << std::endl;
	
	std::cout << "Total vivas: " << world.counterAliveCells() << std::endl;

}

void ConsoleView::printMenu(){
	
	std::cout << "---- MENU ----" << std::endl;

	std::cout << "1. Siembra manual" << std::endl;
	std::cout << "2. Siembra aleatoria" << std::endl;
	std::cout << "3. Colocar patron" << std::endl;
	std::cout << "4. avanzar generacion" << std::endl;
	std::cout << "5. Ver mundo" << std::endl;
	std::cout << "6. Estadisticas" << std::endl;
	std::cout << "0. Salir" << std::endl;

	std::cout << "Escoja una opcion: ";
}

