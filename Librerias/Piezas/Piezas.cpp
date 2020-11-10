class piezas{
private:
    //Piezas minusculas
    int coor_x_peon[8] = {0,1,2,3,4,5,6,7};
    int coor_y_peon[8] = {1,1,1,1,1,1,1,1};
    int primer_movimiento_peon[8] = {0,0,0,0,0,0,0,0};
    int coor_x_torre[2] = {0,7};
    int coor_y_torre[2] = {0,0};
    int coor_x_caballo[2] = {1,6};
    int coor_y_caballo[2] = {0,0};
    int coor_x_alfil[2] = {2,5};
    int coor_y_alfil[2] = {0,0};
    int coor_x_queen = 3;
    int coor_y_queen = 0;
    int coor_x_rey = 4;
    int coor_y_rey = 0;

    //Piezas mayusculas
    int COOR_X_PEON[8] = {0,1,2,3,4,5,6,7};
    int COOR_Y_PEON[8] = {1,1,1,1,1,1,1,1};
    int PRIMER_MOVIMIENTO_PEON[8] = {0,0,0,0,0,0,0,0};
    int COOR_X_TORRE[2] = {0,7};
    int COOR_Y_TORRE[2] = {0,0};
    int COOR_X_CABALLO[2] = {1,6};
    int COOR_Y_CABALLO[2] = {0,0};
    int COOR_X_ALFIL[2] = {2,5};
    int COOR_Y_ALFIL[2] = {0,0};
    int COOR_X_QUEEN = 3;
    int COOR_Y_QUEEN = 0;
    int COOR_X_REY = 4;
    int COOR_Y_REY = 0;

public:
    void movimiento_peon(char tablero[8][8], int n_peon){
        int coor_x = coor_x_peon[n_peon];
        int coor_y = coor_y_peon[n_peon];
        if (primer_movimiento_peon[n_peon]==0){
            tablero[coor_y+1][coor_x] = '*';
            tablero[coor_y+2][coor_x] = '*';
        }
        else {
            tablero[coor_y+1][coor_x] = '*';
        }
    }
    void MOVIMIENTO_PEON(char tablero[8][8], int n_peon){
        int coor_x = coor_x_peon[n_peon];
        int coor_y = coor_y_peon[n_peon];
        if (PRIMER_MOVIMIENTO_PEON[n_peon]==0){
            tablero[coor_y-1][coor_x] = '*';
            tablero[coor_y-2][coor_x] = '*';
        }
        else {
            tablero[coor_y-1][coor_x] = '*';
        }
    }
};
