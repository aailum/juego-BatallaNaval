
#ifndef FUNCIONESGENERALES_H_
#define FUNCIONESGENERALES_H_


#include "matrices.h"
#include "parEntero.h"
#include "funcionesTablero.h"

/*Compara la cantidad de vidas de cada jugador y devuelve quien gano*/
void verificarGanador(int vidas1, int vidas2);

/**/
parEntero pedirPosicion(parEntero posicion);

/**/
void titulo();


/**/
void insertarPosicion(parEntero posicion, Matriz &tablero, char ficha);


/**/
void ingresoSoldados(parEntero posicion, Matriz &tablero, char ficha);

/**/
int turno(int jugador);


/*Pide una opcion, un numero del 1 al 9*/
int pedirOpcion(int opcion);

/**/
bool preguntarMovimiento();


/**/
parEntero pedirPosicionAcambiar(parEntero posicion);



void verificarTurno(Matriz &tablero, parEntero movimiento, int turno);

/**/
bool verificarVidas(int vidas);

/**/
void controlVidas(int turno, int vidas1, int vidas2, int &fin);






#endif /* FUNCIONESGENERALES_H_ */
