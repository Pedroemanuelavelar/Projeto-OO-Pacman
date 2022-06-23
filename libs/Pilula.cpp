#include <allegro5/allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "Pilula.h"

#define LIN 15
#define COL 19

Pilula::Pilula() {
	this->pilulapng = NULL;
	if (!pilulapng) {
		printf("ERRO NA PILULA");
	}
	else {
		printf("\nPilula criado com sucesso!\n");
	}
}

void Pilula::desenha_pilula(int** matriz) {
	this->pilulapng = al_load_bitmap("images/pilula.png");
	for (int i = 0; i < LIN; i++) {
		for (int j = 0; j < COL; j++) {
			if (matriz[i][j] == 2) {
				al_draw_bitmap(this->pilulapng, (j * 40), (40 * i), 0);
			}
		}
	}
	//al_flip_display();
}

ALLEGRO_BITMAP* Pilula::getPilula() {
	return this->pilulapng;
}

Pilula::~Pilula() {
	al_destroy_bitmap(this->pilulapng);
}