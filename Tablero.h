#ifndef TABLERO_H
#define	TABLERO_H
#include <list>
using namespace std;

class Tablero {
public:
    wchar_t tablero[10][10];
    int tablero2[10][10];
    
    Tablero();
    Tablero(const Tablero& t, int, int, int);
    void mostrar();
    list <Tablero>& movimientos(bool);
    list <Tablero>& getSaltos(int, int, int);
    bool salto(int, int, int, int);
    bool abierto(int, int);
    bool dentro(int, int);
    double valorTablero();
    bool juegoTerminado(bool);
};

#endif	/* TABLERO_H */

