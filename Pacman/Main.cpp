#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <allegro5/allegro_image.h>
#include "libs/tabuleiro.h"
#include "libs/bloco.h"
#include "libs/pilula.h"

#define LIN 15
#define COL 19

using namespace std;

int main() {

	al_init();
	al_init_image_addon();

	int aux;
	int **matriz;
	ifstream txtFile;

	matriz = (int**)malloc(sizeof(int*) * LIN);
	for (int i = 0; i < LIN; i++) {
		matriz[i] = (int*)malloc(sizeof(int) * COL);
	}

	txtFile.open("libs/Matriz.txt");

	for (int i = 0; i < LIN; i++) {
		for (int j = 0; j < COL; j++) {
			txtFile >> aux;
			matriz[i][j] = aux;
		}
	}

	// Debug matriz
	/*
		for (int i = 0; i < LIN; i++) {
				for (int j = 0; j < COL; j++) {
					cout << matriz[i][j] << ' ';
				}
				printf("\n");
			}
	*/

	Tabuleiro t;
	Bloco b;
	Pilula p;

	t.criar_display(760,600); // 19 - 15
	b.desenha_bloco(matriz);
	al_flip_display();
	p.desenha_pilula(matriz);

	al_rest(5.0);

	t.destroi_display();
	b.destroi_bloco();
	p.destroi_pilula();
	t.desalocar_matriz(matriz);

	return 0;
}