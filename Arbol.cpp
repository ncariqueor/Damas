
#include "Arbol.h"

Arbol::Arbol(){

}

Arbol::Arbol(const Tablero& t, bool jugador){
    hijos = new list<Arbol>();
    tablero = t;
    player = jugador;
}

void Arbol::brote(bool jugador){
    list<Arbol>::iterator pos = hijos->begin();
    
    while(pos != hijos->end()){
        pos->brote(!jugador);
        pos++;
    }
    
    if(hijos->empty()){
        list<Tablero> *moves = &tablero.movimientos(jugador);
        list<Tablero>::iterator pos2 = moves->begin();
        while(pos2 != moves->end()){
            Arbol *aux = new Arbol(*pos2, jugador);
            hijos->push_back(*aux);
            pos2++;
        }
    }
}

double Arbol::minimax(bool jugador){
    if(hijos->empty())
        return tablero.valorTablero();
    
    if(jugador){
        double a = 0;
        list<Arbol>::iterator pos = hijos->begin();
        while(pos != hijos->end()){
            a = (a > pos->minimax(!jugador)? a : pos->minimax(!jugador));
            pos++;
        }
        return a;
    }
    else{
        double a = 999999;
        list<Arbol>::iterator pos = hijos->begin();
        while(pos != hijos->end()){
            a = (a < pos->minimax(!jugador)? a : pos->minimax(!jugador));
            pos++;
        }
        return a;
    }
}

Arbol& Arbol::movimiento(bool jugador){
    
    Arbol *arbol = new Arbol();
    if(hijos->empty()){
        return *arbol;
    }
    
    Arbol *mejor;
    if(jugador){
        double a = 0;
        list<Arbol>::iterator pos = hijos->begin();
        while(pos != hijos->end()){
            double valor = pos->minimax(!jugador);
            if(mejor == NULL || valor > a){
                a = valor;
                mejor = &*pos;
            }
            pos++;
        }
    }else{
        double a = 9999;
        list<Arbol>::iterator pos = hijos->begin();
        while(pos != hijos->end()){
            double valor = pos->minimax(!jugador);
            if(mejor == NULL || valor < a){
                a = valor;
                mejor = &*pos;
            }
            pos++;
        }
    }
    return *mejor;
}
