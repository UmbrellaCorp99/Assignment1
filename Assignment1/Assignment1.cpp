//Alexander Young
//Assignment 1

#include <iostream>
#include "logic.h"
#include <allegro5/allegro.h>

using namespace std;

//The input and timer functions
void* input(ALLEGRO_THREAD* ptr, void* arg);
void* timer(ALLEGRO_THREAD* ptr, void* arg);

//global variables to be used
bool finished = false;
bool timeOut = false;

//instantiating the logic class 
logic game;

int main()
{
	//calling the introduction and createList functions
	game.introduction();
	game.createLists();

	//creating two Allegro threads, one for the timer and the other for the gameplay input
	ALLEGRO_THREAD *create1 = NULL, *create2 = NULL;
	create1 = al_create_thread(input, NULL);
	create2 = al_create_thread(timer, NULL);
	
	//keep the threads running until the timer runs out or the user wins the game
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

	//if the user wins, simply call the end function. If the timer runs out, let the user know and then call the end function
	if (finished) {
		game.end();
	}
	else {
		cout << "\nTime ran out!\n";
		game.end();
	}

	return 0;
}

//This function calls the playGame function
//It takes Allegro thread and void pointers as parameters
//No return
void* input(ALLEGRO_THREAD* ptr, void* arg) {
	finished = false;
	game.playGame();
	finished = true;
	return NULL;
}

//This function manages the timer for the game
//It takes allegro thread and void pointers as parameters
//No return
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

