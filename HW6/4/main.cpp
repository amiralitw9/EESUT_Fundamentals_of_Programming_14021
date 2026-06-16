#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL2_gfx.h>
//#include "C:\Users\amira\OneDrive\Desktop\ff\sdl_g\main.cpp"
void window_color (SDL_Renderer * renderer , int R , int G , int B,int a  ) {
    SDL_SetRenderDrawColor( renderer, R, G, B,a  );
    SDL_RenderClear( renderer );
}



using namespace std;
int main( int argc, char * argv[] ) {
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,1,2048);
    Mix_Music *music = Mix_LoadMUS(".mp3");
    srand(time(0));
    double i = 0 ;
    double a =0 ;
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
    Uint32 WND_flags = SDL_WINDOW_SHOWN |SDL_WINDOW_FULLSCREEN_DESKTOP ;//SDL_WINDOW_BORDERLESS ;// SDL_WINDOW_FULLSCREEN_DESKTOP ; ;
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
    SDL_CreateWindowAndRenderer(1000, 1000, WND_flags, &m_window, &m_renderer);
//Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
//Get screen resolution
    SDL_GetCurrentDisplayMode(0, &DM);
//این بخش از کد طول و عرض صفحه رو در دو متغیر ذخیره میکنه
    int width, height;
    SDL_GetRendererOutputSize(m_renderer, &width, &height);
//**************************************************************************
    double x_1 ,x_2 , y_1 ,y_2 ;
    do{
        x_1 = rand() % (width - 120 + 1) + 60, x_2 = rand() % (width - 180 + 1) + 90, y_1 =rand() % (height - 120 + 1) + 60, y_2 = rand() % (height - 180 + 1) + 90;
    }
    while (sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2))<150);
    double vx_1 = rand()%(10000-30+1)+30,vx_2 = rand()%(10000-30+1)+30,vy_1 =  rand()%(10000-30+1)+30 , vy_2 = rand()%(10001-30)+30 ;
    vx_1/=20000.0 ; vx_2/=20000.0 ;vy_1/=20000.0 ;vy_2/=20000.0 ;
    int r_1 = 255 , b_1 = 0 , r_2 =0 ,b_2 = 255;
    bool x = 1 ;
    cout<<vx_1<<" "<<vx_2<<" "<< vy_1<<" "<<vy_2 ;




    bool running = true;
    SDL_Event event;
    SDL_Event event_1 ;


    while (running) {
        while (SDL_PollEvent(&event) || SDL_PollEvent(&event_1)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    cout<<i ;
                    running = false;
                }
                if (event.key.keysym.sym == SDLK_SPACE){
                    i+=.03;
                }

            }
        }
        window_color(m_renderer,0,0,0,255);
        aacircleRGBA(m_renderer,x_1,y_1,60,r_1,0,b_1,255);
        aacircleRGBA(m_renderer,x_2,y_2,90,r_2,0,b_2,255);
        if(i>0){
            if(vy_1>0)
                vy_1+=i;
            if(vy_1<0)
                vy_1-=i;
            if(vy_2>0)
                vy_2+=i ;
            if(vy_2<0)
                vy_2-=i;
            if(vx_1>0)
                vx_1+=i;
            if(vx_1<0)
                vy_1-=i ;
            if(vx_2>0)
                vx_2+=i;
            if(vx_2<0)
                vx_2-=i ;
        }
        i=0;
        if(((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2))<=150*150 &&  x ==1  ){
            Mix_PlayMusic(music, 0);
            a = -1/5.0*vx_1+3/2.5*vx_2 ;
            vx_2 = 2/2.5*vx_1+1/5.0*vx_2 ;
            vx_1=a ;
            a  = -1/5.0*vy_1+3/2.5*vy_2 ;
            vy_2 = 2/2.5*vy_1+1/5.0*vy_2 ;
            vy_1=a ;
            swap(r_1,r_2);
            swap(b_1,b_2);
            x=0 ;
        }
        if (((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2))>=150.1*150.1)
            x = 1 ;
        x_1+=vx_1 ; x_2+=vx_2 ; y_1+=vy_1 ; y_2+=vy_2 ;
        SDL_RenderPresent(m_renderer);
        if(x_1>(width-60) || x_1<60) {
            vx_1 = -1 * (vx_1);
            Mix_PlayMusic(music, 0);
        }
        if(x_2>(width-90) || x_2 <90) {
            vx_2 = -1 * (vx_2);
            Mix_PlayMusic(music, 0);
        }
        if(y_1>(height-60) || y_1<60) {
            vy_1 = -1 * vy_1;
            Mix_PlayMusic(music, 0);
        }
        if(y_2>(height-90) || y_2 <90) {
            vy_2 = -1 * vy_2;
            Mix_PlayMusic(music, 0);
        }
    }
}
