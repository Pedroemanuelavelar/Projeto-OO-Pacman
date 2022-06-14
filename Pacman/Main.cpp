#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <allegro5/allegro_image.h>
#include "libs/tabuleiro.h"
#include "libs/bloco.h"
#include "libs/pilula.h"
#include "libs/Pacman.h"

#define LIN 15
#define COL 19
#define FPS 60

using namespace std;

int main() {

	al_init();
	al_init_image_addon();
	al_install_keyboard();

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
	Pacman pac;

	bool loop = false;

	t.criar_display(760,600); // 19 - 15

	
	al_register_event_source(t.getEventQ(), al_get_display_event_source(t.getDisplay()));//Evento da Tela

	al_register_event_source(t.getEventQ(), al_get_timer_event_source(t.getTimer()));//Evento de tempo

	al_register_event_source(t.getEventQ(), al_get_keyboard_event_source());//Evento de Teclado


	while(!loop){
		ALLEGRO_EVENT ev;
		al_wait_for_event(t.getEventQ(), &ev);

		b.desenha_bloco(matriz);
		al_flip_display();
		p.desenha_pilula(matriz);
		al_flip_display();
		pac.desenha_pacman();

		al_flip_display();

		if(ev.keyboard.keycode == ALLEGRO_KEY_Q){
			loop = true;
		}
	}        
	t.desalocar_matriz(matriz);

	return 0;
}