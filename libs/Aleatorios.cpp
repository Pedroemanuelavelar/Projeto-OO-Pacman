#include <allegro5/allegro.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include "Aleatorios.h"

using namespace std;

Aleatoria::Aleatoria() {
    this->dementador = NULL;
    this->dementador = al_load_bitmap("images/dementador.png");
    if (!this->dementador) {
        printf("ERRO NO Dementador");
    }
    else {
        printf("\nDementador criado com sucesso!\n");
    }

    updem = false;
    downdem = false;
    leftdem = false;
    rightdem = false;

    direcaodem[1] = 0;
    dem = 0;

    nextMov = 0;

    //padrao
    this->dem_y_matriz = 0;
    this->dem_x_matriz = 0;
}

void Aleatoria::setdemx(float x) {
    Dementador::setposx(x);
}
void Aleatoria::setdemy(float y) {
    Dementador::setposy(y);
}

float Aleatoria::getdemx() {
    return Dementador::getposx();
}
float Aleatoria::getdemy() {
    return Dementador::getposy();
}

void Aleatoria::conversao() {

    Dementador::conversao();

    //padr�o
    this->dem_y_matriz = (getposy()) / 40;
    this->dem_x_matriz = (getposx()) / 40;
}

bool Aleatoria::cima_dementador(int** matriz) {
    return Dementador::cima_obstaculo(matriz);
}

bool Aleatoria::baixo_dementador(int** matriz) {
    return Dementador::baixo_obstaculo(matriz);
}
bool Aleatoria::direita_dementador(int** matriz) {
    return Dementador::direita_obstaculo(matriz);
}
bool Aleatoria::esquerda_dementador(int** matriz) {
    return Dementador::esquerda_obstaculo(matriz);
}

void Aleatoria::desenha_dementador() {
    al_draw_bitmap_region(dementador, 0, 0, 40, 40, 
    Dementador::getposx(), Dementador::getposy(), 0);
}

void Aleatoria::randomDir(float pacx, float pacy, int** matriz) {

    //Geração aleatória para a direção do fantasma

    int flag = 0;
    int possible = 0;

    int direcoes[4];

    for (int i = 0; i < 4; i++)
    {
        direcoes[i] = 0;
    }

    if (leftdem == true)
    {

        //Left
        if (esquerda_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_LEFT;
            possible++;
        }
        //Top
        if (cima_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_UP;
            possible++;
        }
        //Botton
        if (baixo_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_DOWN;
            possible++;
        }

        srand(time(NULL));

        if (possible > 0)
        {
            flag = rand() % possible;

            nextMov = direcoes[flag];
        }

    }

    else if (rightdem == true)
    {

        //Right
        if (direita_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_RIGHT;
            possible++;
        }
        //Top
        if (cima_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_UP;
            possible++;
        }
        //Botton
        if (baixo_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_DOWN;
            possible++;
        }

        srand(time(NULL));

        if (possible > 0)
        {
            flag = rand() % possible;

            nextMov = direcoes[flag];
        }

    }

    else if (updem == true)
    {

        //Left
        if (esquerda_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_LEFT;
            possible++;
        }
        //Right
        if (direita_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_RIGHT;
            possible++;
        }
        //Top
        if (cima_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_UP;
            possible++;
        }

        srand(time(NULL));

        if (possible > 0)
        {
            flag = rand() % possible;

            nextMov = direcoes[flag];
        }

    }

    else if (downdem == true)
    {

        //Left
        if (esquerda_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_LEFT;
            possible++;
        }
        //Right
        if (direita_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_RIGHT;
            possible++;
        }
        //Botton
        if (baixo_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_DOWN;
            possible++;
        }

        srand(time(NULL));

        if (possible > 0)
        {
            flag = rand() % possible;

            nextMov = direcoes[flag];
        }

    }

    else
    {
        //Left
        if (esquerda_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_LEFT;
            possible++;
        }
        //Right
        if (direita_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_RIGHT;
            possible++;
        }
        //Top
        if (cima_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_UP;
            possible++;
        }
        //Botton
        if (baixo_dementador(matriz) == true)
        {
            direcoes[possible] = ALLEGRO_KEY_DOWN;
            possible++;
        }

        srand(time(NULL));

        if (possible > 0)
        {
            flag = rand() % possible;

            nextMov = direcoes[flag];
        }
    }
        if (nextMov == ALLEGRO_KEY_UP && cima_dementador(matriz) == true && downdem != true)
        {
            updem = true;
            downdem = false;
            leftdem = false;
            rightdem = false;
        }
        //Bottom
        if (nextMov == ALLEGRO_KEY_DOWN && baixo_dementador(matriz) == true && updem != true)
        {
            downdem = true;
            updem = false;
            leftdem = false;
            rightdem = false;

        }
        //Left
        if (nextMov == ALLEGRO_KEY_LEFT && esquerda_dementador(matriz) == true && rightdem != true)
        {
            leftdem = true;
            updem = false;
            downdem = false;
            rightdem = false;

        }
        //Right
        if (nextMov == ALLEGRO_KEY_RIGHT && direita_dementador(matriz) == true && leftdem != true)
        {
            rightdem = true;
            updem = false;
            downdem = false;
            leftdem = false;
        }

        //Movi do dementador
        if (updem == true && cima_dementador(matriz) == true) {
            setdemy(getdemy() - 2.0);
        }

        if (downdem == true && baixo_dementador(matriz) == true) {
            setdemy(getdemy() + 2.0);
        }

        if (leftdem == true && esquerda_dementador(matriz) == true) {
            setdemx(getdemx() - 2.0);
        }

        if (rightdem == true && direita_dementador(matriz) == true) {
            setdemx(getdemx() + 2.0);
        }

}

ALLEGRO_BITMAP* Aleatoria::getDementador() {
    return this->dementador;
}

Aleatoria::~Aleatoria() {
    al_destroy_bitmap(this->dementador);
}