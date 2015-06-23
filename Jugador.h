/* 
 * File:   Jugador.h
 * Author: nelson
 *
 * Created on 3 de junio de 2015, 21:54
 */

#ifndef JUGADOR_H
#define	JUGADOR_H
#include "Arbol.h"
#include "Tablero.h"

using namespace std;

class Jugador {
public:
    Arbol miArbol;
    bool jugador;
    int profundidad;
    
    Jugador(const Tablero& t, int prof, bool player);
    Tablero& movimiento();
    void actualizar(const Tablero& t, bool jugador);
    Arbol& get(int i);
    void mostrarHijos();
};

#endif	/* JUGADOR_H */

