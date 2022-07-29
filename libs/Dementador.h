#include <allegro5/allegro.h>
#ifndef DEMENTADOR_H
#define DEMENTADOR_H

#include "Movimentacao.h"

class Dementador : public Movimentacao {
public:
	Dementador();
	~Dementador();
	//
	void desenha_dementador();
	virtual void randomDir(float, float, int** matriz); 
	//
	void setdemx(float);
	void setdemy(float);
	float getdemx();
	float getdemy();
	//
	bool cima_dementador(int** matriz);
	bool baixo_dementador(int** matriz);
	bool direita_dementador(int** matriz);
	bool esquerda_dementador(int** matriz);
	//
	void conversao();

	ALLEGRO_BITMAP* getDementador();
private:
	ALLEGRO_BITMAP* dementador;

	//padrao
	int dem_y_matriz;
	int dem_x_matriz;
	int dem;

	bool updem, downdem, leftdem, rightdem;
	bool direcaodem[1];
};

#endif // !DEMENTADOR_H
