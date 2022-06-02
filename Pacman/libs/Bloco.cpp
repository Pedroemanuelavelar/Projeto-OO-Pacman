#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "bloco.h"

using namespace std;

Bloco::Bloco() {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 31; j++) {
			matriz[i][j] = 0;
		}
	}
	blocopng = NULL;
	blocopng = al_load_bitmap("images/bloco.png");
	if (!blocopng) {
		printf("ERRO NO BLOCO");
	}
	else {
		printf("\nBloco criado com sucesso\n");
	}
}

void Bloco::draw() {
	for (int i = 0; i < 31; i++) {
		al_draw_bitmap(blocopng, (30 * i), 0, 0);
		al_draw_bitmap(blocopng, (30 * i), 600, 0);

	}
	for (int j = 0; j < 21; j++) {
		if (j == 10) {
			j++;
		}
		al_draw_bitmap(blocopng, 0, (30 * j), 0);
		al_draw_bitmap(blocopng, 900, (30 * j), 0);
	}
	al_flip_display();
}

void Bloco::destroyDraw() {
	al_destroy_bitmap(blocopng);
}