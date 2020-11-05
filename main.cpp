#include <iostream>
using namespace std;

void swap(char tabla[8][8], int x, int y, int a, int b)
{
    int temp = tabla[x][y];
    tabla[x][y] = tabla[a][b];
    tabla[a][b] = temp;
}
void tablero(char m[8][8]){
    cout << "-1     0       1       2       3       4       5       6      7" << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______" << endl;
    cout << "   |       |       |       |       |       |       |       |       " << endl;
    cout << "0  |   " << m[0][0] << "   |   " << m[0][1] << "   |   " << m[0][2] << "   |   " << m[0][3] << "   |   " << m[0][4] << "   |   " << m[0][5] << "   |   " << m[0][6] << "   |   " << m[0][7] << " " << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______" << endl;
    cout << "   |       |       |       |       |       |       |       |       " << endl;
    cout << "1  |   " << m[1][0] << "   |   " << m[1][1] << "   |   " << m[1][2] << "   |   " << m[1][3] << "   |   " << m[1][4] << "   |   " << m[1][5] << "   |   " << m[1][6] << "   |   " << m[1][7] << " " << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______" << endl;
    cout << "   |       |       |       |       |       |       |       |       " << endl;
    cout << "2  |   " << m[2][0] << "   |   " << m[2][1] << "   |   " << m[2][2] << "   |   " << m[2][3] << "   |   " << m[2][4] << "   |   " << m[2][5] << "   |   " << m[2][6] << "   |   " << m[2][7] << " " << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______" << endl;
    cout << "   |       |       |       |       |       |       |       |       " << endl;
    cout << "3  |   " << m[3][0] << "   |   " << m[3][1] << "   |   " << m[3][2] << "   |   " << m[3][3] << "   |   " << m[3][4] << "   |   " << m[3][5] << "   |   " << m[3][6] << "   |   " << m[3][7] << " " << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______" << endl;
    cout << "   |       |       |       |       |       |       |       |       " << endl;
    cout << "4  |   " << m[4][0] << "   |   " << m[4][1] << "   |   " << m[4][2] << "   |   " << m[4][3] << "   |   " << m[4][4] << "   |   " << m[4][5] << "   |   " << m[4][6] << "   |   " << m[4][7] << " " << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______" << endl;
    cout << "   |       |       |       |       |       |       |       |       " << endl;
    cout << "5  |   " << m[5][0] << "   |   " << m[5][1] << "   |   " << m[5][2] << "   |   " << m[5][3] << "   |   " << m[5][4] << "   |   " << m[5][5] << "   |   " << m[5][6] << "   |   " << m[5][7] << " " << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______" << endl;
    cout << "   |       |       |       |       |       |       |       |       " << endl;
    cout << "6  |   " << m[6][0] << "   |   " << m[6][1] << "   |   " << m[6][2] << "   |   " << m[6][3] << "   |   " << m[6][4] << "   |   " << m[6][5] << "   |   " << m[6][6] << "   |   " << m[6][7] << " " << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______" << endl;
    cout << "   |       |       |       |       |       |       |       |       " << endl;
    cout << "7  |   " << m[7][0] << "   |   " << m[7][1] << "   |   " << m[7][2] << "   |   " << m[7][3] << "   |   " << m[7][4] << "   |   " << m[7][5] << "   |   " << m[7][6] << "   |   " << m[7][7] << " " << endl;
    cout << "___|_______|_______|_______|_______|_______|_______|_______|_______" << endl;
}

void cambio(char tabla[8][8], int x = 0, int y = 0, int a = 0, int b = 0){
    cout << "Ingrese" << endl;
    cin >> x >> y;
    cout << "Ingrese cambio" << endl;
    cin >> a >> b;
    swap(tabla, x, y, a, b);
    tablero(tabla);
}

int main(){
    char m[8][8] = {{'t', 'c', 'a', 'q', 'r', 'a', 'c', 't'},
                    {'s', 's', 's', 's', 's', 's', 's', 's'},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'T', 'C', 'A', 'R', 'Q', 'A', 'C', 'T'},
                    {'s', 's', 's', 's', 's', 's', 's', 's'}};
    tablero(m);
    cambio(m);
}

