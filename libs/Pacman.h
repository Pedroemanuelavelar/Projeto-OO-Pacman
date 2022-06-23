#include <allegro5/allegro.h>
#ifndef PACMAN_H
#define PACMAN_H

class Pacman {
	public:
		Pacman();
		~Pacman();
		//
		void desenha_pacman();
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
		float pac_x;
		float pac_y;
		int score;
		ALLEGRO_BITMAP* pacman;

		//padrao
		int pac_y_matriz;
		int pac_x_matriz;
		//cima
		int pac_cy_matriz;
		int pac_cx_matriz;
		int pac_ccy_matriz;
		int pac_ccx_matriz;
		//baixo
		int pac_by_matriz;
		int pac_bx_matriz;
		int pac_bby_matriz;
		int pac_bbx_matriz;
		//direita
		int pac_ry_matriz;
		int pac_rx_matriz;
		int pac_rry_matriz;
		int pac_rrx_matriz;
		//esquerda
		int pac_ly_matriz;
		int pac_lx_matriz;
		int pac_lly_matriz;
		int pac_llx_matriz;
		//pac com pilula intera��o de comer
		int pac_py_matriz;
		int pac_px_matriz;
		int pac_ppy_matriz;
		int pac_ppx_matriz;
};

#endif // !PACMAN_H
