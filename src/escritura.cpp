#include "escritura.h"
#include <fstream>

using namespace std;

void grabarProgreso(Matriz tablero1, Matriz tablero2){

	std::ofstream archivo;
	archivo.open("EstadoTablero1.txt", ios::out | ios::app);

    archivo<<"\nTablero\n";
	for(int i=0; i<TAMANIO ;i++){
        for (int j=0; j<TAMANIO ; j++){
            archivo<<' '<< tablero1[i][j]<<' ';
        }
    archivo<<"\n";
    }

	archivo.close();

	archivo.open("EstadoTablero2.txt", ios::out | ios::app);

    archivo<<"\nTablero\n";
    for(int i=0; i<TAMANIO ;i++){
        for (int j=0; j<TAMANIO ; j++){
            archivo<<' '<< tablero2[i][j]<<' ';
        }
    archivo<<"\n";

    }

    archivo.close();
	return;
}




