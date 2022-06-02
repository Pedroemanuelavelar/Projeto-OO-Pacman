#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "tabuleiro.h"
#include "bloco.h"

using namespace std;

Bloco::Bloco() {
	blocopng = NULL;
	blocopng = al_load_bitmap("bloco.png");
	if (!blocopng) {
		printf("ERRO NO BLOCO");
	}
}

void Bloco::draw() {
	al_draw_bitmap(blocopng, 200, 200, 0);
	al_flip_display();
}

void Bloco::destroyDraw() {
	al_destroy_bitmap(blocopng);
}