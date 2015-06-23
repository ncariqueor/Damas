/* 
 * File:   Arbol.cpp
 * Author: nelson
 * 
 * Created on 3 de junio de 2015, 21:12
 */

#include "Arbol.h"
Arbol::Arbol(){
    hijos;
    player;
    tab;
}

Arbol::Arbol(const Tablero& t, bool player) {
    hijos = list<Arbol>();
    this->player = player;
    tab.operator =(t);
}

void Arbol::Brote(bool jugador){
    
    list<Arbol>::iterator ini = hijos.begin();
    list<Arbol>::iterator fin = hijos.end();
    while(ini != fin){
        ini->Brote(!jugador);
        ini++;
    }
    
    if(hijos.empty()){
        list<Tablero> moves;
        moves.operator =(tab.getMovimiento(jugador));
        
        list<Tablero>::iterator ini = moves.begin();
        list<Tablero>::iterator fin = moves.end();
        
        while(ini != fin){
            hijos.push_back(Arbol(*ini, jugador));
            ini++;
        }
    }
}

double Arbol::minimax(bool jugador){
    if(hijos.empty()){
        double tmp = tab.valorTablero();
        if(tab.comer > 0){
            if(tmp>0)
                return tmp *=2;
            else
                return tmp *=-2;
        }
        if(tab.comer < 0){
            if(tmp>0)
                return tmp *=-2;
            else
                return tmp *=2;
        }
        
        return tmp;
    }
    
    if(jugador){
        double max = 0;
        list<Arbol>::iterator ini = hijos.begin();
        list<Arbol>::iterator fin = hijos.end();
        
        while(ini != fin){
            max = (max < ini->minimax(!jugador)? ini->minimax(!jugador) : max);
            ini++;
        }
        return max;
    }else{
        double min = 999;
        list<Arbol>::iterator ini = hijos.begin();
        list<Arbol>::iterator fin = hijos.end();
        
        while(ini != fin){
            min = (min > ini->minimax(!jugador)? ini->minimax(!jugador) : min);
            ini++;
        }
        return min;
    }
}

Arbol& Arbol::movimiento(bool jugador){
    
    if(hijos.empty()){
        return *this;
    }
    
    Arbol *tmp;
    tmp = this;
    if(jugador){
        double max = 0;
        list<Arbol>::iterator ini = hijos.begin();
        list<Arbol>::iterator fin = hijos.end();
        
        while(ini != fin){
            double valor = ini->minimax(!jugador);
            if(tmp == this || valor >= max){
                max = valor;
                tmp = &*ini;
            }
            ini++;
        }
    }else{
        double min = 999;
        list<Arbol>::iterator ini = hijos.begin();
        list<Arbol>::iterator fin = hijos.end();
        
        while(ini != fin){
            double valor = ini->minimax(!jugador);
            if(tmp == this || valor <= min){
                min = valor;
                tmp = &*ini;
            }
            ini++;
        }
    }
    return *tmp;
    
}

Arbol& Arbol::operator =(const Arbol& ab){
    if(this != &ab){
        this->hijos.operator =(ab.hijos);
        this->tab.operator =(ab.tab);
        this->player = ab.player;
    }
    return *this;
}



