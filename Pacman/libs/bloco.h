#include <allegro5/allegro5.h>
#ifndef BLOCO_H
#define _CRT_SECURE_NO_DEPRECATE
#define BLOCO_H

#define LIN 15
#define COL 19

class Bloco {
	public:
		Bloco();
		void draw();
		void destroyDraw();
		void preencherMatriz();
;	private:
		ALLEGRO_BITMAP* blocopng;
		int matriz[LIN][COL];
};

#endif // !BLOCO_H