/* 
 * File:   Jugador.cpp
 * Author: nelson
 * 
 * Created on 27 de mayo de 2015, 20:27
 */

#include "Jugador.h"

Jugador::Jugador(const Tablero& t, int p, bool jugador){
    miArbol = new Arbol(t, jugador);
    this->jugador = jugador;
    profundidad = p;
    while(p > 0){
        miArbol->brote(jugador);
        p--;
    }
}

Tablero& Jugador::movimiento(){
    return miArbol->movimiento(jugador).tablero;
}

void Jugador::actualizar(Tablero t, bool jugador){
    bool encendido = false;
    int a = 0;
    list<Arbol>::iterator pos= miArbol->hijos->begin();
    
    while(a < miArbol->hijos->size() && !encendido){
        if(get(a).tablero.tablero == t.tablero){
            *miArbol = get(a);
            encendido = true;
        }
        a++;
    }
    
    if(!encendido){
        miArbol = new Arbol(t, jugador);
        for(int i=0;i<profundidad-1;i++){
            miArbol->brote(!jugador);
        }
    }
    miArbol->brote(!jugador);
}

Arbol& Jugador::get(int j){
    int i = 0;
    list<Arbol>::iterator pos = miArbol->hijos->begin();
    while(pos != miArbol->hijos->end() && i != j){
        pos++;
        i++;
    }
    return *pos;
}
