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
	game.end();
	return 0;
}

void* input(ALLEGRO_THREAD* ptr, void* arg) {
	finished = false;
	cout << "Asking for user input?";
	cin >> finished;
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

