#include <iostream>
#include "funcionesGenerales.h"

using namespace std;

void verificarGanador(int vidas1, int vidas2){
        if(vidas1 > vidas2){
            cout<<"GANADOR: jugador 1";
        }else{
             cout<<"GANADOR: jugador 2";
        }
    }


parEntero pedirPosicion(parEntero posicion){
    cout<<"Ingrese posicion de fila y columna. \n";
    cout<<"Fila: ";
    cin>> posicion.f;
    cout<<"Columna: ";
    cin>> posicion.c;

    return posicion;
}

void titulo(){                                                          //TITULO
	std::cout<<"      Batalla Campal\n\n"<<std::endl;
}

void insertarPosicion(parEntero posicion, Matriz &tablero, char ficha){
        tablero[posicion.f][posicion.c] = ficha;
    }

void ingresoSoldados(parEntero posicion, Matriz &tablero, char ficha) {    //INGRESO SOLDADOS
    for(int i=0; i<3; i++){
        posicion = pedirPosicion(posicion);
        insertarPosicion(posicion, tablero, ficha);
        imprimirTablero(tablero);
    }

}




int turno(int jugador){
	int turno;
	int aux = jugador%2;

	if (aux == 1){
		turno = 1;
	}else {
		turno = 2;
	}
	return turno;
}


int pedirOpcion(int opcion){
    cout<<"Ingrese su opcion(el 5 es su posicion actual): ";
    cin>> opcion;
    return opcion;
}

bool preguntarMovimiento(){
    char respuesta;
    cout<<"Desea mover un soldado? s/n: \n";
    cin>> respuesta;
    if(respuesta == 's'){
        return true;
    }else{
        return false;
    }
}


parEntero pedirPosicionAcambiar(parEntero posicion){
    cout<<"Ingrese posicion que desea cambiar.\n";
    cout<< "Fila: ";
    cin>> posicion.f;
    cout<< "Columna: ";
    cin>> posicion.c;
    return posicion;
}


void verificarTurno(Matriz &tablero, parEntero movimiento, int turno){
    if(turno == 1){
		cambiarValorCasilla(tablero, movimiento, '1');
    }else{
        cambiarValorCasilla(tablero, movimiento, '2');
        }
}


bool verificarVidas(int vidas){
    if(vidas == 0){
        return true;
    }else{
        return false;
    }
}


void controlVidas(int turno, int vidas1, int vidas2, int &fin){
    if(turno == 1){
        if(verificarVidas(vidas1) == true){
        fin = 0;
        }
    }else{
        if(verificarVidas(vidas2) == true){
            fin = 0;
        }
    }

}





