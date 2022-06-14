#include <allegro5/allegro5.h>
#ifndef TABULEIRO_H
#define TABULEIRO_H

class Tabuleiro {
	public:
		Tabuleiro();
		~Tabuleiro();
		void criar_display(int w, int h);
		void desalocar_matriz(int **matriz);
		ALLEGRO_TIMER * getTimer();
		ALLEGRO_EVENT_QUEUE *getEventQ();
		ALLEGRO_DISPLAY* getDisplay();
		
	private:
		ALLEGRO_DISPLAY* display;
		ALLEGRO_EVENT_QUEUE *event_queue;
		ALLEGRO_TIMER *timer;
};

#endif