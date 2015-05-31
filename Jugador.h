/* 
 * File:   Jugador.h
 * Author: nelson
 *
 * Created on 27 de mayo de 2015, 20:27
 */

#ifndef JUGADOR_H
#define	JUGADOR_H
#include "Arbol.h"
#include "Tablero.h"

class Jugador {
public:
    Arbol *miArbol;
    bool jugador;
    int profundidad;
    
    Jugador(const Tablero& t, int, bool);
    Tablero& movimiento();
    void actualizar(Tablero, bool);
    Arbol& get(int);
private:

};

#endif	/* JUGADOR_H */

