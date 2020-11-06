#include <iostream>
#include "Librerias/Tablero/Tablero.h"

using namespace std;

int main(){
    char m[8][8] = {{'t', 'c', 'a', 'q', 'r', 'a', 'c', 't'},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {'T', 'C', 'A', 'R', 'Q', 'A', 'C', 'T'}};
    tablero(m);
    while (true){
        cambio(m, ' ', 0, ' ', 0);
    }

}

