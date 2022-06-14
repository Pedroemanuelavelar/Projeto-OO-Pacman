#include <allegro5/allegro5.h>
#ifndef BLOCO_H
#define _CRT_SECURE_NO_DEPRECATE
#define BLOCO_H

class Bloco {
	public:
		Bloco();
		~Bloco();
		void desenha_bloco(int **matriz);
;	private:
		ALLEGRO_BITMAP* blocopng;
};

#endif // !BLOCO_H