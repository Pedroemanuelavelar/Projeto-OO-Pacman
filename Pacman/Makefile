ALLEGRO_FLAGS=-L/usr/local/lib -lallegro `pkg-config --libs allegro-5 allegro_audio-5 allegro_dialog-5 allegro_image-5 allegro_memfile-5 allegro_primitives-5 allegro_acodec-5 allegro_color-5 allegro_font-5 allegro_main-5 allegro_physfs-5 allegro_ttf-5` 

ALLEGRO_INCLUDE= -I/usr/local/include/allegro5

all: ./libs/Tabuleiro.o ./libs/Bloco.o ./libs/Pilula.o Main.o
	g++ ./libs/Tabuleiro.o ./libs/Bloco.o ./libs/Pilula.o  Main.o -o Main.exe $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Tabuleiro.o: ./libs/tabuleiro.h ./libs/Tabuleiro.cpp
	g++ -c ./libs/Tabuleiro.cpp -o ./libsTabuleiro.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Bloco.o: ./libs/bloco.h ./libs/Bloco.cpp
	g++ -c Bloco.cpp -o Bloco.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Pilula.o: ./libs/pilula.h ./libs/Pilula.cpp
	g++ -c Pilula.cpp -o Pilula.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Main.o: ./libs/tabuleiro.h ./libs/bloco.h ./libs/pilula.h Main.cpp
	g++ -c Main.cpp -o Main.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

clear: 
	erase *.o *.exe