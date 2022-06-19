#include <iostream>
#include "funcionJuego.h"
using namespace std;

void juego(){
    Matriz tablero, tablero1, tablero2, tableroMuestra;
    MatrizMini opciones;
    parEntero posicion;
    int fin = 1, j = 1;
    int turnoJugador;
    int vidasJ1 = 3, vidasJ2 = 3;
    char fichaJ1 = '1', fichaJ2 = '2';

    titulo();
    iniciar_tableros(tablero, tablero1, tablero2, tableroMuestra, opciones);
    cout<<"Posiciones del tablero: "<<"\n";
    imprimirTablero(tableroMuestra);
    cout<<"\nIngreso jugador 1\n";
    ingresoSoldados(posicion, tablero1, fichaJ1);
    cout<<"\nIngreso jugador 2\n";
    ingresoSoldados(posicion, tablero2, fichaJ2);
    grabarProgreso(tablero1, tablero2);

    cout<<"\nCOMIENZA EL JUEGO!"<<'\n';
    //empieza el juego, muestra el tablero vacio para que se elijan posiciones.




    while (fin == 1){ //
        turnoJugador = turno(j);
        std::cout<<"TURNO DEL JUGADOR: "<< turnoJugador <<std::endl;

        if(turnoJugador == 1){
            cout<<"VIDAS JUGADOR 1: "<<vidasJ1<<"\n";
            cout<<"\n";
            posicion = pedirPosicion(posicion);
            disparo(posicion, tablero, vidasJ2, tablero2);
            movimientoSoldado(tablero, tablero1, tablero2, turnoJugador, opciones, vidasJ1, vidasJ2);


        }else{
            cout<<"VIDAS JUGADOR 2: "<<vidasJ2<<'\n';
            cout<<"\n";
            posicion = pedirPosicion(posicion);
            disparo(posicion, tablero, vidasJ1, tablero1);
            movimientoSoldado(tablero, tablero2, tablero1, turnoJugador, opciones, vidasJ1, vidasJ2);

        }

        j++;
        controlVidas(turnoJugador, vidasJ1, vidasJ2, fin);
        grabarProgreso(tablero1, tablero2);

    }
    verificarGanador(vidasJ1, vidasJ2);

    return;
}








