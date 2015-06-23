/* 
 * File:   Juego.cpp
 * Author: nelson
 * 
 * Created on 3 de junio de 2015, 22:33
 */

#include "Juego.h"
#include <cstdlib>
#include <iostream>
using namespace std;


Juego::Juego() {
    tab = new Tablero();
    player = true;
    blanco = new Jugador(*tab, 4, player);
    //blanco->mostrarHijos();
    negro = new Jugador(*tab, 4, !player);
    //negro->mostrarHijos();
    tab->mostrar();
    while(!tab->juegoTerminado(player)){
        cin.ignore().get();
        system("clear");
        tab->operator =((player ? blanco->movimiento() : negro->movimiento()));
        tab->mostrar();
        blanco->actualizar(*tab,player);
        negro->actualizar(*tab,player);
        player = !player;
        
    }
    if(player == true){
        wcout << "\nGano CPU Negra" << endl;
    }else{
        wcout << "\nGano CPU Blanca" << endl;
    }
    
}