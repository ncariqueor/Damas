/* 
 * File:   JugadorHumano.h
 * Author: nelson
 *
 * Created on 18 de junio de 2015, 9:40
 */

#ifndef JUGADORHUMANO_H
#define	JUGADORHUMANO_H
#include <list>
#include <ctype.h>
#include <stdio.h>
#include "Tablero.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <unistd.h>
using namespace std;

class JugadorHumano {
public:
    JugadorHumano(bool player);
    Tablero movimiento(const Tablero& t);
    
    bool jugador;
};

#endif	/* JUGADORHUMANO_H */

