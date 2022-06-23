ALLEGRO_FLAGS=-L/usr/local/lib -lallegro `pkg-config --libs allegro-5 allegro_audio-5 allegro_dialog-5 allegro_image-5 allegro_memfile-5 allegro_primitives-5 allegro_acodec-5 allegro_color-5 allegro_font-5 allegro_main-5 allegro_physfs-5 allegro_ttf-5` 

ALLEGRO_INCLUDE= -I/usr/local/include/allegro5

all: Bloco.o Pilula.o Pacman.o Main.o
	g++  Bloco.o Pilula.o  Pacman.o Main.o -o Main.exe $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Pacman.o: Pacman.h Pacman.cpp
	g++ -c Pacman.cpp -o Pacman.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Bloco.o: Bloco.h Bloco.cpp
	g++ -c Bloco.cpp -o Bloco.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Pilula.o: Pilula.h Pilula.cpp
	g++ -c Pilula.cpp -o Pilula.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Main.o: Bloco.h Pilula.h Main.cpp
	g++ -c Main.cpp -o Main.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

clear: 
	rm *.o *.exe
	erase *.o *.exe