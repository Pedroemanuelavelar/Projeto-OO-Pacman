#include <allegro5/allegro.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "Dementador.h"

using namespace std;

Dementador::Dementador() {
    this->dementador = NULL;
    this->dementador = al_load_bitmap("images/dementador.png");
    if (!this->dementador) {
        printf("ERRO NO Dementador");
    }
    else {
        printf("\nDementador criado com sucesso!\n");
    }

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

ALLEGRO_BITMAP* Dementador::getDementador() {
    return this->dementador;
}

Dementador::~Dementador() {
    al_destroy_bitmap(this->dementador);
}