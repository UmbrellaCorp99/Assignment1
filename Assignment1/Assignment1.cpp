#include <iostream>
#include "logic.h"
#include <allegro5/allegro.h>

using namespace std;

void* input(ALLEGRO_THREAD* ptr, void* arg);
void* timer(ALLEGRO_THREAD* ptr, void* arg);
bool finished = false;
bool timeOut = false;
logic game;

int main()
{
	game.introduction();
	game.createLists();

	ALLEGRO_THREAD *create1 = NULL, *create2 = NULL;

	create1 = al_create_thread(input, NULL);
	create2 = al_create_thread(timer, NULL);

	while (!finished && !timeOut) {
		if (!finished && !timeOut) {
			al_start_thread(create1);
			al_start_thread(create2);
		}
		else {
			al_destroy_thread(create1);
			al_destroy_thread(create2);
		}
	}

	if (finished) {
		game.end();
	}
	else {
		cout << "\nTime ran out!\n";
		game.end();
	}

	return 0;
}

void* input(ALLEGRO_THREAD* ptr, void* arg) {
	finished = false;
	game.playGame();
	finished = true;
	return NULL;
}

void* timer(ALLEGRO_THREAD* ptr, void* arg) {
	time_t startTime, currentTime;
	startTime = time(NULL);
	currentTime = time(NULL);
	while (currentTime - startTime < 60 && !finished) {
		currentTime = time(NULL);
	}
	timeOut = true;
	return NULL;
}

