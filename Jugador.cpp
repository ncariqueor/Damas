/* 
 * File:   Jugador.cpp
 * Author: nelson
 * 
 * Created on 3 de junio de 2015, 21:54
 */

#include "Jugador.h"

Jugador::Jugador(const Tablero& t, int prof, bool player) {
    miArbol = Arbol(t, player);
    jugador = player;
    profundidad = prof;
    while(prof>0){
        miArbol.Brote(true);
        prof--;
    }
}

Tablero& Jugador::movimiento(){
    return miArbol.movimiento(jugador).tab;
}

void Jugador::actualizar(const Tablero& t, bool jugador){
    
    bool switched = false;
    int a = 0;
    
    int tamanio = miArbol.hijos.size();
    
    while((a < tamanio) && !switched){
            if(get(a).tab.tablero == t.tablero){
                miArbol = get(a);
                switched = true;
            }
        a++;
    }
    
    if(!switched){
        miArbol = Arbol(t, jugador);
        for(int i=0;i<profundidad-1;i++){
            miArbol.Brote(!jugador);
        }
    }
    miArbol.Brote(!jugador);
}

Arbol& Jugador::get(int i){
    list<Arbol>::iterator ini = miArbol.hijos.begin();
    list<Arbol>::iterator fin = miArbol.hijos.end();
    int j = 0;
    while((ini != fin) && (i != j)){
        ini++;
        j++;
    }
    return *ini;
}

void Jugador::mostrarHijos(){
    int i =0;
    list<Arbol>::iterator ini = miArbol.hijos.begin();
    list<Arbol>::iterator fin = miArbol.hijos.end();
    wcout << "Profundidad 0" << endl;
    wcout << miArbol.player<< endl;
    i+=miArbol.hijos.size();
    while(ini != fin){
        wcout << "\tProfundidad 1" << endl;
        wcout << "\t" << ini->player << endl;
        list<Arbol>::iterator ini2 = ini->hijos.begin();
        list<Arbol>::iterator fin2 = ini->hijos.end();
        i+=ini->hijos.size();
        while(ini2 != fin2){
            wcout << "\t\tProfundidad 2" << endl;
            wcout << "\t\t" << ini2->player << endl;
            list<Arbol>::iterator ini3 = ini2->hijos.begin();
            list<Arbol>::iterator fin3 = ini2->hijos.end();
            i+=ini2->hijos.size();
            while(ini3 != fin3){
                wcout  << "\t\t\tProfundidad 3" << endl;
                wcout << "\t\t\t" << ini3->player << endl;
                list<Arbol>::iterator ini4 = ini2->hijos.begin();
                list<Arbol>::iterator fin4 = ini2->hijos.end();
                i+=ini3->hijos.size();
                while(ini4 != fin4){
                    wcout  << "\t\t\t\tProfundidad 4" << endl;
                    wcout << "\t\t\t\t" << ini4->player << endl;
                    i+=ini4->hijos.size();
                    ini4++;
                    system("clear");
                }
                ini3++;
            }
            ini2++;
        }
        ini++;
       
    }
    
    wcout << "Hay " << (i-miArbol.hijos.size()) << " hijos en profundidad 4" << endl;
}

