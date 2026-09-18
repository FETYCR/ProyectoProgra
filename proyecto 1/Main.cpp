#include <iostream>
#include <string>
#include "Cell.h"
#include "ConsoleView.h"
#include "World.h"


int readCin() {
	int value = 0;
	bool invalid;
	
	do {
		std::cin >> value;
		invalid = std::cin.fail();

		if (invalid) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Numero invalido, intantalo de nuevo: ";
		}

	} while (invalid);
	return value;
}

int main(){

	srand(time(0));
	const int MIN = 10;
	const int MAX = 100;
	int cols = 0, rows = 0;
	ConsoleView consoleView;
	bool valid = false;

	std::cout << "Digite el tamanio del tablero (minimo 10x10)" << std::endl;
	do{
	valid = true;
	std::cout << "Tamanio de las filas: ";
	rows = readCin();
		if (rows < MIN || rows > MAX) {
			std::cout << "Tiene que ser un numero entre 10 y 100" << std::endl;
			std::cout << "Intentalo de nuevo..." << std::endl;
			valid = false;
			std::cout << std::endl;
		}
		

	} while (!valid);

	do {
		valid = true;
		std::cout << "\nTamanio de las columnas: ";
		cols = readCin();
		if (cols< MIN || cols > MAX) {
			std::cout << "Tiene que ser un numero igual a 10 o mayor" << std::endl;
			std::cout << "Intentalo de nuevo..." << std::endl;
			valid = false;
			std::cout << std::endl;
		}
		

	} while (!valid);


	World world(rows, cols);
	int option;
	bool loop = true;

	do {
		consoleView.printMenu();
		option = readCin();

		if (option == 0) {
			loop = false;
		}

		switch (option) {
			
			case 1:{
				int row = 0, col = 0, specie = 0;
				std::cout << "Digite la posicion de la fila donde desea ingresar la especie: ";
				row = readCin();
				std::cout << "\nDigite la posicion de la columna donde desea ingresa la especie: ";
				col = readCin();
				std::cout << std::endl;

				std::cout << "1. Asuras" << std::endl;
				std::cout << "2. Humanos" << std::endl;
				std::cout << "3. Enanos" << std::endl;
				std::cout << "4. Elfos" << std::endl;
				std::cout << "Digite la specie que desa ingresar: ";
				specie = readCin();
				std::cout << std::endl;
				
				bool valid = world.seedManual(row, col, specie);
				if (!valid) {
					std::cout << "Fila o columna fuera del limite o epecie invalida" << std::endl;
					std::cout << "Porfavor intentalo de nuevo...";
					std::cout << std::endl;
					
				}else {
					consoleView.printWorld(world);
					std::cout << std::endl;
				}

			break;
			}
			case 2: {

				float density = 0;
				bool invalid;
				std::cout << "Digite que tan lleno quieres el tablero de especies aleatorias" << std::endl;
				std::cout << "Digite un numero entre 0.1 y 1: ";

				do {
					std::cin >> density;
					invalid = std::cin.fail();
					if (invalid) {
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						std::cout << "Numero invalido, intentalo de nuevo: ";
					}
				} while (invalid);

				std::cout << std::endl;

				bool valid = world.seedRandom(density);
				if (!valid) {
					std::cout << "Digitaste un nuemero fuera del rango solicitado" << std::endl;
					std::cout << "Vuelve a intentarlo con un numero entre 0.1 y 1...";
					std::cout << std::endl;
				}else {
					consoleView.printWorld(world);
					std::cout << std::endl;
				}
					
			break;
			}
			case 3: {
				int row = 0, col = 0, specie = 0;

				std::cout << "Digite la posicion de la fila donde quieres que este el patron: ";
				row = readCin();
				std::cout << "\nDigite la posicion de la columna donde quieres que este el patron: ";
				col = readCin();
				std::cout << std::endl;

				std::cout << "1. Asuras" << std::endl;
				std::cout << "2. Humanos" << std::endl;
				std::cout << "3. Enanos" << std::endl;
				std::cout << "4. Elfos" << std::endl;
				std::cout << "Digite la specie que desa ingresar: ";
				specie = readCin();
				std::cout << std::endl;

				bool valid = world.seedPattern(row, col, specie);
				if (!valid) {
					std::cout << "Fila o columna fuera del limite o epecie invalida" << std::endl;
					std::cout << "Porfavor intentalo de nuevo...";
					std::cout << std::endl;
				}else{
					consoleView.printWorld(world);
					std::cout << std::endl;
				}
			break;
			}
			case 4:{
				int generations = 0;
				std::cout << "Digite la cantidad de generacioens que desesa avanzar: ";
				generations = readCin();
				
				
				for (int i = 0; i < generations; i++) {
					world.nextGeneration();
				}

				std::cout << "\nSe avanzaron (" << generations << ") generaciones..." << std::endl;
				consoleView.printWorld(world);
				std::cout << std::endl;

			break;
			}
			case 5: {
				std::cout << "Cargando mundo..." << std::endl;
				consoleView.printWorld(world);
				std::cout << std::endl;
			break;
			}
			case 6: {
				std::cout << "Mostrando estadisticas del mundo..." << std::endl;
				consoleView.printStats(world);
				std::cout << std::endl;
			break;
			}
			
			case 0: {
				loop = false;
				std::cout << "Saliendo del programa..." << std::endl;
				break;
			}

			default:
			std::cout << "Opcion invalida" << std::endl;
			break;
		}

	} while (loop);

	return 0;
}

