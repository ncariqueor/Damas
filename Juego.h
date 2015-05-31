/* 
 * File:   Juego.h
 * Author: nelson
 *
 * Created on 27 de mayo de 2015, 16:52
 */

#ifndef JUEGO_H
#define	JUEGO_H
#include "Tablero.h"
#include "Jugador.h"

class Juego {
public:
    Tablero *tablero;
    Jugador *blanco;
    Jugador *negro;
    bool player;
    
    Juego();
};

#endif	/* JUEGO_H */

