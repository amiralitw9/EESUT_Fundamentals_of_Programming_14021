#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
//#include "C:\Users\amira\OneDrive\Desktop\ff\sdl_g\main.cpp"
using namespace std;
void  mod(int x_0 ,int x_1 , int y_0,int y_1,double natije[3]){
    y_0 = 1080 -y_0;
    y_1 = 1080 -y_1 ;
    double shib =  (y_1-y_0)/((x_1-x_0)/1.0);
    natije[0]=y_0;
    natije[1]=shib;
    natije[2]=x_0;

}
bool place(int x , int y , double natije[3]) {
    y=1080-y ;
    cout<<(-y-natije[0]+(natije[1])*(x-natije[2]))<<endl ;
    if((natije[0]+(natije[1])*(x-natije[2]))<y){
        return 1 ;

    }


    else
        return 0 ;
}

void window_color (SDL_Renderer * renderer , int R , int G , int B,int a  ) {
    SDL_SetRenderDrawColor( renderer, R, G, B,a  );
    SDL_RenderClear( renderer );
}
bool f (double points [4][2]) {
    int counter_1 = 0 , counter_2 = 0 ;
    for(int i = 0 ; i<3 ; i++) {
        if (points[i][0]>points[3][0])
            counter_1++ ;
        if (points[i][0]<points[3][0])
            counter_2++ ;
    }
    if(counter_1>counter_2)
        return 1 ;
    else
        return 0 ;
}


int main( int argc, char * argv[] ) {
    double  points[4][2] , counter = 0 ;
    int n;
    cout << "enter n :";
    cin >> n;
    double a;
    double max = 0, min = 0;
    int max_1 = 0, min_1 = 0;
    double natije [3] ;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a;
            points[i][j] = a;
        }
    }
    min = 1920 ;
    for (int i = 0; i < 4; i++) {
        if (points[i][1] <= min) {
            min_1 = i;
            min = points[i][1];
        }
    }
    swap(points[0],points[min_1]);
    max = 0  ;
    for (int i = 1; i < 4; i++) {
        if (points[i][0] >= max) {
            max_1 = i;
            max = points[i][0];
        }
    }
    swap(points[1],points[max_1]);
    max = 0;
    for (int i = 2; i < 4; i++) {
        if (points[i][0] >= max) {
            max_1 = i;
            max = points[i][0];
        }
    }
    swap(points[3],points[max_1]);
    if (points[1][0] > points[2][0]) {
        swap(points[1], points[2]);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cout << points[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"********************"<<endl;
    mod(points[1][0],points[2][0],points[1][1],points[2][1],natije);
    for(int  i =0 ; i<3 ; i++)
        cout<<natije[i]<<" ";
    cout<<endl ;

    if(place(points[3][0],points[3][1],natije)==1 && f(points)==1) {
        swap(points[3],points[1]);
    }
    else if(place(points[3][0],points[3][1],natije)==1 && f(points)==0) {
        swap(points[3],points[2]);

    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            cout << points[i][j] << " ";
        }
        cout << endl;
    }



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
    SDL_CreateWindowAndRenderer(1813, 1020, WND_flags, &m_window, &m_renderer);
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_GetCurrentDisplayMode(0, &DM);
    int width, height;
    SDL_GetRendererOutputSize(m_renderer, &width, &height);
    window_color(m_renderer, 255, 255, 255, 255);
    aalineRGBA(m_renderer, points[0][0], points[0][1], points[3][0], points[3][1], 0, 0, 0, 255);
    aalineRGBA(m_renderer, points[0][0], points[0][1], points[1][0], points[1][1], 0, 0, 0, 255);
    aalineRGBA(m_renderer, points[0][0], points[0][1], points[2][0], points[2][1], 0, 0, 0, 255);
    aalineRGBA(m_renderer, points[1][0], points[1][1], points[3][0], points[3][1], 0, 0, 0, 255);
    aalineRGBA(m_renderer, points[2][0], points[2][1], points[3][0], points[3][1], 0, 0, 0, 255);

    double l_1 = (points[3][1] - points[0][1]) / n; //تقسیمات y
    double l_2 = (points[3][0] - points[0][0]) / n; //تقسیمات x
    //تقسیم خط وسط
    //**********************************
    double l_3 = (points[1][1] - points[0][1]) / n;
    double l_4 = (points[1][0] - points[0][0]) / n;
    //تقسیم خط کنار
    //**********************************
    double l_5 = (points[2][1] - points[0][1]) / n;
    double l_6 = (points[2][0] - points[0][0]) / n;
    for (int i = 0; i < n; i++) {
        aalineRGBA(m_renderer, (points[0][0] + i * l_2), points[0][1] + i * (l_1), (points[0][0] + i * l_4),
                   (points[0][1] + i * l_3), 0, 0, 0, 255);
        aalineRGBA(m_renderer, (points[0][0] + i * l_2), points[0][1] + i * (l_1), (points[0][0] + i * l_6),
                   (points[0][1] + i * l_5), 0, 0, 0, 255);


    }
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }


            SDL_RenderPresent(m_renderer);
        }
    }
}
