/* 
 * File:   main.cpp
 * Author: nelson
 *
 * Created on 31 de mayo de 2015, 21:43
 */
#include "Tablero.h"

//#include "Juego.h"
#include "JugadorHumano.h"
#include <iostream>
#include <cstdlib>
#include <locale>
#include <ctype.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    setlocale(LC_CTYPE, "");
    //Juego j;
    Tablero *t = new Tablero();
    JugadorHumano *jugador = new JugadorHumano(true);
    list<Tablero> auxiliar;
    system("clear");
    while(!t->juegoTerminado(true) && !t->juegoTerminado(false)){
        t->mostrar();
        t->operator =(jugador->movimiento(*t));
        cin.ignore().get();
        system("clear");
        system("clear");
        //auxiliar.operator =(t->getMovimiento(true));
        list<Tablero>::iterator ini = auxiliar.begin();
        list<Tablero>::iterator fin = auxiliar.end();
    
        double max =0 , min = 999;
        /*while(ini != fin){
            double tmpx =  ini->valorTablero();
            if( tmpx >= max){
                t->operator=( *ini);
                max = ini->valorTablero();
            }
            ini++;
        }*/
         t->mostrar();
        cin.ignore().get();
        system("clear");
        system("clear");
        auxiliar.operator =(t->getMovimiento(false));
        ini = auxiliar.begin();
        fin = auxiliar.end();
        
        while(ini != fin){
            double tmpx =  ini->valorTablero();
            
            if( tmpx <= min){
                t->operator=( *ini);
                min = ini->valorTablero();
            }
            ini++;
        }
       
    }
    t->mostrar();
    if(t->juegoTerminado(true))
        wcout << "Gano negro" << endl;
    else
        wcout << "Gano blanco" << endl;
    return 0;
}

