#include <allegro5/allegro.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include "Dementador.h"

using namespace std;

Dementador::Dementador() {

    updem = false, downdem = false, leftdem = false, rightdem = false;
    
    for(int i = 0; i < 4; i++) {
        direcaodem[i] = false;
    }

    //Geração aleatória para a direção do fantasma
    dem = 0;

    this->dementador = NULL;
    this->dementador = al_load_bitmap("images/dementador.png");
    if (!this->dementador) {
        printf("ERRO NO Dementador");
    }
    else {
        printf("\nDementador criado com sucesso!\n");
    }

    updem = false;
    downdem = false;
    leftdem = false;
    rightdem = false;

    //padrao
    this->dem_y_matriz = 0;
    this->dem_x_matriz = 0;
}

void Dementador::setdemx(float x) {
    Movimentacao::setposx(x);
}
void Dementador::setdemy(float y) {
    Movimentacao::setposy(y);
}

float Dementador::getdemx() {
    return Movimentacao::getposx();
}
float Dementador::getdemy() {
    return Movimentacao::getposy();
}

void Dementador::conversao() {

    Movimentacao::conversao();

    //padr�o
    this->dem_y_matriz = (getposy()) / 40;
    this->dem_x_matriz = (getposx()) / 40;
}

bool Dementador::cima_dementador(int** matriz) {
    return Movimentacao::cima_obstaculo(matriz);
}
bool Dementador::baixo_dementador(int** matriz) {
    return Movimentacao::baixo_obstaculo(matriz);
}
bool Dementador::direita_dementador(int** matriz) {
    return Movimentacao::direita_obstaculo(matriz);
}
bool Dementador::esquerda_dementador(int** matriz) {
    return Movimentacao::esquerda_obstaculo(matriz);
}

void Dementador::desenha_dementador() {
    al_draw_bitmap_region(dementador, 0, 0, 40, 40, 
    Movimentacao::getposx(), Movimentacao::getposy(), 0);
}

void Dementador::randomDir(float pacx, float pacy, int** matriz) {

    srand(time(NULL));

    //Movimentação do Dementador

    for(int i = 0; i < 4; i++){

        dem = rand() % 100;

        if (dem <= 25 && cima_dementador(matriz) == true) {

            updem = true;
            downdem = false;
            leftdem = false;
            rightdem = false;

            direcaodem[0] = true;
            direcaodem[1] = false;
            direcaodem[2] = false;
            direcaodem[3] = false;

        }
        else if (dem > 25 && dem <=50 && baixo_dementador(matriz) == true) {

            updem = false;
            downdem = true;
            leftdem = false;
            rightdem = false;

            direcaodem[0] = false;
            direcaodem[1] = true;
            direcaodem[2] = false;
            direcaodem[3] = false;


        }
        else if (dem > 50 && dem <= 75 && esquerda_dementador(matriz) == true) {

            updem = false;
            downdem = false;
            leftdem = true;
            rightdem = false;

            direcaodem[0] = false;
            direcaodem[1] = false;
            direcaodem[2] = false;
            direcaodem[3] = true;

        }
        
        else if (dem > 75 && dem <= 100 && direita_dementador(matriz) == true) {

            updem = false;
            downdem = false;
            leftdem = false;
            rightdem = true;

            direcaodem[0] = false;
            direcaodem[1] = false;
            direcaodem[2] = true;
            direcaodem[3] = false;

        }

        //Movi do dementador
        if (updem == true && cima_dementador(matriz) == true) {
            setdemy(getdemy() - 2.0);
        }

        if (downdem == true && baixo_dementador(matriz) == true) {
            setdemy(getdemy() + 2.0);
        }

        if (leftdem == true && esquerda_dementador(matriz) == true) {
            setdemx(getdemx() - 2.0);
        }

        if (rightdem == true && direita_dementador(matriz) == true) {
            setdemx(getdemx() + 2.0);
        }
    }
}

ALLEGRO_BITMAP* Dementador::getDementador() {
    return this->dementador;
}

Dementador::~Dementador() {
    al_destroy_bitmap(this->dementador);
}