#include <allegro5/allegro5.h>
#ifndef PILULA_H
#define PILULA_H

class Pilula {
	public:
		Pilula();
		~Pilula();
		void desenha_pilula(int **matriz);
	private:
		ALLEGRO_BITMAP* pilula;
};

#endif