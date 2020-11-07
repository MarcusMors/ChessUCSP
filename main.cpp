#include <iostream>
#include "Librerias/Tablero/Tablero.h"
using namespace std;

class peon{
    int cord_x=2;
};

int main(){
    char m[8][8] = {{'T', 'C', 'A', 'R', 'Q', 'A', 'C', 'T'},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'t', 'c', 'a', 'q', 'r', 'a', 'c', 't'}};
    tablero(m);
    while (true){
        cambio(m, ' ', 0, ' ', 0);
    }
}

