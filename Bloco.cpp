#include <allegro5/allegro.h>
#include <stdio.h>
#include <stdlib.h>
#include "Bloco.h"

#define LIN 15
#define COL 21

Bloco::Bloco() {
	this->blocopng = NULL;
	if (!blocopng) {
		printf("ERRO NO BLOCO");
	}
	else {
		printf("\nBloco criado com sucesso!\n");
	}
}

void Bloco::desenha_bloco(int** matriz) {
	this->blocopng = al_load_bitmap("bloco.png");
	for (int i = 0; i < LIN; i++) {
		for (int j = 0; j < COL; j++) {
			if (matriz[i][j] == 1) {
				al_draw_bitmap(blocopng, (j * 40), (40 * i), 0);
			}
		}
	}
	
	//al_flip_display();
}

ALLEGRO_BITMAP* Bloco::getBloco() {
	return this->blocopng;
}

Bloco::~Bloco() {
	al_destroy_bitmap(this->blocopng);
}