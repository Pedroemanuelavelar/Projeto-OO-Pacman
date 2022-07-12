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

    score = 0;

	//padrao
	 this->pac_y_matriz = 0;
	 this->pac_x_matriz = 0;
    //pac com pilula ethis->ra��o de comer
     this->pac_py_matriz = 0;
     this->pac_px_matriz = 0;
     this->pac_ppy_matriz = 0;
     this->pac_ppx_matriz = 0;
}

void Pacman::setpacx(float x) {
    Movimentacao::setposx(x);
}
void Pacman::setpacy(float y) {
    Movimentacao::setposy(y);
}

float Pacman::getpacx() {
	return Movimentacao::getposx();
}
float Pacman::getpacy() {
	return Movimentacao::getposy();
}

void Pacman::conversao() {

    Movimentacao::conversao();

    //padr�o
    this->pac_y_matriz = (getposy()) / 40;
    this->pac_x_matriz = (getposx()) / 40;
    //pac com pilula intera��o de comer
    this->pac_py_matriz = Movimentacao::getposy() / 40;
    this->pac_px_matriz = Movimentacao::getposx() / 40;
    this->pac_ppy_matriz = ceil(Movimentacao::getposy() / 40);
    this->pac_ppx_matriz = ceil(Movimentacao::getposx() / 40);
}

bool Pacman::cima_pacman(int **matriz) {
    return Movimentacao::cima_obstaculo(matriz);
}
bool Pacman::baixo_pacman(int **matriz) {
    return Movimentacao::baixo_obstaculo(matriz);
}
bool Pacman::direita_pacman(int **matriz) {
    return Movimentacao::direita_obstaculo(matriz);
}
bool Pacman::esquerda_pacman(int **matriz) {
    return Movimentacao::esquerda_obstaculo(matriz);
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

void Pacman::desenha_pacman(int sprite, int dir) {

	al_draw_bitmap_region(pacman,sprite*40, dir*40, 40, 40, Movimentacao::getposx(), Movimentacao::getposy(), 0);
}

ALLEGRO_BITMAP* Pacman::getPacman() {
	return this->pacman;
}

Pacman::~Pacman() {
	al_destroy_bitmap(this->pacman);
}