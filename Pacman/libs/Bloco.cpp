#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <fstream>
#include <iomanip>
#include <allegro5/allegro_image.h>
#include "bloco.h"

#define LIN 15
#define COL 19

using namespace std;

Bloco::Bloco() {

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 19; j++) {
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

	for (int i = 0; i < LIN; i++) {
		for (int j = 0; j < COL; j++) {

			if(matriz[i][j] == 1){
				al_draw_bitmap(blocopng, (j * 30), (30 * i), 0);
			}
		}
	}
	al_flip_display();
}

void Bloco::preencherMatriz() {
	
	int aux;

	ifstream txtFile;

	txtFile.open("libs/Matriz.txt");

	for (int i = 0; i < LIN; i++) {
		for (int j = 0; j < COL; j++) {
			txtFile >> aux;
			matriz[i][j] = aux;
		}
	}

	for (int i = 0; i < LIN; i++) {
		for (int j = 0; j < COL; j++) {

			cout << matriz[i][j] << ' ';
		}
		printf("\n");
	}
}

void Bloco::destroyDraw() {
	al_destroy_bitmap(blocopng);
}