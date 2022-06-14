#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include "tabuleiro.h"

#define FPS 60

using namespace std;

Tabuleiro::Tabuleiro() {
	display = NULL;
	event_queue = NULL;
	timer = NULL;
	timer = al_create_timer(1.0 / FPS);
	event_queue = al_create_event_queue();
	if(!timer){
		printf("\nERRO NO TIMER");
		return;
	}
	if(!event_queue){
		printf("\nERRO NA FILA DE EVENTOS");
		return;
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

ALLEGRO_TIMER * Tabuleiro::getTimer(){
	return this->timer;
}

ALLEGRO_EVENT_QUEUE * Tabuleiro::getEventQ(){
	return this->event_queue;
}

ALLEGRO_DISPLAY* Tabuleiro::getDisplay(){
	return this->display;
}

void Tabuleiro::desalocar_matriz(int** matriz) {
	for (int i = 0; i < 15; i++) {
		free(matriz[i]);
	}
	free(matriz);
}

Tabuleiro::~Tabuleiro(){
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
}