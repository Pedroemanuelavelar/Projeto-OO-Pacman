#include <allegro5/allegro.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "Pacman.h"

using namespace std;


Pacman::Pacman() {
	this->pacman = NULL;
	this->pacman = al_load_bitmap("pacman.png");
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
	int pac_y_matriz = 0;
	int pac_x_matriz = 0;
	//cima
	int pac_cy_matriz = 0;
	int pac_cx_matriz = 0;
	int pac_ccy_matriz = 0;
	int pac_ccx_matriz = 0;
	//baixo
	int pac_by_matriz = 0;
	int pac_bx_matriz = 0;
	int pac_bby_matriz = 0;
	int pac_bbx_matriz = 0;
	//direita
	int pac_ry_matriz = 0;
	int pac_rx_matriz = 0;
	int pac_rry_matriz = 0;
	int pac_rrx_matriz = 0;
	//esquerda
	int pac_ly_matriz = 0;
	int pac_lx_matriz = 0;
	int pac_lly_matriz = 0;
	int pac_llx_matriz = 0;
    //pac com pilula intera��o de comer
    int pac_py_matriz = 0;
    int pac_px_matriz = 0;
    int pac_ppy_matriz = 0;
    int pac_ppx_matriz = 0;
}

void Pacman::setpacx(float x) {
	pac_x = x;
}
void Pacman::setpacy(float y) {
	pac_y = y;
}

float Pacman::getpacx() {
	return pac_x;
}
float Pacman::getpacy() {
	return pac_y;
}

void Pacman::conversao() {
    //padr�o
    pac_y_matriz = (pac_y) / 40;
    pac_x_matriz = (pac_x) / 40;
    //cima
    pac_cy_matriz = ceil(pac_y / 40);
    pac_cx_matriz = pac_x / 40;
    pac_ccy_matriz = ceil(pac_y / 40);
    pac_ccx_matriz = ceil(pac_x / 40);
    //baixo
    pac_by_matriz = pac_y / 40;
    pac_bx_matriz = ceil(pac_x / 40);
    pac_bby_matriz = pac_y / 40;
    pac_bbx_matriz = pac_x / 40;
    //direita
    pac_ry_matriz = ceil(pac_y / 40);
    pac_rx_matriz = pac_x / 40;
    pac_rry_matriz = pac_y / 40;
    pac_rrx_matriz = pac_x / 40;
    //esquerda
    pac_ly_matriz = ceil(pac_y / 40);
    pac_lx_matriz = ceil(pac_x / 40);
    pac_lly_matriz = pac_y / 40;
    pac_llx_matriz = ceil(pac_x / 40);
    //pac com pilula intera��o de comer
    pac_py_matriz = pac_y / 40;
    pac_px_matriz = pac_x / 40;
    pac_ppy_matriz = ceil(pac_y / 40);
    pac_ppx_matriz = ceil(pac_x / 40);
}

bool Pacman::cima_pacman(int **matriz) {
    if (matriz[pac_y_matriz][pac_x_matriz] != 1) {
        if (matriz[pac_cy_matriz - 1][pac_cx_matriz] != 1 && matriz[pac_ccy_matriz - 1][pac_ccx_matriz] != 1) {
            return true;
        }
        else {
            return false;
        }
    }
}
bool Pacman::baixo_pacman(int **matriz) {
    if (matriz[pac_y_matriz][pac_x_matriz] != 1) {

        if (matriz[pac_by_matriz + 1][pac_bx_matriz] != 1 && matriz[pac_bby_matriz + 1][pac_bbx_matriz] != 1) {
            return true;
        }
        else {
            return false;
        }
    }
}
bool Pacman::direita_pacman(int **matriz) {
    if (matriz[pac_y_matriz][pac_x_matriz] != 1) {
        if (matriz[pac_ry_matriz][pac_rx_matriz + 1] != 1 && matriz[pac_rry_matriz][pac_rrx_matriz + 1] != 1) {
            return true;
        }
        else {
            return false;
        }
    }
}
bool Pacman::esquerda_pacman(int **matriz) {
    if (matriz[pac_y_matriz][pac_x_matriz] != 1) {
        if (matriz[pac_ly_matriz][pac_lx_matriz - 1] != 1 && matriz[pac_lly_matriz][pac_llx_matriz - 1] != 1) {
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
    if (matriz[pac_y_matriz][pac_x_matriz] == 2) {
        if (direcao[0] == true ) {
            if (matriz[pac_ppy_matriz][pac_px_matriz] == 2) {
                matriz[pac_ppy_matriz][pac_px_matriz] = 0;
                score++;
                cout << score << endl;
            }
            //cout << "entrou" << endl;
        }
        else if (direcao[3] == true ) {
            if (matriz[pac_py_matriz][pac_ppx_matriz] == 2) {
                matriz[pac_py_matriz][pac_ppx_matriz] = 0;
                score++;
                cout << score << endl;
            }
            //cout << "entrou2" << endl;
        }
        else {
            matriz[pac_py_matriz][pac_px_matriz] = 0;
            score++;
            cout << score << endl;
        }
    }

    x = pac_x_matriz;
    y = pac_y_matriz;
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