/* 
 * File:   JugadorHumano.cpp
 * Author: nelson
 * 
 * Created on 18 de junio de 2015, 9:40
 */

#include "JugadorHumano.h"

JugadorHumano::JugadorHumano(bool player){
    jugador = player;
}

Tablero JugadorHumano::movimiento(const Tablero& t){
    bool accion = false;
    list<Tablero> auxiliar;
    
    wchar_t move[4];
    wchar_t opcion;
    
    Tablero aux;
    aux.operator =(t);
    do{
        list<Tablero> comer;
        auxiliar.operator =(aux.getMovimiento(jugador));
        list<Tablero>::iterator ini = auxiliar.begin();
        list<Tablero>::iterator fin = auxiliar.end();
        while(ini != fin){
            if(ini->comer > 0)
                comer.push_back(*ini);
            ini++;
        }
        move[0] = 'n';
        move[1] = 'n';
        move[2] = 'n';
        move[3] = 'n';
        if(!comer.empty()){
            wcout << "Ingrese 's', si quiere capturar pieza o 'n' si quiere retirarla:  ";
            wcin >> opcion;
            opcion = toupper(opcion);
            if(opcion == 'S')
                wcout << "Ingrese coordenadas (desde[x1][y1], hacia[x2][y2]): ";
            else
                wcout << "Ingrese coordenadas de pieza a retirar: ";
            wcin >> move[0] >> move[1];
            if(opcion == 'S')
                wcin >> move[2] >> move[3];
            move[0] = toupper(move[0]);
            move[1] = toupper(move[1]);
            move[2] = toupper(move[2]);
            move[3] = toupper(move[3]);
            int x1 = (int)move[0] - 65;
            int x2 = (int)move[2] - 65;
            int y1 = (int)move[1] - 48;
            int y2 = (int)move[3] - 48;
            if(move[2] == 'N' && move[3] == 'N'){
                if((int)move[0] > 64 && (int)move[0] < 75){
                    if(y1 >= 0 && y1 < 10){
                        if(aux.tablero2[x1+1][y1-1] > 0 || aux.tablero2[x1+1][y1+1] > 0){
                            if(x1+1 >= 0 && x1+1 < 10 && y1-1 >= 0 && y1-1 < 10 && y1+1 >= 0 && y1+1 <10){
                                aux = Tablero(aux, x1, y1, 8);
                                return aux;
                            }else
                                wcout << "Movimiento invalido." << endl;
                        }else
                            wcout << "Pieza invalida, seleccione otra pieza." << endl;
                    }else
                        wcout << "Ingrese valores entre 0 y 9." << endl;
                }else
                    wcout << "Ingrese valores entre A y J, o, a y j." << endl;
            }else{
                if(((int)move[0] > 64 && (int)move[0] < 75) && ((int)move[2] > 64 && (int)move[2] < 75)){
                    if((y1 >= 0 && y1 < 10) && (y2 >= 0 && y2 < 10)){
                        int pieza = aux.tablero2[x1][y1];
                        
                        if(pieza == 1){
                            for(int i=1;i<10;i++){
                                if(aux.salto(x1, y1, x1-i, y1-i) || aux.salto(x1, y1, x1-i, y1+i)){
                                    if((x1-(i+1)) == x2 && (y1-(i+1)) == y2){
                                        aux = Tablero(aux, x1, y1, x2, y2, 1);
                                        list<Tablero> comer;
                                        auxiliar.operator =(aux.getMovimiento(jugador));
                                        list<Tablero>::iterator ini = auxiliar.begin();
                                        list<Tablero>::iterator fin = auxiliar.end();
                                        while(ini != fin){
                                            if(ini->comer > 0)
                                                comer.push_back(*ini);
                                            ini++;
                                        }
                                        if(comer.empty())
                                            return aux;
                                        else{
                                            system("clear");
                                            aux.mostrar();
                                        }
                                    }
                                    if((x1-(i+1)) == x2 && (y1+(i+1)) == y2){
                                        aux = Tablero(aux, x1, y1, x2, y2, 2);
                                        list<Tablero> comer;
                                        auxiliar.operator =(aux.getMovimiento(jugador));
                                        list<Tablero>::iterator ini = auxiliar.begin();
                                        list<Tablero>::iterator fin = auxiliar.end();
                                        while(ini != fin){
                                            if(ini->comer > 0)
                                                comer.push_back(*ini);
                                            ini++;
                                        }
                                        if(comer.empty())
                                            return aux;
                                        else{
                                            system("clear");
                                            aux.mostrar();
                                        }
                                    }
                                }
                            }
                        }
                        
                        if(pieza == 2){
                            int direccion = 0;
                            if(x2-x1 < 0 && y2-y1 < 0)
                                direccion = 0;
                            if(x2-x1 < 0 && y2-y1 > 0)
                                direccion = 1;
                            if(x2-x1 > 0 && y2-y1 < 0)
                                direccion = 2;
                            if(x2-x1 > 0 && y2-y1 > 0)
                                direccion = 3;
                            
                            Tablero temporal;
                            temporal.operator =(aux);
                            
                            for(int i=1;i<10;i++){
                                if(temporal.abierto(x1-1, y1-1) && direccion == 0){
                                    temporal = Tablero(temporal, x1, y1, 0);
                                    x1 = x1-1;
                                    y1 = y1-1;
                                }else{
                                    if(temporal.salto(x1, y1, x1-1, y1-1) && direccion == 0){
                                        if(x1-2 == x2 && y1-2 == y2){
                                            aux = Tablero(temporal, x1, y1, 4);
                                            list<Tablero> comer;
                                            auxiliar.operator =(aux.getMovimiento(jugador));
                                            list<Tablero>::iterator ini = auxiliar.begin();
                                            list<Tablero>::iterator fin = auxiliar.end();
                                            while(ini != fin){
                                                if(ini->comer > 0)
                                                    comer.push_back(*ini);
                                                ini++;
                                            }
                                            if(comer.empty())
                                                return aux;
                                            else{
                                                system("clear");
                                                aux.mostrar();
                                            }
                                        }
                                    }else{
                                        if(temporal.abierto(x1-1, y1+1) && direccion == 1){
                                            temporal = Tablero(temporal, x1, y1, 1);
                                            x1 = x1-1;
                                            y1 = y1+1;
                                        }else{
                                            if(temporal.salto(x1, y1, x1-1, y1+1) && direccion == 1){
                                                if(x1-2 == x2 && y1+2 == y2){
                                                    aux = Tablero(temporal, x1, y1, 5);
                                                    list<Tablero> comer;
                                                    auxiliar.operator =(aux.getMovimiento(jugador));
                                                    list<Tablero>::iterator ini = auxiliar.begin();
                                                    list<Tablero>::iterator fin = auxiliar.end();
                                                    while(ini != fin){
                                                        if(ini->comer > 0)
                                                            comer.push_back(*ini);
                                                        ini++;
                                                    }
                                                    if(comer.empty())
                                                        return aux;
                                                    else{
                                                        system("clear");
                                                        aux.mostrar();
                                                    }
                                                }
                                            }else{
                                                if(temporal.abierto(x1+1, y1-1) && direccion == 2){
                                                    temporal = Tablero(temporal, x1, y1, 2);
                                                    x1 = x1+1;
                                                    y1 = y1-1;
                                                }else{
                                                    if(temporal.salto(x1, y1, x1+1, y1-1) && direccion == 2){
                                                        if(x1+2 == x2 && y1-2 == y2){
                                                            aux = Tablero(temporal, x1, y1, 6);
                                                            list<Tablero> comer;
                                                            auxiliar.operator =(aux.getMovimiento(jugador));
                                                            list<Tablero>::iterator ini = auxiliar.begin();
                                                            list<Tablero>::iterator fin = auxiliar.end();
                                                            while(ini != fin){
                                                                if(ini->comer > 0)
                                                                    comer.push_back(*ini);
                                                                ini++;
                                                            }
                                                            if(comer.empty())
                                                                return aux;
                                                            else{
                                                                system("clear");
                                                                aux.mostrar();
                                                            }
                                                        }
                                                    }else{
                                                        if(temporal.abierto(x1+1, y1+1) && direccion == 3){
                                                            temporal = Tablero(temporal, x1, y1, 3);
                                                            x1 = x1+1;
                                                            y1 = y1+1;
                                                        }else{
                                                            if(temporal.salto(x1, y1, x1+1, y1+1) && direccion == 3){
                                                                if(x1+2 == x2 && y1+2 == y2){
                                                                    aux = Tablero(temporal, x1, y1, 7);
                                                                    list<Tablero> comer;
                                                                    auxiliar.operator =(aux.getMovimiento(jugador));
                                                                    list<Tablero>::iterator ini = auxiliar.begin();
                                                                    list<Tablero>::iterator fin = auxiliar.end();
                                                                    while(ini != fin){
                                                                        if(ini->comer > 0)
                                                                            comer.push_back(*ini);
                                                                        ini++;
                                                                    }
                                                                    if(comer.empty())
                                                                        return aux;
                                                                    else{
                                                                        system("clear");
                                                                        aux.mostrar();
                                                                    }
                                                                }
                                                            }else{
                                                                wcout << "Debe capturar la pieza." << endl;
                                                                break;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
                
        }else{
            wcout << "Ingrese coordenadas (desde[x1][y1], hacia[x2][y2]): ";
            wcin >> setw(1) >> move[0];
            wcin >> setw(1) >> move[1];
            wcin >> setw(1) >> move[2];
            wcin >> setw(1) >> move[3];
            wcin.ignore(256,'\n');
            move[0] = toupper(move[0]);
            move[1] = toupper(move[1]);
            move[2] = toupper(move[2]);
            move[3] = toupper(move[3]);
            int x1 = (int)move[0] - 65;
            int x2 = (int)move[2] - 65;
            int y1 = (int)move[1] - 48;
            int y2 = (int)move[3] - 48;
            if(((int)move[0] > 64 && (int)move[0] < 75) && ((int)move[2] > 64 && (int)move[2] < 75)){
                if((y1 >= 0 && y1 < 10) && (y2 >= 0 && y2 < 10)){
                    int pieza = aux.tablero2[x1][y1];
                    if(pieza == 1){
                        if(aux.abierto(x1-1, y1-1) || aux.abierto(x1-1, y1+1)){
                            if((x1-1) == x2 && (y1-1) == y2){
                                aux = Tablero(aux, x1, y1, x2, y2, 0);
                                        return aux;
                            }
                            if((x1-1) == x2 && (y1+1) == y2){
                                aux = Tablero(aux, x1, y1, x2, y2, 0);
                                        return aux;
                            }
                        }
                    }
                    if(pieza == 2){
                        int direccion = 0;
                        if(x2-x1 < 0 && y2-y1 < 0)
                            direccion = 0;
                        if(x2-x1 < 0 && y2-y1 > 0)
                            direccion = 1;
                        if(x2-x1 > 0 && y2-y1 < 0)
                            direccion = 2;
                        if(x2-x1 > 0 && y2-y1 > 0)
                            direccion = 3;
                        
                        for(int i=1;i<10;i++){
                            if(aux.abierto(x1-i, y1-i) && direccion == 0){
                                if((x1-i == x2 && y1-i == y2)){
                                    aux = Tablero(aux, x1, y1, x2, y2, 0);
                                    return aux;
                                }
                            }else{                            
                                if(aux.abierto(x1-i, y1+i) && direccion == 1){
                                    if((x1-i == x2 && y1+i == y2)){
                                        aux = Tablero(aux, x1, y1, x2, y2, 0);
                                        return aux;
                                    }
                                }else{
                                    if(aux.abierto(x1+i, y1-i) && direccion == 2){
                                        if((x1+i == x2 && y1-i == y2)){
                                            aux = Tablero(aux, x1, y1, x2, y2, 0);
                                            return aux;
                                        }
                                    }else{
                                        if(aux.abierto(x1+i, y1+i) && direccion == 3){
                                            if((x1+i == x2 && y1+i == y2)){
                                                aux = Tablero(aux, x1, y1, x2, y2, 0);
                                                return aux;
                                            }
                                        }else
                                            break;
                                    }
                                }
                            }
                        }
                    }
                    wcout << "Movimiento invalido." << endl;
                }else
                    wcout << "Ingrese valores entre 0 y 9." << endl;
            }else
                wcout << "Ingrese valores entre A y J, o, a y j." << endl;
        }
    }while(accion == false);
}                                                                                           