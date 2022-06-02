#include <allegro5/allegro5.h>
#ifndef TABULEIRO_H
#define TABULEIRO_H

class Tabuleiro {
	public:
		Tabuleiro();
		void getDisplay(int w, int h);
		void destroiDisplay();
	private:
		ALLEGRO_DISPLAY* display;
};

#endif