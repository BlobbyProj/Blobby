/* Playing around with SDL and learning it */

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


// load a bmp and put on a texture
SDL_Texture* LoadBMP(string file, SDL_Renderer* ren) {
    SDL_Surface * img = NULL;
    // get graphic
    img = SDL_LoadBMP(file.c_str());
    if (img == NULL){
        cout << "Loading Image: " << SDL_GetError() << endl;
        return NULL;
    }
    // create texture with graphic
    SDL_Texture* texture = NULL;
    texture = SDL_CreateTextureFromSurface(ren, img);
    // free the surface now that the image is on a texture
    SDL_FreeSurface(img);
    return texture;
}

// destroy everything and quit
void Quit(SDL_Texture* tex, SDL_Renderer* ren, SDL_Window* win) {
    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void Move(SDL_Rect& box, int x, int y) {
    box.x = (box.x + x) % SCREEN_WIDTH;
    box.y = (box.y + y) % SCREEN_HEIGHT;
    if (box.x < 0)
        box.x += SCREEN_WIDTH;
    if (box.y < 0)
        box.y += SCREEN_HEIGHT;
}

void Render(SDL_Renderer* ren, SDL_Texture* tex, SDL_Rect &box){
    // color screen (default = black)
    SDL_RenderClear(ren);
    // copy texture onto renderer
    SDL_RenderCopy(ren, tex, NULL, &box);
    // show renderer
    SDL_RenderPresent(ren);
}

int main(int argc, const char * argv[])
{
    // initialize SDL
    if (SDL_Init( SDL_INIT_EVERYTHING ) == -1) {
        cout << SDL_GetError() << endl;
        return -1;
    }
    
    // create window
    SDL_Window* window = NULL;
    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (window == NULL) {
        cout << SDL_GetError() << endl;
        return -1;
    }
    
    // create renderer
    SDL_Renderer* ren = NULL;
    ren = SDL_CreateRenderer(window, -1, 0);
    if (ren == NULL) {
        cout << SDL_GetError() << endl;
        return -1;
    }
    
    // get graphic
    SDL_Texture* tex = NULL;
    tex = LoadBMP("images/block.bmp", ren);
    
    /* put simple graphic on screen*/
    
    // create rect to copy texture to
    SDL_Rect box;
    box.x = 0; box.y = 0;
    box.w = 30; box.h = 30;
    
    Render(ren, tex, box);
    
    /* move graphic around*/
    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP:
                        Move(box, 0, -10);
                        break;
                    case SDLK_DOWN:
                        Move(box, 0, 10);
                        break;
                    case SDLK_RIGHT:
                        Move(box, 10, 0);
                        break;
                    case SDLK_LEFT:
                        Move(box, -10, 0);
                        break;
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    default:
                        break;
                }
                
            }
            // redraw screen
            Render(ren, tex, box);
        }
        
    }
    
    // close everything and end
    Quit(tex, ren, window);
    return 0;
}

