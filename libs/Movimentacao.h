#include <allegro5/allegro.h>
#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

class Movimentacao {
	public:
		Movimentacao();
		Movimentacao(int, int);
		~Movimentacao();
		//
		void setposx(float);
		void setposy(float);
		float getposx();
		float getposy();
		//
		bool cima_obstaculo(int **matriz);
		bool baixo_obstaculo(int **matriz);
		bool direita_obstaculo(int **matriz);
		bool esquerda_obstaculo(int **matriz);
		//
		void conversao();

		ALLEGRO_BITMAP* getPacman();
	private:
		float pos_x;
		float pos_y;
		int score;
		//ALLEGRO_BITMAP* pacman;

		//padrao
		int pos_y_matriz;
		int pos_x_matriz;
		//cima
		int pos_cy_matriz;
		int pos_cx_matriz;
		int pos_ccy_matriz;
		int pos_ccx_matriz;
		//baixo
		int pos_by_matriz;
		int pos_bx_matriz;
		int pos_bby_matriz;
		int pos_bbx_matriz;
		//direita
		int pos_ry_matriz;
		int pos_rx_matriz;
		int pos_rry_matriz;
		int pos_rrx_matriz;
		//esquerda
		int pos_ly_matriz;
		int pos_lx_matriz;
		int pos_lly_matriz;
		int pos_llx_matriz;
};

#endif // !MOVIMENTACAO_H
