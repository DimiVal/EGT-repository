//============================================================================
// Name        : 15Ex2.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//2. ≈кран 640 на 480. ѕокажете .png изображение на координати 20, 20.
//с размети 200 на 200 на изображението

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image
SDL_Surface* loadSurface(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//Current displayed PNG image
SDL_Surface* gPNGReducedSurface = NULL;

bool init() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init( SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Window could not be created! SDL Error: %s\n",
					SDL_GetError());
			success = false;
		} else {
			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags)) {
				printf("SDL_image could not initialize! SDL_image Error: %s\n",
				IMG_GetError());
				success = false;
			} else {
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}
	return success;
}

bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load reduced PNG surface ********************
	gPNGReducedSurface = loadSurface("Balloons.png");
	if (gPNGReducedSurface == NULL) {
		printf("Failed to load stretching image!\n");
		success = false;
	}
	return success;
}

void close() {
	//Free loaded image
	SDL_FreeSurface(gPNGReducedSurface);
	gPNGReducedSurface = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Surface* loadSurface(std::string path) {
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL Error: %s\n", path.c_str(),
				IMG_GetError());
	} else {
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface,
				gScreenSurface->format, 0);
		if (optimizedSurface == NULL) {
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(),
					SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface;
}

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
				}

				//Apply the image stretched
				SDL_Rect stretchRect;
				stretchRect.x = 20;
				stretchRect.y = 20;
				stretchRect.w = 200;
				stretchRect.h = 200;
				SDL_BlitScaled(gPNGReducedSurface, NULL, gScreenSurface,
						&stretchRect);

				//Update the surface
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}
