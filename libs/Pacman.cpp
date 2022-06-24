#include <allegro5/allegro.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "Pacman.h"

using namespace std;

Pacman::Pacman() {
	this->pacman = NULL;
	this->pacman = al_load_bitmap("images/pacman.png");
	if (!this->pacman) {
		printf("ERRO NO PACMAN");
	}
	else {
		printf("\nPACMAN criado com sucesso!\n");
	}

	pac_x = 40;
	pac_y = 40;
    score = 0;

	//padrao
	 this->pac_y_matriz = 0;
	 this->pac_x_matriz = 0;
	//cima
	 this->pac_cy_matriz = 0;
	 this->pac_cx_matriz = 0;
	 this->pac_ccy_matriz = 0;
	 this->pac_ccx_matriz = 0;
	//baixo
	 this->pac_by_matriz = 0;
	 this->pac_bx_matriz = 0;
	 this->pac_bby_matriz = 0;
	 this->pac_bbx_matriz = 0;
	//direita
	 this->pac_ry_matriz = 0;
	 this->pac_rx_matriz = 0;
	 this->pac_rry_matriz = 0;
	 this->pac_rrx_matriz = 0;
	//esquerda
	 this->pac_ly_matriz = 0;
	 this->pac_lx_matriz = 0;
	 this->pac_lly_matriz = 0;
	 this->pac_llx_matriz = 0;
    //pac com pilula ethis->ra��o de comer
     this->pac_py_matriz = 0;
     this->pac_px_matriz = 0;
     this->pac_ppy_matriz = 0;
     this->pac_ppx_matriz = 0;
}

void Pacman::setpacx(float x) {
	this->pac_x = x;
}
void Pacman::setpacy(float y) {
	this->pac_y = y;
}

float Pacman::getpacx() {
	return this->pac_x;
}
float Pacman::getpacy() {
	return this->pac_y;
}

void Pacman::conversao() {
    //padr�o
    this->pac_y_matriz = (pac_y) / 40;
    this->pac_x_matriz = (pac_x) / 40;
    //cima
    this->pac_cy_matriz = ceil(pac_y / 40);
    this->pac_cx_matriz = pac_x / 40;
    this->pac_ccy_matriz = ceil(pac_y / 40);
    this->pac_ccx_matriz = ceil(pac_x / 40);
    //baixo
    this->pac_by_matriz = pac_y / 40;
    this->pac_bx_matriz = ceil(pac_x / 40);
    this->pac_bby_matriz = pac_y / 40;
    this->pac_bbx_matriz = pac_x / 40;
    //direita
    this->pac_ry_matriz = ceil(pac_y / 40);
    this->pac_rx_matriz = pac_x / 40;
    this->pac_rry_matriz = pac_y / 40;
    this->pac_rrx_matriz = pac_x / 40;
    //esquerda
    this->pac_ly_matriz = ceil(pac_y / 40);
    this->pac_lx_matriz = ceil(pac_x / 40);
    this->pac_lly_matriz = pac_y / 40;
    this->pac_llx_matriz = ceil(pac_x / 40);
    //pac com pilula intera��o de comer
    this->pac_py_matriz = pac_y / 40;
    this->pac_px_matriz = pac_x / 40;
    this->pac_ppy_matriz = ceil(pac_y / 40);
    this->pac_ppx_matriz = ceil(pac_x / 40);
}

bool Pacman::cima_pacman(int **matriz) {
    if (matriz[this->pac_y_matriz][this->pac_x_matriz] != 1) {
        if (matriz[this->pac_cy_matriz - 1][this->pac_cx_matriz] != 1 && matriz[this->pac_ccy_matriz - 1][this->pac_ccx_matriz] != 1) {
            return true;
        }
        else {
            return false;
        }
    }
}
bool Pacman::baixo_pacman(int **matriz) {
    if (matriz[this->pac_y_matriz][this->pac_x_matriz] != 1) {
        if (matriz[this->pac_by_matriz + 1][this->pac_bx_matriz] != 1 && matriz[this->pac_bby_matriz + 1][this->pac_bbx_matriz] != 1) {
            return true;
        }
        else {
            return false;
        }
    }
}
bool Pacman::direita_pacman(int **matriz) {
    if (matriz[this->pac_y_matriz][this->pac_x_matriz] != 1) {
        if (matriz[this->pac_ry_matriz][this->pac_rx_matriz + 1] != 1 && matriz[this->pac_rry_matriz][this->pac_rrx_matriz + 1] != 1) {
            return true;
        }
        else {
            return false;
        }
    }
}
bool Pacman::esquerda_pacman(int **matriz) {
    if (matriz[this->pac_y_matriz][this->pac_x_matriz] != 1) {
        if (matriz[this->pac_ly_matriz][this->pac_lx_matriz - 1] != 1 && matriz[this->pac_lly_matriz][this->pac_llx_matriz - 1] != 1) {
            return true;
        }
        else {
            return false;
        }
    }
}

void Pacman::pacman_come(int** matriz, bool *direcao) {
    int x, y;
    x = 0;
    y = 0;
    if (matriz[this->pac_y_matriz][this->pac_x_matriz] == 2) {
        if (direcao[0] == true ) {
            if (matriz[this->pac_ppy_matriz][this->pac_px_matriz] == 2) {
                matriz[this->pac_ppy_matriz][this->pac_px_matriz] = 0;
                score++;
                //cout << score << endl;
            }
            //cout << "entrou" << endl;
        }
        else if (direcao[3] == true ) {
            if (matriz[this->pac_py_matriz][this->pac_ppx_matriz] == 2) {
                matriz[this->pac_py_matriz][this->pac_ppx_matriz] = 0;
                score++;
                //cout << score << endl;
            }
            //cout << "entrou2" << endl;
        }
        else {
            matriz[this->pac_py_matriz][this->pac_px_matriz] = 0;
            score++;
            //cout << score << endl;
        }
    }

    x = this->pac_x_matriz;
    y = this->pac_y_matriz;
}

int Pacman::getscore(){
    return this->score;
}

void Pacman::desenha_pacman() {
	al_draw_bitmap_region(pacman,0, 0, 40, 40, pac_x, pac_y, 0);
}

ALLEGRO_BITMAP* Pacman::getPacman() {
	return this->pacman;
}

Pacman::~Pacman() {
	al_destroy_bitmap(this->pacman);
}