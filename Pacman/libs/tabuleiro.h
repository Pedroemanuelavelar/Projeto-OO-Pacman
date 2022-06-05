#include <allegro5/allegro5.h>
#ifndef TABULEIRO_H
#define TABULEIRO_H

class Tabuleiro {
	public:
		Tabuleiro();
		void criar_display(int w, int h);
		void destroi_display();
		void desalocar_matriz(int **matriz);
	private:
		ALLEGRO_DISPLAY* display;
};

#endif