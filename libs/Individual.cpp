#include <allegro5/allegro.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include "Individual.h"


using namespace std;

Individual::Individual() {
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
    
    bufferX = 0;
    bufferY = 0;

    Instrucao = 0;

    dem = 0;

    //padrao
    this->dem_y_matriz = 0;
    this->dem_x_matriz = 0;
}

void Individual::setdemx(float x) {
    Dementador::setposx(x);
}
void Individual::setdemy(float y) {
    Dementador::setposy(y);
}

float Individual::getdemx() {
    return Dementador::getposx();
}
float Individual::getdemy() {
    return Dementador::getposy();
}

void Individual::conversao() {

    Dementador::conversao();

    //padr�o
    this->dem_y_matriz = (getposy()) / 40;
    this->dem_x_matriz = (getposx()) / 40;
}

bool Individual::cima_dementador(int** matriz) {
    return Dementador::cima_obstaculo(matriz);
}

bool Individual::baixo_dementador(int** matriz) {
    return Dementador::baixo_obstaculo(matriz);
}
bool Individual::direita_dementador(int** matriz) {
    return Dementador::direita_obstaculo(matriz);
}
bool Individual::esquerda_dementador(int** matriz) {
    return Dementador::esquerda_obstaculo(matriz);
}

void Individual::desenha_dementador() {
    al_draw_bitmap_region(dementador, 0, 0, 40, 40, 
    Dementador::getposx(), Dementador::getposy(), 0);
}

void Individual::randomDir(float pacx, float pacy, int** matriz) {

    int distanciaPacX;
    int distanciaPacY;

    int direcoes[] = { ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT ,ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN };

    distanciaPacX = pacx - getdemx();
    distanciaPacY = pacy - getdemy();

    if (distanciaPacX < distanciaPacY)
    {
        if (distanciaPacX > 0)
        {
            Instrucao = direcoes[1];
            //cout << "Indo pra Direira" << endl;
        }
        else if (distanciaPacX >= 0)
        {
            if (distanciaPacY >= 0)
            {
                Instrucao = direcoes[3];
                //cout << "Indo pra Baixo" << endl;
            }
            else
            {
                Instrucao = direcoes[2];
                //cout << "Indo pra Cima" << endl;
            }
        }
        else
        {
            Instrucao = direcoes[0];
            //cout << "Indo pra Esquerda" << endl;
        }
    }
    else
    {
        if (distanciaPacY > 0)
        {
            Instrucao = direcoes[3];
            //cout << "Indo pra Baixo" << endl;
        }
        else if (distanciaPacY == 0)
        {
            if (distanciaPacX >= 0)
            {
                Instrucao = direcoes[1];
                //cout << "Indo pra Direira" << endl;
            }
            else
            {
                Instrucao = direcoes[0];
                //cout << "Indo pra Esquerda" << endl;
            }
        }
        else
        {
            Instrucao = direcoes[2];
            //cout << "Indo pra Cima" << endl;
        }
    }

    //Geração aleatória para a direção do fantasma
    if (bufferX == getdemx() && bufferY == getdemy())
    {

        int flag = 0;
        int posibilidades = 0;

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
                direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
                posibilidades++;
            }
            //Top
            if (cima_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_UP;
                posibilidades++;
            }
            //Botton
            if (baixo_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
                posibilidades++;
            }

            srand(time(NULL));

            if (posibilidades > 0)
            {
                flag = rand() % posibilidades;

                Instrucao = direcoes[flag];
            }

        }

        else if (rightdem == true)
        {

            //Right
            if (direita_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
                posibilidades++;
            }
            //Top
            if (cima_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_UP;
                posibilidades++;
            }
            //Botton
            if (baixo_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
                posibilidades++;
            }

            srand(time(NULL));

            if (posibilidades > 0)
            {
                flag = rand() % posibilidades;

                Instrucao = direcoes[flag];
            }

        }

        else if (updem == true)
        {

            //Left
            if (esquerda_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
                posibilidades++;
            }
            //Right
            if (direita_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
                posibilidades++;
            }
            //Top
            if (cima_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_UP;
                posibilidades++;
            }

            srand(time(NULL));

            if (posibilidades > 0)
            {
                flag = rand() % posibilidades;

                Instrucao = direcoes[flag];
            }

        }

        else if (downdem == true)
        {

            //Left
            if (esquerda_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
                posibilidades++;
            }
            //Right
            if (direita_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
                posibilidades++;
            }
            //Botton
            if (baixo_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
                posibilidades++;
            }

            srand(time(NULL));

            if (posibilidades > 0)
            {
                flag = rand() % posibilidades;

                Instrucao = direcoes[flag];
            }

        }

        else
        {
            //Left
            if (esquerda_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
                posibilidades++;
            }
            //Right
            if (direita_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
                posibilidades++;
            }
            //Top
            if (cima_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_UP;
                posibilidades++;
            }
            //Botton
            if (baixo_dementador(matriz) == true)
            {
                direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
                posibilidades++;
            }

            srand(time(NULL));

            if (posibilidades > 0)
            {
                flag = rand() % posibilidades;

                Instrucao = direcoes[flag];
            }
        }
    }

    bufferX = getdemx();
    bufferY = getdemy();
        if (Instrucao == ALLEGRO_KEY_UP && cima_dementador(matriz) == true && downdem != true)
        {
            updem = true;
            downdem = false;
            leftdem = false;
            rightdem = false;
        }
        //Bottom
        if (Instrucao == ALLEGRO_KEY_DOWN && baixo_dementador(matriz) == true && updem != true)
        {
            downdem = true;
            updem = false;
            leftdem = false;
            rightdem = false;

        }
        //Left
        if (Instrucao == ALLEGRO_KEY_LEFT && esquerda_dementador(matriz) == true && rightdem != true)
        {
            leftdem = true;
            updem = false;
            downdem = false;
            rightdem = false;

        }
        //Right
        if (Instrucao == ALLEGRO_KEY_RIGHT && direita_dementador(matriz) == true && leftdem != true)
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

ALLEGRO_BITMAP* Individual::getDementador() {
    return this->dementador;
}

Individual::~Individual() {
    al_destroy_bitmap(this->dementador);
}