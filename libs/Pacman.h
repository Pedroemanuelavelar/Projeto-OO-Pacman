#include <allegro5/allegro.h>
#ifndef PACMAN_H
#define PACMAN_H

#include "Movimentacao.h"

class Pacman : public Movimentacao{
	public:
		Pacman();
		~Pacman();
		//
		void desenha_pacman(int, int);
		//
		void setpacx(float);
		void setpacy(float);
		float getpacx();
		float getpacy();
		int getscore();
		//
		
		bool cima_pacman(int **matriz);
		bool baixo_pacman(int **matriz);
		bool direita_pacman(int **matriz);
		bool esquerda_pacman(int **matriz);
		
		//
		void pacman_come(int** matriz, bool *direcao);
		//
		void conversao();

		ALLEGRO_BITMAP* getPacman();
	private:
		int score;
		ALLEGRO_BITMAP* pacman;

		//padrao
		int pac_y_matriz;
		int pac_x_matriz;
		//pac com pilula intera��o de comer
		int pac_py_matriz;
		int pac_px_matriz;
		int pac_ppy_matriz;
		int pac_ppx_matriz;
};

#endif // !PACMAN_H
