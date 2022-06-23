#include <allegro5/allegro.h>

#ifndef BLOCO_H
#define BLOCO_H

class Bloco {
	public:
		Bloco();
		~Bloco();
		void desenha_bloco(int** matriz);
		ALLEGRO_BITMAP * getBloco();
	private:
		ALLEGRO_BITMAP* blocopng;
};	

#endif // DEBUG
