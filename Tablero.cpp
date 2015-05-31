#include <iostream>
#include "Tablero.h"
#include <locale>
using namespace std;

Tablero::Tablero(){
    setlocale(LC_CTYPE,"");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i<3 && (i+j)%2 != 0){
                tablero[i][j] = 9679;
                tablero2[i][j] = -1;
            }
            else{
                if(i>6 && (i+j)%2 != 0){
                    tablero[i][j] = 9675;
                    tablero2[i][j] = 1;
                }
                else{
                    tablero[i][j] = '-';
                    tablero2[i][j] = 0;
                }
            }
        }
    }
}

Tablero::Tablero(const Tablero& t, int I, int J, int codigo){
    setlocale(LC_CTYPE,"");
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tablero[i][j] = t.tablero[i][j];
            tablero2[i][j] = t.tablero2[i][j];
        }
    }
    
    int valorInt= tablero2[I][J];
    wchar_t valorChar = tablero[I][J];
    
    tablero[I][J] = '-';
    tablero2[I][J] = 0;
    
    switch(codigo){
        case(0):
            I--;
            J--;
            break;
            
        case(1):
            I--;
            J++;
            break;
            
        case(2):
            I++;
            J--;
            break;
            
        case(3):
            I++;
            J++;
            break;
            
        case(4):
            tablero[I-1][J-1] = '-';
            tablero2[I-1][J-1] = 0;
            I-=2;
            J-=2;
            break;
            
        case(5):
            tablero[I-1][J+1] = '-';
            tablero2[I-1][J+1] = 0;
            I-=2;
            J+=2;
            break;
            
        case(6):
            tablero[I+1][J-1] = '-';
            tablero2[I+1][J-1] = 0;
            I+=2;
            J-=2;
            break;
            
        case(7):
            tablero[I+1][J+1] = '-';
            tablero2[I+1][J+1] = 0;
            I+=2;
            J+=2;
            break;
            
        default:
            break;
    }
    
    tablero[I][J] = valorChar;
    tablero2[I][J] = valorInt;
    
    if(I==9 && valorInt == -1){
        tablero[I][J] = 9819;
        tablero2[I][J] *=2;
    }
    if(I==0 && valorInt == 1){
        tablero[I][J] = 9813;
        tablero2[I][J] *=2;
    }
}


void Tablero::mostrar(){
    wcout << "\t";
    for(int i=0;i<10;i++){
        wcout << i << "\t";
    }
    cout << endl << endl;
    for(int i=0;i<10;i++){
        char t = i+65;
        wcout << t;
        for(int j=0;j<10;j++){
            
            wcout << "\t" << tablero[i][j];
            if(j==9)
                cout << endl << endl;
        }
    }
}

list<Tablero>& Tablero::movimientos(bool player){
    list <Tablero> *movimiento = new list<Tablero>();
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if((player && tablero2[i][j]>0) || (!player && tablero2[i][j]<0)){
                list<Tablero> aux = getSaltos(i, j, tablero2[i][j]);
                list<Tablero>::iterator pos = aux.begin();
                while(pos != aux.end()){
                    movimiento->push_back(*pos);
                    pos++;
                }
                
            }
        }
    }
    
    if(movimiento->empty()){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                int pieza = tablero2[i][j];
                if(player && pieza == 1){
                    if(abierto(i-1, j-1))
                        movimiento->push_back(Tablero(*this,i,j,0));
                    if(abierto(i-1, j+1))
                        movimiento->push_back(Tablero(*this,i,j,1));
                }else{
                    if(player && pieza == 2){
                        if(abierto(i-1, j-1))
                            movimiento->push_back(Tablero(*this,i,j,0));
                        if(abierto(i-1, j+1))
                            movimiento->push_back(Tablero(*this,i,j,1));
                        if(abierto(i+1, j-1))
                            movimiento->push_back(Tablero(*this,i,j,2));
                        if(abierto(i+1, j+1))
                            movimiento->push_back(Tablero(*this,i,j,3));
                    }
                }
                
                if(!player && pieza == -1){
                    if(abierto(i+1, j-1)){
                        Tablero *aux = new Tablero(*this,i,j,3);
                        movimiento->push_back(*aux);
                    }
                    if(abierto(i+1, j+1)){
                        Tablero *aux = new Tablero(*this,i,j,4);
                        movimiento->push_back(*aux);
                    }
                }else{
                    if(!player && pieza == -2){
                        if(abierto(i-1, j-1))
                            movimiento->push_back(Tablero(*this,i,j,0));
                        if(abierto(i-1, j+1))
                            movimiento->push_back(Tablero(*this,i,j,1));
                        if(abierto(i+1, j-1))
                            movimiento->push_back(Tablero(*this,i,j,2));
                        if(abierto(i+1, j+1))
                            movimiento->push_back(Tablero(*this,i,j,3));
                    }
                }
            }
        }
    }
    return *movimiento;
}

list<Tablero>& Tablero::getSaltos(int i, int j, int pieza){
    list<Tablero> *saltos = new list<Tablero>();
    if(pieza == 1 || pieza == 2 || pieza == -2){
        if(salto(i, j, i-1, j-1)){
            Tablero *nuevoTablero = new Tablero(*this, i, j, 4);
            list <Tablero> saltosDerivados = nuevoTablero->getSaltos(i-2, j-2, pieza);
            if(saltosDerivados.empty())
                saltos->push_back(*nuevoTablero);
            else{
                list<Tablero>::iterator pos;
                pos = saltosDerivados.begin();
                while(pos != saltosDerivados.end()){
                    saltos->push_back(*pos);
                    pos++;
                }
            }
                
        }
        if(salto(i, j, i-1, j+1)){
            Tablero *nuevoTablero = new Tablero(*this, i, j, 5);
            list <Tablero> saltosDerivados = nuevoTablero->getSaltos(i-2, j+2, pieza);
            if(saltosDerivados.empty())
                saltos->push_back(*nuevoTablero);
            else{
                list<Tablero>::iterator pos;
                pos = saltosDerivados.begin();
                while(pos != saltosDerivados.end()){
                    saltos->push_back(*pos);
                    pos++;
                }
            }
                
        }
    }
    if(pieza == -1 || pieza == 2 || pieza == -2){
        if(salto(i, j, i+1, j-1)){
            Tablero *nuevoTablero = new Tablero(*this, i, j, 6);
            list <Tablero> saltosDerivados = nuevoTablero->getSaltos(i+2, j-2, pieza);
            if(saltosDerivados.empty())
                saltos->push_back(*nuevoTablero);
            else{
                list<Tablero>::iterator pos;
                pos = saltosDerivados.begin();
                while(pos != saltosDerivados.end()){
                    saltos->push_back(*pos);
                    pos++;
                }
            }
                
        }
        if(salto(i, j, i+1, j+1)){
            Tablero *nuevoTablero = new Tablero(*this, i, j, 7);
            list <Tablero> saltosDerivados = nuevoTablero->getSaltos(i+2, j+2, pieza);
            if(saltosDerivados.empty())
                saltos->push_back(*nuevoTablero);
            else{
                list<Tablero>::iterator pos;
                pos = saltosDerivados.begin();
                while(pos != saltosDerivados.end()){
                    saltos->push_back(*pos);
                    pos++;
                }
            }
                
        }
    }
    return *saltos;
}

double Tablero::valorTablero(){
    double valor = 0;
    
    int valores[10][10] = {{5,4,3,2,1,1,2,3,4,5},
                           {5,4,3,2,1,1,2,3,4,5},
                           {5,4,3,2,1,1,2,3,4,5},
                           {5,4,3,2,1,1,2,3,4,5},
                           {5,4,3,2,1,1,2,3,4,5},
                           {5,4,3,2,1,1,2,3,4,5},
                           {5,4,3,2,2,2,2,3,4,5},
                           {5,4,3,3,3,3,3,3,4,5},
                           {5,4,4,4,4,4,4,4,4,5},
                           {5,5,5,5,5,5,5,5,5,5}};
    
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            valor += tablero2[i][j] * valores[i][j];
        }
    }
    
    return valor;
}

bool Tablero::salto(int i1, int j1, int i2, int j2){
    return abierto(2*i2 - i1, 2*j2 - j1) && dentro(i2, j2) && tablero2[i2][j2] == -tablero2[i1][j1];
}

bool Tablero::abierto(int i, int j){
    return dentro(i, j) && tablero2[i][j] == 0;
}

bool Tablero::dentro(int i, int j){
    return i>=0 && i<10 && j>=0 && j<10;
}

bool Tablero::juegoTerminado(bool player){
    return movimientos(player).empty();
}


