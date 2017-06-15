//============================================================================
// Name        : 15_Ex_Click.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*1. Прихванете кликане на мишката от екрана и изведете в
 конзолата координатите на мишката. Бройте колко пъти
 кликате и извеждайте бройката след всеки клик.*/

#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gMouseClick = NULL;

bool init() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n",
					SDL_GetError());
			success = false;
		} else {
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load splash image
	gMouseClick = SDL_LoadBMP("SquareMouseClick.bmp");
	if (gMouseClick == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n",
				"SquareMouseClick.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

void close() {
	//Deallocate surface
	SDL_FreeSurface(gMouseClick);
	gMouseClick = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main(int args, char* argc[]) {
	//Start up SDL and create window
	if (!init()) {
		printf("Failed to initialize!\n");
	} else {
		//Load media
		if (!loadMedia()) {
			printf("Failed to load media!\n");
		} else {
			//Apply the image
			SDL_BlitSurface(gMouseClick, NULL, gScreenSurface, NULL);

			//Update the surface
			SDL_UpdateWindowSurface(gWindow);
		}
	}
	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;
	int counter = 0;

	//While application is running
	while (!quit) {
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			} else if (e.type == SDL_MOUSEBUTTONUP) {
				//get mouse position
				int x, y;
				SDL_GetMouseState(&x, &y);
				cout << "mouse x: " << x << " y: " << y << "\n";
				counter++;
			}
		}
	}
	cout << "counter" << counter << endl;


	return 0;
}
