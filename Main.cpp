#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include "./libs/Bloco.h"
#include "./libs/Pilula.h"
#include "./libs/Pacman.h"

#define COL 19 
#define LIN 15
#define FPS 60

enum DIRECAO { CIMA, BAIXO, DIREITA, ESQUERDA };
bool direcao[] = { false, false, false, false };

enum STATE { MENU, PLAYING };

using namespace std;

int main(int argc, char** argv){
    
    al_init();
    al_install_keyboard();//Funcoes Teclado
    al_init_image_addon();//Imagens
    al_init_ttf_addon(); // Fonte
    al_init_font_addon(); // Fonte
    al_install_audio(); // audio
    al_init_acodec_addon(); // audio
    al_reserve_samples(1); // audio

	int aux;
	int** matriz;
	ifstream txtFile;

    matriz = (int**)malloc(sizeof(int*) * LIN);
    for (int i = 0; i < LIN; i++) {
        matriz[i] = (int*)malloc(sizeof(int) * COL);
    }

    txtFile.open("libs/Matriz.txt");

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            txtFile >> aux;
            matriz[i][j] = aux;
        }
    }

    /*
    DEGUG
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d x:%d , y:%d\n", matriz[i][j], j, i);
        }
        printf("\n");
    }*/

    Bloco b;
    Pilula p;
    Pacman pac;

    ALLEGRO_FONT* font = NULL;
    ALLEGRO_FONT* fontInitScr = NULL;
    ALLEGRO_FONT* fontFooterScr = NULL;
    ALLEGRO_BITMAP * logopng = NULL;
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_SAMPLE *sample=NULL;
    ALLEGRO_SAMPLE_INSTANCE *instance = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
    ALLEGRO_TIMER* timer = NULL;

    int proximoMovimento = 0;
    bool teclas[255] = { false };
    font = al_load_font("./fonts/harry.ttf", 30, 0);
    fontInitScr = al_load_font("./fonts/dogicapixel.ttf", 14, 0);
    fontFooterScr = al_load_font("./fonts/dogicapixel.ttf", 11, 0);

    // State variables
    int state = MENU;

    if (!al_init()) {
        fprintf(stderr, "failed to initialize allegro!\n");
        return -1;
    }

    timer = al_create_timer(1.0 / FPS);

    if (!timer) {
        fprintf(stderr, "failed to create timer!\n");
        return -1;
    };

    display = al_create_display(900, 600);
    if (!display) {
        fprintf(stderr, "failed to create display!\n");
        al_destroy_timer(timer);
        return -1;
    }

    event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_display_event_source(display));//Evento da Tela

    al_register_event_source(event_queue, al_get_timer_event_source(timer));//Evento de tempo

    al_register_event_source(event_queue, al_get_keyboard_event_source());//Evento de Teclado

    al_start_timer(timer);

    bool re_desenha = true;
    bool termina = false;

    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    bool space = false;

    int lado = 0; 

    // int logopng;

    int sprite = 0, fator = 1;
    int tempo, miliseg = 200;
    float pac_x = 40;
    float pac_y = 40;

    al_clear_to_color(al_map_rgb(21, 10, 0));//Quantidade de Audios

    sample = al_load_sample( "audios/harrysong.wav" );
    instance = al_create_sample_instance(sample);

    al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());

    if (!sample){
        printf( "Audio clip sample not loaded!\n" ); 
        return -1;
    }

    while (!termina){

        pac.conversao();
        pac.pacman_come(matriz, direcao);

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        tempo = al_get_timer_count(timer);

        if (ev.type == ALLEGRO_EVENT_TIMER) {

            if (tempo == (FPS * miliseg) / 1000) {
                al_set_timer_count(timer, 0);
                sprite = sprite + fator; 
                if (sprite == 0) fator = 1;
                if (sprite == 5) fator = -1;
            }

            // cout << "Sprite: " << sprite << endl;


            if (teclas[ALLEGRO_KEY_UP]){
                proximoMovimento = ALLEGRO_KEY_UP;
            }
            if (teclas[ALLEGRO_KEY_DOWN]){
                proximoMovimento = ALLEGRO_KEY_DOWN;
            }
            if (teclas[ALLEGRO_KEY_LEFT]){
                proximoMovimento = ALLEGRO_KEY_LEFT;
            }
            if (teclas[ALLEGRO_KEY_RIGHT]){
                proximoMovimento = ALLEGRO_KEY_RIGHT;
            }
            // Space
            /*if (teclas[ALLEGRO_KEY_SPACE]){
                return true;
            }*/
            
           if (state == MENU) {
                if (teclas[ALLEGRO_KEY_SPACE]) 
                    state = PLAYING;
           }

            if(proximoMovimento == ALLEGRO_KEY_UP && pac.cima_pacman(matriz) == true) {

                up = true;
                down = false;
                left = false;
                right = false;

                lado = 3;

                direcao[CIMA] = true;
                direcao[BAIXO] = false;
                direcao[DIREITA] = false;
                direcao[ESQUERDA] = false;

            } else if(proximoMovimento == ALLEGRO_KEY_DOWN && pac.baixo_pacman(matriz) == true) {

                up = false;
                down = true;
                left = false;
                right = false;

                lado = 0;

                direcao[CIMA] = false;
                direcao[BAIXO] = true;
                direcao[DIREITA] = false;
                direcao[ESQUERDA] = false;


            }else if(proximoMovimento == ALLEGRO_KEY_LEFT && pac.esquerda_pacman(matriz) == true) {

                up = false;
                down = false;
                left = true;
                right = false;

                lado = 1;

                direcao[CIMA] = false;
                direcao[BAIXO] = false;
                direcao[DIREITA] = false;
                direcao[ESQUERDA] = true;


            }else if(proximoMovimento == ALLEGRO_KEY_RIGHT && pac.direita_pacman(matriz) == true) {

                up = false;
                down = false;
                left = false;
                right = true;

                lado = 2;

                direcao[CIMA] = false;
                direcao[BAIXO] = false;
                direcao[DIREITA] = true;
                direcao[ESQUERDA] = false;

            }

            if (up == true && pac.cima_pacman(matriz) == true) {
                pac.setpacy(pac.getpacy() - 2.0);
            }

            if (down == true && pac.baixo_pacman(matriz) == true) {
                pac.setpacy(pac.getpacy() + 2.0);
            }

            if (left == true && pac.esquerda_pacman(matriz) == true) {
                pac.setpacx(pac.getpacx() - 2.0);
            }

            if (right == true && pac.direita_pacman(matriz) == true) {
                pac.setpacx(pac.getpacx() + 2.0);
            }

            re_desenha = true;
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) { //Tecla X Apertada
            teclas[ev.keyboard.keycode] = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP) { //Tecla X Liberada
            teclas[ev.keyboard.keycode] = false;
            if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                termina = true;
            }
                
        }
        if (re_desenha && al_is_event_queue_empty(event_queue)) { //Redesenha se a fila de eventos esta vazia

            re_desenha = false;
            p.~Pilula();
            b.~Bloco();
            al_clear_to_color(al_map_rgb(21, 10, 0));
            p.desenha_pilula(matriz);
            b.desenha_bloco(matriz);
            al_draw_text(font, al_map_rgb(255, 255, 0), 800, 1, 0, "Score");
            al_draw_textf(font, al_map_rgb(255, 255, 0), 814, 40, NULL,"%d",pac.getscore());
            pac.desenha_pacman(sprite, lado);

            if (state == MENU) {

                al_clear_to_color(al_map_rgb(21, 10, 0));

               al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
               
                logopng = al_load_bitmap("images/logo.png");
                al_draw_bitmap(logopng,175,20,0); 

                   
                     // contador
                    if (tempo > 50 ) 
                        tempo=0; 
                    
                    if (tempo < 25 )
                    // cout << "tempo: " << tempo << endl; 
                    al_draw_text(fontInitScr, al_map_rgb(255, 255, 255), 275, 340, 0,"PRESS (SPACE) TO START GAME");
                
                al_draw_text(fontFooterScr, al_map_rgb(255, 255, 0), 146, 570, 0,"© 2022 - PacPotter, By: Carlos Eduado, Vinicius do Carmo e Pedro Emanuel ");
                // cout << "Tela Inicial!!" << endl;
            } 

            al_flip_display();
        }
    }

    //Destroi componentes
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_sample(sample);
    al_destroy_sample_instance(instance);
    al_destroy_bitmap(logopng);
    al_destroy_font(font);
    al_destroy_font(fontInitScr);
    al_destroy_font(fontFooterScr);

    for (int i = 0; i < 15; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}