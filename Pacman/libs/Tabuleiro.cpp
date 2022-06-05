#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include "tabuleiro.h"

using namespace std;

Tabuleiro::Tabuleiro() {
	display = NULL;
	if (!display) {
		printf("\n\nTabuleiro criado com sucesso!");
	}
}

void Tabuleiro::criar_display(int w, int h) {
	display = al_create_display(w, h);

	if (display == NULL) {
		printf("ERRO no display");
		return;
	}
	al_clear_to_color(al_map_rgb(21, 10, 0));
	al_flip_display(); 
	al_flip_display();
}

void Tabuleiro::desalocar_matriz(int** matriz) {
	for (int i = 0; i < 15; i++) {
		free(matriz[i]);
	}
	free(matriz);
}

void Tabuleiro::destroi_display() {
	al_destroy_display(display); //Destroi a tela
}