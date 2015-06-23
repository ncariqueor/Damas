/* 
 * File:   Tablero.h
 * Author: nelson
 *
 * Created on 31 de mayo de 2015, 21:44
 */

#ifndef TABLERO_H
#define	TABLERO_H
#include <cstdlib>
#include <iostream>
#include <list>
#include <locale>
using namespace std;

class Tablero {
public:
    Tablero();
    Tablero(const Tablero& orig);
    Tablero(const Tablero& t, int I, int J, int codigo);
    Tablero(const Tablero& t, int I1, int J1, int I2, int J2, int codigo);
    void mostrar();
    list<Tablero> getMovimiento(bool player);
    list<Tablero> getSalto(int i, int j, int pieza, int direccion);
    list<Tablero> getSaltoDerivado(int i, int j, int direccion);
    list<Tablero> getMovimientoDerivado(int i, int j, int direccion);
    Tablero& operator =(const Tablero& t);
    double valorTablero();
    bool salto(int i1, int j1, int i2, int j2);
    bool abierto(int i, int j);
    bool dentro(int i, int j);
    bool juegoTerminado(bool player);
    int signo(int f);
    bool equals(const Tablero& t);
    list<Tablero> getMovReina(int iX, int iY, int fX, int fY, int direccion);
    
    wchar_t tablero[10][10];
    int tablero2[10][10];
    int comer;
};

#endif	/* TABLERO_H */

