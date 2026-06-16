#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
//#include "C:\Users\amira\OneDrive\Desktop\ff\sdl_g\main.cpp"

using namespace std;

void window_color (SDL_Renderer * renderer , int R , int G , int B,int a  ) {
    SDL_SetRenderDrawColor( renderer, R, G, B,a  );
    SDL_RenderClear( renderer );
}
//rectangle
void rect (SDL_Renderer *renderer , int x , int y , int w , int h , int r , int g , int b, int a,bool filled,int r_out,int g_out,int b_out ) {
    SDL_Rect rect = {x, y, w, h}; // Define the rectangle's position and size
    SDL_SetRenderDrawColor(renderer, r, g, b, a); // Set the drawing color to red with alpha of 100
    if (filled)
        SDL_RenderFillRect(renderer, &rect); // Draw the filled rectangle with the specified color and alpha
    SDL_SetRenderDrawColor(renderer,r_out,g_out,b_out,255);
    SDL_RenderDrawRect(renderer,&rect);
}

double length_line(double x_1 , double y_1 , double x_2 , double y_2) {
    double w = abs(x_2-x_1);
    double h = abs(y_2-y_1);
    double ans = sqrt(w*w+h*h);
    return ans ;
}



int main( int argc, char * argv[] ) {
    srand(time(NULL));
    int n, p_1, p_2, p_3, p_4;
    double a;
    //p_1 , p_4 برای y
    cout<<"enter Esc for exit\n";
    cout<<"******************\n";
    cout<<"enter n :";
    cin >> n;
    cout<<"******************\n";
    cout<<"enter a:";
    cin>>a ;

    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;// SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Texture *bkImg = NULL;
    //Texture for loading image

    int img_w, img_h;
    SDL_Rect img_rect;
    SDL_DisplayMode DM;
    int W = DM.w;
    int H = DM.h;

    SDL_Init(SDL_flags);
    SDL_CreateWindowAndRenderer(1920, 1080, WND_flags, &m_window, &m_renderer);
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_GetCurrentDisplayMode(0, &DM);
    int width, height;
    SDL_GetRendererOutputSize(m_renderer, &width, &height);
//  bkImg = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, W, H);
    window_color(m_renderer, 255, 255, 255, 255);
    for (int i = 0; i < (n/2)*2; i) {
        rect(m_renderer, (width - a) / 2, (height - a) / 2, a, a, 0, 0, 0, 255, 0, 0, 0, 0);
        circleRGBA(m_renderer, width / 2, height / 2, a / 2, 0, 0, 0, 255);
        i++;
        p_1 = (height - a) / 2;
        p_4 = (height + a) / 2;
        p_2 = (width - a) / 2;
        p_3 = (width + a) / 2;
        aalineRGBA(m_renderer, width / 2, p_1, p_2, height / 2, 0, 0, 0, 255);
        aalineRGBA(m_renderer, width / 2, p_4, p_2, height / 2, 0, 0, 0, 255);
        aalineRGBA(m_renderer, width / 2, p_4, p_3, height / 2, 0, 0, 0, 255);
        aalineRGBA(m_renderer, width / 2, p_1, p_3, height / 2, 0, 0, 0, 255);
        a = length_line(width / 2, p_1, p_2, height / 2);
        circleRGBA(m_renderer, width / 2, height / 2, a / 2, 0, 0, 0, 255);
        a = a * sqrt(2) / 2;
        i++;
    }
    if(n%2==1) {
        rect(m_renderer, (width - a) / 2, (height - a) / 2, a, a, 0, 0, 0, 255, 0, 0, 0, 0);
        circleRGBA(m_renderer, width / 2, height / 2, a / 2, 0, 0, 0, 255);

    }

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
            }
        }


        SDL_RenderPresent(m_renderer);
    }
}