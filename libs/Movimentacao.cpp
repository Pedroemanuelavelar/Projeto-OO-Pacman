#include <allegro5/allegro.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "Movimentacao.h"

using namespace std;

Movimentacao::Movimentacao(){
    pos_x = 40;
	pos_y = 40;
    score = 0;

	//padrao
    this->pos_y_matriz = 0;
    this->pos_x_matriz = 0;
//cima
    this->pos_cy_matriz = 0;
    this->pos_cx_matriz = 0;
    this->pos_ccy_matriz = 0;
    this->pos_ccx_matriz = 0;
//baixo
    this->pos_by_matriz = 0;
    this->pos_bx_matriz = 0;
    this->pos_bby_matriz = 0;
    this->pos_bbx_matriz = 0;
//direita
    this->pos_ry_matriz = 0;
    this->pos_rx_matriz = 0;
    this->pos_rry_matriz = 0;
    this->pos_rrx_matriz = 0;
//esquerda
    this->pos_ly_matriz = 0;
    this->pos_lx_matriz = 0;
    this->pos_lly_matriz = 0;
    this->pos_llx_matriz = 0;
}

Movimentacao::Movimentacao(int x, int y) {
    this->pos_x = x;
    this->pos_y = y;
}

void Movimentacao::setposx(float x){
    this->pos_x = x;
}

void Movimentacao::setposy(float y){
    this->pos_y = y;
}

float Movimentacao::getposx(){
    return this->pos_x;
}

float Movimentacao::getposy(){
    return this->pos_y;
}

void Movimentacao::conversao() {
    //padr�o
    this->pos_y_matriz = (pos_y) / 40;
    this->pos_x_matriz = (pos_x) / 40;
    //cima
    this->pos_cy_matriz = ceil(pos_y / 40);
    this->pos_cx_matriz = pos_x / 40;
    this->pos_ccy_matriz = ceil(pos_y / 40);
    this->pos_ccx_matriz = ceil(pos_x / 40);
    //baixo
    this->pos_by_matriz = pos_y / 40;
    this->pos_bx_matriz = ceil(pos_x / 40);
    this->pos_bby_matriz = pos_y / 40;
    this->pos_bbx_matriz = pos_x / 40;
    //direita
    this->pos_ry_matriz = ceil(pos_y / 40);
    this->pos_rx_matriz = pos_x / 40;
    this->pos_rry_matriz = pos_y / 40;
    this->pos_rrx_matriz = pos_x / 40;
    //esquerda
    this->pos_ly_matriz = ceil(pos_y / 40);
    this->pos_lx_matriz = ceil(pos_x / 40);
    this->pos_lly_matriz = pos_y / 40;
    this->pos_llx_matriz = ceil(pos_x / 40);
}

bool Movimentacao::cima_obstaculo(int **matriz) {
    if (matriz[this->pos_y_matriz][this->pos_x_matriz] != 1) {
        if (matriz[this->pos_cy_matriz - 1][this->pos_cx_matriz] != 1 && matriz[this->pos_ccy_matriz - 1][this->pos_ccx_matriz] != 1) {
            return true;
        }
        else {
            return false;
        }
    }
}
bool Movimentacao::baixo_obstaculo(int **matriz) {
    if (matriz[this->pos_y_matriz][this->pos_x_matriz] != 1) {
        if (matriz[this->pos_by_matriz + 1][this->pos_bx_matriz] != 1 && matriz[this->pos_bby_matriz + 1][this->pos_bbx_matriz] != 1) {
            return true;
        }
        else {
            return false;
        }
    }
}
bool Movimentacao::direita_obstaculo(int **matriz) {
    if (matriz[this->pos_y_matriz][this->pos_x_matriz] != 1) {
        if (matriz[this->pos_ry_matriz][this->pos_rx_matriz + 1] != 1 && matriz[this->pos_rry_matriz][this->pos_rrx_matriz + 1] != 1) {
            return true;
        }
        else {
            return false;
        }
    }
}
bool Movimentacao::esquerda_obstaculo(int **matriz) {
    if (matriz[this->pos_y_matriz][this->pos_x_matriz] != 1) {
        if (matriz[this->pos_ly_matriz][this->pos_lx_matriz - 1] != 1 && matriz[this->pos_lly_matriz][this->pos_llx_matriz - 1] != 1) {
            return true;
        }
        else {
            return false;
        }
    }
}

Movimentacao::~Movimentacao(){

}