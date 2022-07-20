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
#include <time.h>
#include <math.h>
#include "./libs/Bloco.h"
#include "./libs/Pilula.h"
#include "./libs/Pacman.h"
#include "./libs/Dementador.h"
#include "./libs/Movimentacao.h"

#define COL 19 
#define LIN 15
#define FPS 60

enum DIRECAO { CIMA, BAIXO, DIREITA, ESQUERDA };
bool direcao[] = { false, false, false, false };

enum DIRECAODEM { CIMADEM, BAIXODEM, DIREITADEM, ESQUERDADEM };
bool direcaodem[] = { false, false, false, false };

enum STATE { MENU, PLAYING, GAMEOVER };

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
    Dementador demons[4];

    ALLEGRO_FONT* font = NULL;
    ALLEGRO_FONT* fontInitScr = NULL;
    ALLEGRO_FONT* fontFooterScr = NULL;
    ALLEGRO_FONT* fontEndScr = NULL;
    ALLEGRO_BITMAP * logopng = NULL;
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_SAMPLE *sample=NULL;
    ALLEGRO_SAMPLE_ID *sample_id;
    ALLEGRO_SAMPLE_INSTANCE *instance = NULL;
    ALLEGRO_SAMPLE *sample2=NULL;
    ALLEGRO_SAMPLE_INSTANCE *instance2 = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
    ALLEGRO_TIMER* timer = NULL;
    



    int proximoMovimento = 0;
    bool teclas[255] = { false };
    font = al_load_font("./fonts/harry.ttf", 30, 0);
    fontInitScr = al_load_font("./fonts/dogicapixel.ttf", 14, 0);
    fontFooterScr = al_load_font("./fonts/dogicapixel.ttf", 11, 0);
    fontEndScr = al_load_font("./fonts/harry.ttf", 72, 0);
    

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

    bool updem = false;
    bool downdem = false;
    bool leftdem = false;
    bool rightdem = false;
    bool spacedem = false;

    int lado = 0; 

    for(int i = 0, j = 8; i < 4; i++, j++){
        if(j == 11){
            j--;
            demons[i].setposy(40 * 6);
        }else{
            demons[i].setposy(40 * 7);
        }
        demons[i].setposx(40 * j);
    }

    int sprite = 0, fator = 1;
    int t = 0,tempo, miliseg = 200;
    float pac_x = 40;
    float pac_y = 40;

    al_clear_to_color(al_map_rgb(21, 10, 0));

    sample = al_load_sample( "./audios/harrysong.wav" );
    instance = al_create_sample_instance(sample);

    sample2 = al_load_sample( "./audios/gameover.wav" );
    instance2 = al_create_sample_instance(sample2);


    al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(instance2, al_get_default_mixer());


    if (!sample){
        printf( "Audio clip sample not loaded!\n" ); 
        return -1;
    }

    if(!sample2){
        printf("Audio clip sample2 not loaded!\n");
        return -1;
    }

    while (!termina){
        
        for(int i = 0; i < 4; i++){
            demons[i].conversao();
        }
     
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

            //Movimentação do Pacman
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

            //Geração aleatória para a direção do fantasma
            int i, dem = 0;

            srand(time(NULL));

            //Movimentação do Dementador

            for(int i = 0; i < 4; i++){

                dem = rand() % 100;
        
                if (dem <= 25 && demons[i].cima_dementador(matriz) == true) {

                    updem = true;
                    downdem = false;
                    leftdem = false;
                    rightdem = false;

                    direcaodem[CIMADEM] = true;
                    direcaodem[BAIXODEM] = false;
                    direcaodem[DIREITADEM] = false;
                    direcaodem[ESQUERDADEM] = false;

                }
                else if (dem > 25 && dem <=50 && demons[i].baixo_dementador(matriz) == true) {

                    updem = false;
                    downdem = true;
                    leftdem = false;
                    rightdem = false;

                    direcaodem[CIMADEM] = false;
                    direcaodem[BAIXODEM] = true;
                    direcaodem[DIREITADEM] = false;
                    direcaodem[ESQUERDADEM] = false;


                }
                else if (dem > 50 && dem <= 75 && demons[i].esquerda_dementador(matriz) == true) {

                    updem = false;
                    downdem = false;
                    leftdem = true;
                    rightdem = false;

                    direcaodem[CIMADEM] = false;
                    direcaodem[BAIXODEM] = false;
                    direcaodem[DIREITADEM] = false;
                    direcaodem[ESQUERDADEM] = true;


                }
                else if (dem > 75 && dem <= 100 && demons[i].direita_dementador(matriz) == true) {

                    updem = false;
                    downdem = false;
                    leftdem = false;
                    rightdem = true;

                    direcaodem[CIMADEM] = false;
                    direcaodem[BAIXODEM] = false;
                    direcaodem[DIREITADEM] = true;
                    direcaodem[ESQUERDADEM] = false;

                }

                //Movi do dementador
                if (updem == true && demons[i].cima_dementador(matriz) == true) {
                    demons[i].setdemy(demons[i].getdemy() - 2.0);
                }

                if (downdem == true && demons[i].baixo_dementador(matriz) == true) {
                    demons[i].setdemy(demons[i].getdemy() + 2.0);
                }

                if (leftdem == true && demons[i].esquerda_dementador(matriz) == true) {
                    demons[i].setdemx(demons[i].getdemx() - 2.0);
                }

                if (rightdem == true && demons[i].direita_dementador(matriz) == true) {
                    demons[i].setdemx(demons[i].getdemx() + 2.0);
                }
            }

            //Movi do pacman
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
            //al_clear_to_color(al_map_rgb(0, 0, 255));
            p.desenha_pilula(matriz);
            b.desenha_bloco(matriz);
            al_draw_text(font, al_map_rgb(255, 255, 0), 800, 1, 0, "Score");
            al_draw_textf(font, al_map_rgb(255, 255, 0), 814, 40, NULL,"%d",pac.getscore());
            pac.desenha_pacman(sprite, lado);
            for(int i = 0; i < 4; i++){
                demons[i].desenha_dementador();
                if(pac.getpacx() == demons[i].getposx() 
                    && pac.getpacy() == demons[i].getposy()){
                        state = GAMEOVER;
                    break;
                }
            }
            
            if (state == MENU) {

                al_clear_to_color(al_map_rgb(21, 10, 0));

                al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);

                logopng = al_load_bitmap("images/logo.png");
                al_draw_bitmap(logopng,175,20,0); 

                if (t>20 && t<90) {
                    al_draw_text(fontInitScr, al_map_rgb(255,255,255), 275, 340, 0,"PRESS (SPACE) TO START GAME");
                } else if(t>100) {
                     // cout << "tempo: " << tempo << endl;
                    t = 0; 
                }
                t++;
                
                
                al_draw_text(fontFooterScr, al_map_rgb(255, 255, 0), 146, 570, 0,"© 2022 - PacPotter, By: Carlos Eduado, Vinicius do Carmo e Pedro Emanuel ");
                // cout << "Tela Inicial!!" << endl;
            }  else if(state == GAMEOVER) {
                al_stop_sample(sample_id); // pausa o audio
                // cout << "Sample id: " << sample_id << endl;

                al_play_sample(sample2, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);

                break;
            }

            al_flip_display();
        }
    }

    if(state == GAMEOVER) {
        
        al_clear_to_color(al_map_rgb(21, 10, 0));

        al_draw_text(fontEndScr, al_map_rgb(255, 255, 0), 300, 300, 0,"GAME OVER");

    }

    // cout << "ERRO GAME OVER: " << state << endl;
    al_flip_display();
    sleep(4);
    
    //Destroi componentes
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_sample(sample);
    al_destroy_sample_instance(instance);
    al_destroy_sample(sample2);
    al_destroy_sample_instance(instance2);
    al_destroy_bitmap(logopng);
    al_destroy_font(font);
    al_destroy_font(fontInitScr);
    al_destroy_font(fontEndScr);
    al_destroy_font(fontFooterScr);

    for (int i = 0; i < 15; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}