/* 
 * File:   Arbol.h
 * Author: nelson
 *
 * Created on 27 de mayo de 2015, 16:57
 */

#ifndef ARBOL_H
#define	ARBOL_H
#include "Tablero.h"
#include <iostream>
#include <list>
using namespace std;

class Arbol {
public:
    list <Arbol> *hijos;
    Tablero tablero;
    bool player;
    
    Arbol();
    Arbol(const Tablero& t, bool);
    void brote(bool);
    double minimax(bool);
    Arbol& movimiento(bool);
    
};

#endif	/* ARBOL_H */

