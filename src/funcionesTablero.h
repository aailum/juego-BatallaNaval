
#ifndef FUNCIONESTABLERO_H_
#define FUNCIONESTABLERO_H_


#include "parEntero.h"
#include "matrices.h"
#include "funcionesGenerales.h"

/*Funcion que inicia los 5 tableros: el general, los 2 de los jugadores, el tablero que muestra las posiciones y un mini
 * tablero de 3x3 para que los jugadores elijan donde mover a sus soldados*/
void iniciar_tableros(Matriz tablero, Matriz tablero1, Matriz tablero2, Matriz muestra, MatrizMini opciones);

/*Funcion encargada de imprimir por pantalla los tableros de 10x10*/
void imprimirTablero(Matriz tablero);

/*Funcion engargada de emprimir por pantalla la matriz de 3x3 donde se muestran las opciones de movimieto*/
void imprimirOpciones(MatrizMini m);

/**/
void sacarDelTablero(Matriz &tablero, parEntero movimiento);

/**/
bool verificarCasilla(Matriz tablero, parEntero posicion);

/*Cambia el valor de una casilla*/
void cambiarValorCasilla(Matriz &tablero, parEntero posicion, char valor);


/**/
void disparo(parEntero disparo, Matriz &tablero, int &vidas, Matriz &tableroContrario);


/**/
int validarMovimiento(parEntero movimiento, Matriz tablero);


/**/
void procesamiento(Matriz &tableroGeneral, Matriz &tablero, Matriz &tableroContrario, parEntero movimiento, parEntero posicion, int turno, int &vidas1, int &vidas2);

/**/
void moverSoldado(Matriz &tableroGeneral, Matriz &tablero, Matriz &tableroContrario, int turno, int opcion, parEntero movimiento, parEntero posicion, int &vidas1, int &vidas2);

/**/
void movimientoSoldado(Matriz &tableroGeneral, Matriz &tableroPropio, Matriz &tableroContrario, int turno, MatrizMini opciones, int &vidas1, int &vidas2);







#endif /* FUNCIONESTABLERO_H_ */
