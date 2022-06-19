#include <iostream>
#include "funcionesTablero.h"

using namespace std;



void iniciar_tableros(Matriz tablero, Matriz tablero1, Matriz tablero2, Matriz muestra, MatrizMini opciones){
    for(int i=0; i< TAMANIO; i++){
        for(int j=0; j < TAMANIO; j++){
            tablero[i][j] = ' ';
        }

    }

    for(int i=0; i< TAMANIO; i++){
        for(int j=0; j < TAMANIO; j++){
            tablero1[i][j] = ' ';
        }

    }

    for(int i=0; i< TAMANIO; i++){
        for(int j=0; j < TAMANIO; j++){
            tablero2[i][j] = ' ';
        }

    }


    for(int i=0; i< TAMANIO; i++){
        for(int j=0; j < TAMANIO; j++){
            muestra[i][j] = 'O';
        }

    }

    muestra[0][0] = '0';
    muestra[0][1] = '1';
    muestra[0][2] = '2';
    muestra[0][3] = '3';
    muestra[0][4] = '4';
    muestra[0][5] = '5';
    muestra[0][6] = '6';
    muestra[0][7] = '7';
    muestra[0][8] = '8';
    muestra[0][9] = '9';
    muestra[1][0] = '1';
    muestra[2][0] = '2';
    muestra[3][0] = '3';
    muestra[4][0] = '4';
    muestra[5][0] = '5';
    muestra[6][0] = '6';
    muestra[7][0] = '7';
    muestra[8][0] = '8';
    muestra[9][0] = '9';

    for(int i=0; i< 3*3 ; i++){
        opciones[i/3][i%3] = i+1;
    }


}

void imprimirTablero(Matriz tablero){
   for(int i=0; i<TAMANIO ;i++){
        for (int j=0; j<TAMANIO ; j++){
            cout<<' '<< tablero[i][j]<<' ';
        }
    cout<<'\n';
        }
    cout<<'\n';
}


void imprimirOpciones(MatrizMini m){
    for(int i=0; i<3 ;i++){
        for (int j=0; j<3 ; j++){
            cout<<' '<< m[i][j]<<' ';
        }
    cout<<'\n';
        }
    cout<<'\n';
}


void sacarDelTablero(Matriz &tablero, parEntero movimiento){
    tablero[movimiento.f][movimiento.c] = ' ';
}

bool verificarCasilla(Matriz tablero, parEntero posicion){ //verifica si la casilla esta libre en el tablero
    int a = posicion.f;
    int b = posicion.c;

    if(tablero[a][b] == ' '){
        return true;
    }else{
        return false;
    }
}


void cambiarValorCasilla(Matriz &tablero, parEntero posicion, char valor){
    tablero[posicion.f][posicion.c] = valor;
}

void disparo(parEntero disparo, Matriz &tablero, int &vidas, Matriz &tableroContrario){
    if(verificarCasilla(tableroContrario, disparo) == true){
        cout<<"\nVacio\n\n"; //avisa que no se elimino nada
        cambiarValorCasilla(tablero, disparo, 'X'); //cambia en el tablero principal
        cambiarValorCasilla(tableroContrario, disparo, 'X'); //cambia en el tablero del jugador contrario
        imprimirTablero(tablero);

    }else{
         cout<<"\nSe ha eliminado un soldado contrario!\n\n"; //avisa que se mato a un soldado contrario
        cambiarValorCasilla(tablero, disparo, 'X'); //cambia en el tablero principal
        cambiarValorCasilla(tableroContrario, disparo, 'X'); //cambia en el tablero del jugador contrario
        vidas--;
        imprimirTablero(tablero);
    }

}



int validarMovimiento(parEntero movimiento, Matriz tablero){
    int a = movimiento.f;
    int b = movimiento.c;
    if(tablero[a][b] == ' '){
        return 0;
    }else if(tablero[a][b] == 'X'){
        return 1;
    }else{
        return 2;
    }
}

void procesamiento(Matriz &tableroGeneral, Matriz &tablero, Matriz &tableroContrario, parEntero movimiento, parEntero posicion, int turno, int &vidas1, int &vidas2){
    if(validarMovimiento(movimiento, tableroContrario) == 0){
                sacarDelTablero(tablero, posicion);
                verificarTurno(tablero, movimiento, turno);
    }else{
        if(validarMovimiento(movimiento, tablero) == 1){
            cout<<"Casilla inactiva\n";

        }else{

            cout<<"\nSu soldado cayo en la misma casilla que un soldado contrario, ambos pierden sus soldados. \n";
            vidas1--;
            vidas2--;
            sacarDelTablero(tablero, posicion);
            cambiarValorCasilla(tablero, movimiento, 'X');
            cambiarValorCasilla(tableroContrario, movimiento, 'X');
            cambiarValorCasilla(tableroGeneral, movimiento, 'X');
        }

    }

}

void moverSoldado(Matriz &tableroGeneral, Matriz &tablero, Matriz &tableroContrario, int turno, int opcion, parEntero movimiento, parEntero posicion, int &vidas1, int &vidas2){
    switch(opcion){
		case 0:
            cout<<"No se realiza ningun movimiento";
			break;
		case 1:
            movimiento.f = posicion.f - 1;
            movimiento.c = posicion.c - 1;
            procesamiento(tableroGeneral, tablero, tableroContrario, movimiento, posicion, turno, vidas1, vidas2);

            break;

		case 2:
            movimiento.f = posicion.f - 1;
            movimiento.c = posicion.c;
            procesamiento(tableroGeneral, tablero, tableroContrario, movimiento, posicion, turno, vidas1, vidas2);

			break;

        case 3:
            movimiento.f = posicion.f - 1;
            movimiento.c = posicion.c + 1;
            procesamiento(tableroGeneral, tablero, tableroContrario, movimiento, posicion, turno, vidas1, vidas2);
            break;

        case 4:
            movimiento.f = posicion.f;
            movimiento.c = posicion.c - 1;
            procesamiento(tableroGeneral, tablero, tableroContrario, movimiento, posicion, turno, vidas1, vidas2);
            break;

        case 5:
            cout<<"No se realiza ningun movimiento";
            break;

        case 6:
            movimiento.f = posicion.f;
            movimiento.c = posicion.c + 1;
            procesamiento(tableroGeneral, tablero, tableroContrario, movimiento, posicion, turno, vidas1, vidas2);
            break;

        case 7:
            movimiento.f = posicion.f + 1;
            movimiento.c = posicion.c - 1;
            procesamiento(tableroGeneral, tablero, tableroContrario, movimiento, posicion, turno, vidas1, vidas2);
            break;

        case 8:
            movimiento.f = posicion.f + 1;
            movimiento.c = posicion.c;
            procesamiento(tableroGeneral, tablero, tableroContrario, movimiento, posicion, turno, vidas1, vidas2);
            break;

        case 9:
            movimiento.f = posicion.f + 1;
            movimiento.c = posicion.c + 1;
            procesamiento(tableroGeneral, tablero, tableroContrario, movimiento, posicion, turno, vidas1, vidas2);
            break;
}
}

void movimientoSoldado(Matriz &tableroGeneral, Matriz &tableroPropio, Matriz &tableroContrario, int turno, MatrizMini opciones, int &vidas1, int &vidas2){
    int opcion, opcionElegida;
    parEntero movimiento;
    parEntero posicionActual;
    if(preguntarMovimiento() == true){
        cout<<"\nLos movimientos solo se pueden hacer a las casillas horizontales, verticales o diagonales que estan pegadas a la casilla donde se esta parado.\n";
        posicionActual = pedirPosicionAcambiar(posicionActual);
        imprimirOpciones(opciones);
        opcionElegida = pedirOpcion(opcion);
        moverSoldado(tableroGeneral, tableroPropio, tableroContrario, turno, opcionElegida, movimiento, posicionActual, vidas1, vidas2);
        cout<<"\nTablero propio actualizado.\n";
        imprimirTablero(tableroPropio);

    }
}



