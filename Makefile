ALLEGRO_FLAGS=-L/usr/local/lib -lallegro `pkg-config --libs allegro-5 allegro_audio-5 allegro_dialog-5 allegro_image-5 allegro_memfile-5 allegro_primitives-5 allegro_acodec-5 allegro_color-5 allegro_font-5 allegro_main-5 allegro_physfs-5 allegro_ttf-5` 

ALLEGRO_INCLUDE= -I/usr/local/include/allegro5

all: ./libs/Bloco.o ./libs/Pilula.o ./libs/Pacman.o ./libs/Movimentacao.o  ./libs/Dementador.o Main.o
	g++ ./libs/Bloco.o ./libs/Pilula.o ./libs/Pacman.o ./libs/Movimentacao.o ./libs/Dementador.o Main.o -o Main.exe $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Pacman.o: ./libs/Pacman.h ./libs/Pacman.cpp
	g++ -c ./libs/Pacman.cpp -o ./libs/Pacman.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Bloco.o: ./libs/Bloco.h ./libs/Bloco.cpp
	g++ -c Bloco.cpp -o Bloco.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Movimentacao.o: ./libs/Movimentacao.h ./libs/Movimentacao.cpp
	g++ -c Movimentacao.cpp -o Movimentacao.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Dementador.o: ./libs/Dementador.h ./libs/Dementador.cpp
	g++ -c Dementador.cpp -o Dementador.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Pilula.o: ./libs/Pilula.h ./libs/Pilula.cpp
	g++ -c Pilula.cpp -o Pilula.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

Main.o: ./libs/Bloco.h ./libs/Pilula.h Main.cpp
	g++ -c Main.cpp -o Main.o $(ALLEGRO_INCLUDE) $(ALLEGRO_FLAGS)

clear: 
	rm *.o *.exe
	erase *.o *.exe