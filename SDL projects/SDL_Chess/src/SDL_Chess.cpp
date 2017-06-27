//============================================================================
// Name        : SDL_Chess.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

//Quadrates constants
const int QUAD_WIDTH = 80;
const int QUAD_HEIGHT = 80;
//const int TOTAL_BUTTONS = 64;

//Texture wrapper class
class LTexture {
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	//Loads image at specified path
	bool loadFromFile(string path);

	//Deallocates texture
	void free();

	//Renders texture at given point
	void render(int x, int y, SDL_Rect* clip = NULL);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
//SDL_Texture* loadTexture(string path);  //Lesson 8

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene sprites
SDL_Rect gSpriteClips[12];  //Lesson 11
LTexture gSpriteSheetTexture;

LTexture::LTexture() {
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture() {
	//Deallocate
	free();
}

bool LTexture::loadFromFile(std::string path) {
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(),
		IMG_GetError());
	} else {
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE,
				SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL) {
			printf("Unable to create texture from %s! SDL Error: %s\n",
					path.c_str(), SDL_GetError());
		} else {
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free() {
	//Free texture if it exists
	if (mTexture != NULL) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::render(int x, int y, SDL_Rect* clip) {
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	//Render to screen
	SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}

int LTexture::getWidth() {
	return mWidth;
}

int LTexture::getHeight() {
	return mHeight;
}

bool init() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	} else {
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
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
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1,
					SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n",
						SDL_GetError());
				success = false;
			} else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF); //white

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					printf(
							"SDL_image could not initialize! SDL_mage Error: %s\n",
							IMG_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}

bool loadMedia() {
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if (!gSpriteSheetTexture.loadFromFile("ChessSprite.png")) {
		printf("Failed to load sprite sheet texture!\n");
		success = false;
	} else {
		//Set sprites of the picture
		int step = 77;
		for (int i = 0; i < 6; i++) {
			gSpriteClips[i].x = i * step;
			gSpriteClips[i].y = 0;
			gSpriteClips[i].w = 80;
			gSpriteClips[i].h = 80;
		}
		for (int i = 0; i < 6; i++) {
			gSpriteClips[i + 6].x = i * step;
			gSpriteClips[i + 6].y = 80;
			gSpriteClips[i + 6].w = 80;
			gSpriteClips[i + 6].h = 80;
		}
	}
	return success;
}

void close() {
	//Free loaded images
	gSpriteSheetTexture.free();

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

//SDL_Texture* loadTexture(string path) {
//	//The final texture
//	SDL_Texture* newTexture = NULL;
//
//	//Load image at specified path
//	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
//
//	if (loadedSurface == NULL) {
//		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(),
//				IMG_GetError());
//	} else {
//		//Create texture from surface pixels
//		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
//		if (newTexture == NULL) {
//			printf("Unable to create texture from %s! SDL Error: %s\n",
//					path.c_str(), SDL_GetError());
//		}
//		//Get rid of old loaded surface
//		SDL_FreeSurface(loadedSurface);
//	}
//	return newTexture;
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
			bool draw = true;

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
				if (draw) {
					//Clear screen
					SDL_SetRenderDrawColor(gRenderer, 180, 80, 10, 0); //brown/dark/
					SDL_RenderClear(gRenderer);

					for (int x = 0; x < QUAD_WIDTH * 8; x = x + QUAD_WIDTH) {
						bool odd = ((x / 80) % 2 == 1); //the chessboard have to start with white
						for (int y = QUAD_HEIGHT * odd; y < QUAD_HEIGHT * 8;
								y = y + (2 * QUAD_HEIGHT)) {

							SDL_Rect fillRect = { x, y, SCREEN_WIDTH / 8,
									SCREEN_HEIGHT / 8 };
							SDL_SetRenderDrawColor(gRenderer, 230, 180, 150, 0); //white/light
							SDL_RenderFillRect(gRenderer, &fillRect);
						}
					}

					int step = 80;
					for (int i = 0; i < 8; i++) {  //pawns
						gSpriteSheetTexture.render((i * step), step,
								&gSpriteClips[5]);  // black
						gSpriteSheetTexture.render((i * step), (6 * step),
								&gSpriteClips[11]);  //white
					}

					gSpriteSheetTexture.render(0, 0, &gSpriteClips[4]); //rook, black
					gSpriteSheetTexture.render((7 * step), 0, &gSpriteClips[4]); //black
					gSpriteSheetTexture.render(0, (7 * step),
							&gSpriteClips[10]); //white
					gSpriteSheetTexture.render((7 * step), (7 * step),
							&gSpriteClips[10]); //white

					gSpriteSheetTexture.render(step, 0, &gSpriteClips[3]); //knight/horse/, black
					gSpriteSheetTexture.render((6 * step), 0, &gSpriteClips[3]); //black
					gSpriteSheetTexture.render(step, (7 * step),
							&gSpriteClips[9]); //white
					gSpriteSheetTexture.render((6 * step), (7 * step),
							&gSpriteClips[9]);  //white

					gSpriteSheetTexture.render((2 * step), 0, &gSpriteClips[2]); //bishop/officer/, black
					gSpriteSheetTexture.render((5 * step), 0, &gSpriteClips[2]); //black
					gSpriteSheetTexture.render((2 * step), (7 * step),
							&gSpriteClips[8]);  //white
					gSpriteSheetTexture.render((5 * step), (7 * step),
							&gSpriteClips[8]);  //white

					gSpriteSheetTexture.render((3 * step), 0, &gSpriteClips[1]); //queen, black
					gSpriteSheetTexture.render((3 * step), (7 * step),
							&gSpriteClips[7]); //queen, white
					gSpriteSheetTexture.render((4 * step), 0, &gSpriteClips[0]); //king, black
					gSpriteSheetTexture.render((4 * step), (7 * step),
							&gSpriteClips[6]); //king, white

					draw = false;
				}
				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}
	//Free resources and close SDL
	close();

	return 0;
}
