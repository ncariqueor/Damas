/* 
 * File:   Juego.cpp
 * Author: nelson
 * 
 * Created on 27 de mayo de 2015, 16:52
 */

#include "Juego.h"

Juego::Juego() {
    tablero = new Tablero();
    
    player = true;
    blanco = new Jugador(*tablero,2,player);
    
    negro = new Jugador(*tablero,6,!player);
    
    
    while(!tablero->juegoTerminado(player)){
        *tablero = (player? blanco->movimiento() : negro->movimiento());
        blanco->actualizar(*tablero, player);
        negro->actualizar(*tablero,player);
        player = !player;
    }
    tablero->mostrar();
        
}

