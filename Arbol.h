/* 
 * File:   Arbol.h
 * Author: nelson
 *
 * Created on 3 de junio de 2015, 21:12
 */

#ifndef ARBOL_H
#define	ARBOL_H
#include "Tablero.h"
#include <list>
#include <iostream>

using namespace std;

class Arbol {
public:
    list <Arbol> hijos;
    bool player;
    Tablero tab;
    
    Arbol();
    Arbol(const Tablero& t, bool jugador);
    void Brote(bool jugador);
    double minimax(bool jugador);
    Arbol& movimiento(bool jugador);
    Arbol& operator =(const Arbol& ab);
    
};

#endif	/* ARBOL_H */

