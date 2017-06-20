//============================================================================
// Name        : 15Ex2.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//2. Екран 640 на 480. Покажете .png изображение на координати 20, 20.
//с размети 200 на 200 на изображението

//3. При клик върху горното изображение го преместете на координати 40, 40.

//4. При втори клик върху картинката смалете изображението на 100 на 100.

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <stdio.h>
#include <string>
#include "Button.h"
#include "globals.h"
using namespace std;

//Buttons object
Button gButton;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
//SDL_Surface* loadSurface(string path);

//The surface contained by the window
//SDL_Surface* gScreenSurface = NULL;

//Current displayed PNG image
//SDL_Surface* gPNGReducedSurface = NULL;

bool init() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//Set texture filtering to linear
		if (!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Window could not be created! SDL Error: %s\n",
					SDL_GetError());
			success = false;
		} else {
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());
				success = false;
			} else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					printf(
							"SDL_image could not initialize! SDL_image Error: %s\n",
							IMG_GetError());
					success = false;
				}
//					else {
//					//Get window surface
//					gScreenSurface = SDL_GetWindowSurface(gWindow);
//				}
			}
		}
	}
	return success;
}

bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load sprite
	if (!gButton.loadFromFile(gRenderer, "Balloons.png")) {
		printf("Failed to load button sprite texture!\n");
		success = false;
	} else {
		//Set sprites
		gButton.setPosition(20, 20);
		gButton.setWidth(200);
		gButton.setHeight(200);
	}
	return success;
}

void close() {
	//Free loaded image
	gButton.free();

	//SDL_FreeSurface(gPNGReducedSurface);
	//gPNGReducedSurface = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

//SDL_Surface* loadSurface(string path) { //d
//	//The final optimized image
//	SDL_Surface* optimizedSurface = NULL;
//
//	//Load image at specified path
//	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
//	if (loadedSurface == NULL) {
//		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(),
//		IMG_GetError());
//	} else {
//		//Convert surface to screen format
//		optimizedSurface = SDL_ConvertSurface(loadedSurface,
//				gScreenSurface->format, 0);
//		if (optimizedSurface == NULL) {
//			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(),
//					SDL_GetError());
//		}
//		//Get rid of old loaded surface
//		SDL_FreeSurface(loadedSurface);
//	}
//	return optimizedSurface;
//}

int main(int argc, char* args[]) {
	//Start up SDL and create window
	if (!init()) {
		printf("Failed to initialize!\n");
	} else {
		//Load media
		if (!loadMedia()) {
			printf("Failed to load media!\n");
		} else {
			//Main loop flag
			bool quit = false;
			int c = 0;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit) {
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0) {
					//User requests quit
					if (e.type == SDL_QUIT) {
						quit = true;
					}
					if (e.type == SDL_MOUSEBUTTONDOWN) {
						switch (c) {
						case 0: {
							c++;
							int x, y;
							SDL_GetMouseState(&x, &y);
							if (gButton.isClicked(x, y)) {
								gButton.setPosition(40, 40); //new position - 3)
							}
							break;
						}
						case 1: {
							c--;
							if (e.type == SDL_MOUSEBUTTONDOWN) {
								int x, y;
								SDL_GetMouseState(&x, &y);
								if (gButton.isClicked(x, y)) {
									gButton.setPosition(40, 40);
									gButton.setWidth(100);
									gButton.setHeight(100);  //4)
								}
							}
							break;
						}
						}
					}
				}
				//Apply the image stretched
//				SDL_Rect stretchRect;
//				stretchRect.x = 40;
//				stretchRect.y = 40;
//				stretchRect.w = 200;
//				stretchRect.h = 200;
//				SDL_BlitScaled(gPNGReducedSurface, NULL, gScreenSurface,
//						&stretchRect);

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//Render buttons
				gButton.draw(gRenderer, 0, SDL_FLIP_NONE);

				//Update screen
				SDL_RenderPresent(gRenderer);  //ddddddddddddd

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
//Free resources and close SDL
	close();

	return 0;
}
