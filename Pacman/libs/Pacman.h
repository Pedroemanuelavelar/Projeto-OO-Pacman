#include <allegro5/allegro5.h>
#ifndef PACMAN_H
#define PACMAN_H

class Pacman {
  public:
      Pacman();
      void desenha_pacman();
      ~Pacman();
  private:
      ALLEGRO_BITMAP* pacman;
};

#endif