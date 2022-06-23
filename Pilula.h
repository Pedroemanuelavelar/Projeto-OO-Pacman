#include <allegro5/allegro.h>
#ifndef PILULA_H
#define PILULA_H

class Pilula {
	public:
		Pilula();
		~Pilula();
		ALLEGRO_BITMAP* getPilula();
		void desenha_pilula(int** matriz);
	private:
		ALLEGRO_BITMAP* pilulapng;
};
#endif