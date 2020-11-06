#include <iostream>

using namespace std;

void swap(char tabla[8][8], int x, int y, int a, int b){
    char temp = tabla[x][y];
    tabla[x][y] = tabla[a][b];
    tabla[a][b] = temp;
}

int coordenada_x(char x){
    switch (x) {
        case 'a':
            return 0;
            break;
        case 'b':
            return 1;
            break;
        case 'c':
            return 2;
            break;
        case 'd':
            return 3;
            break;
        case 'e':
            return 4;
            break;
        case 'f':
            return 5;
            break;
        case 'g':
            return 6;
            break;
        case 'h':
            return 7;
            break;
        default:
            return -1;

    }
}
void tablero(char m[8][8]){
    system("cls");
    cout << "       a       b       c       d       e       f       g      h" << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______|___" << endl;
    cout << "   |       |       |       |       |       |       |       |       |" << endl;
    cout << "8  |   " << m[7][0] << "   |   " << m[7][1] << "   |   " << m[7][2] << "   |   " << m[7][3] << "   |   " << m[7][4] << "   |   " << m[7][5] << "   |   " << m[7][6] << "   |   " << m[7][7] << "   |  8" << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______|___" << endl;
    cout << "   |       |       |       |       |       |       |       |       |" << endl;
    cout << "7  |   " << m[6][0] << "   |   " << m[6][1] << "   |   " << m[6][2] << "   |   " << m[6][3] << "   |   " << m[6][4] << "   |   " << m[6][5] << "   |   " << m[6][6] << "   |   " << m[6][7] << "   |  7" << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______|___" << endl;
    cout << "   |       |       |       |       |       |       |       |       |" << endl;
    cout << "6  |   " << m[5][0] << "   |   " << m[5][1] << "   |   " << m[5][2] << "   |   " << m[5][3] << "   |   " << m[5][4] << "   |   " << m[5][5] << "   |   " << m[5][6] << "   |   " << m[5][7] << "   |  6" << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______|___" << endl;
    cout << "   |       |       |       |       |       |       |       |       |" << endl;
    cout << "5  |   " << m[4][0] << "   |   " << m[4][1] << "   |   " << m[4][2] << "   |   " << m[4][3] << "   |   " << m[4][4] << "   |   " << m[4][5] << "   |   " << m[4][6] << "   |   " << m[4][7] << "   |  5" << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______|___" << endl;
    cout << "   |       |       |       |       |       |       |       |       |" << endl;
    cout << "4  |   " << m[3][0] << "   |   " << m[3][1] << "   |   " << m[3][2] << "   |   " << m[3][3] << "   |   " << m[3][4] << "   |   " << m[3][5] << "   |   " << m[3][6] << "   |   " << m[3][7] << "   |  4" << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______|___" << endl;
    cout << "   |       |       |       |       |       |       |       |       |" << endl;
    cout << "3  |   " << m[2][0] << "   |   " << m[2][1] << "   |   " << m[2][2] << "   |   " << m[2][3] << "   |   " << m[2][4] << "   |   " << m[2][5] << "   |   " << m[2][6] << "   |   " << m[2][7] << "   |  3" << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______|___" << endl;
    cout << "   |       |       |       |       |       |       |       |       |" << endl;
    cout << "2  |   " << m[1][0] << "   |   " << m[1][1] << "   |   " << m[1][2] << "   |   " << m[1][3] << "   |   " << m[1][4] << "   |   " << m[1][5] << "   |   " << m[1][6] << "   |   " << m[1][7] << "   |  2" << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______|___" << endl;
    cout << "   |       |       |       |       |       |       |       |       |" << endl;
    cout << "1  |   " << m[0][0] << "   |   " << m[0][1] << "   |   " << m[0][2] << "   |   " << m[0][3] << "   |   " << m[0][4] << "   |   " << m[0][5] << "   |   " << m[0][6] << "   |   " << m[0][7] << "   |  1" << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______|___" << endl;
    cout << "   |       |       |       |       |       |       |       |       |" << endl;
    cout << "       a       b       c       d       e       f       g      h" << endl;
}

void cambio(char tabla[8][8], char x=' ', int y = 0, char a=' ', int b = 0){
    while (true){
        cout << "Ingrese la coordenada 'x' (a-h):   "; cin >> x;
        if (coordenada_x(x) != -1){
            break;
        }
        cout<<"Rango no admitido, VUELVA A INTENTARLO"<<endl;
    }
    while (true){
        cout << "Ingrese la coordenada 'y' (1-8):   "; cin >> y;
        if (y>0 and y<8){
            break;
        }
        cout<<"Rango no admitido, VUELVA A INTENTARLO"<<endl;
    }
    cout << "CAMBIO A:" << endl;
    while (true){
        cout << "Ingrese la coordenada 'x' (a-h):   "; cin >> a;
        if (coordenada_x(x) != -1){
            break;
        }
        cout<<"Rango no admitido, VUELVA A INTENTARLO"<<endl;
    }
    cout << "CAMBIO A:" << endl;
    while (true){
        cout << "Ingrese la coordenada 'y' (1-8):   "; cin >> b;
        if (y>0 and y<8){
            break;
        }
        cout<<"Rango no admitido, VUELVA A INTENTARLO"<<endl;
    }
    swap(tabla, y-1, coordenada_x(x), b-1, coordenada_x(a));
    cout<<endl;
    tablero(tabla);
}