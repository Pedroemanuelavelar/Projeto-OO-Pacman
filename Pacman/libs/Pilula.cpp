#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include "pilula.h"

#define LIN 15
#define COL 19

Pilula::Pilula() {
	pilula = NULL;
	pilula = al_load_bitmap("images/pilula.png");
	if (!pilula) {
		printf("ERRO NA PILULA");
	}
	else {
		printf("Pilula criada com sucesso!");
	}
}

void Pilula::desenha_pilula(int **matriz) {
	for (int i = 0; i < LIN; i++) {
		for (int j = 0; j < COL; j++) {
			if (matriz[i][j] == 2) {
				al_draw_bitmap(pilula, (j * 40), (40 * i), 0);
			}
		}
	}
	al_flip_display();
}

Pilula::~Pilula(){
	al_destroy_bitmap(pilula);
}