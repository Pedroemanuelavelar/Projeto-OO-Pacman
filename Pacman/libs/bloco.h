#include <allegro5/allegro5.h>
#ifndef BLOCO_H
#define BLOCO_H

class Bloco {
	public:
		Bloco();
		void draw();
		void destroyDraw();
;	private:
		ALLEGRO_BITMAP* blocopng;
};

#endif // !BLOCO_H