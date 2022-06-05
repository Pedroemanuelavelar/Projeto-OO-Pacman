#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "bloco.h"

#define LIN 15
#define COL 19

using namespace std;

Bloco::Bloco() {

	blocopng = NULL;
	blocopng = al_load_bitmap("images/bloco.png");
	if (!blocopng) {
		printf("ERRO NO BLOCO");
	}
	else {
		printf("\nBloco criado com sucesso\n");
	}
}

void Bloco::desenha_bloco(int **matriz) {

	for (int i = 0; i < LIN; i++) {
		for (int j = 0; j < COL; j++) {
			if(matriz[i][j] == 1){
				al_draw_bitmap(blocopng, (j * 40), (40 * i), 0);
			}
		}
	}
	al_flip_display();
}

void Bloco::destroi_bloco() {
	al_destroy_bitmap(blocopng);
}