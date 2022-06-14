#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include "Pacman.h"

using namespace std;

Pacman::Pacman(){
  pacman = NULL;
  pacman = al_load_bitmap("images/pacman.png");
  if(!pacman){
    printf("\nDEU RUIM NO PACMAN");
  }else{
    printf("\nPacmanPNG criado com sucesso");
  }
}

void Pacman::desenha_pacman(){
  al_draw_bitmap(pacman, 40, 40, 0);
  al_flip_display();
}

Pacman::~Pacman(){
  al_destroy_bitmap(pacman);
}