#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>

const int screenWidth = 640;
const int screenHeight = 480;

int main(int argc, char* args[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Drawing Circles", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // پاک کردن صفحه
        SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255); // تنظیم رنگ سبز
        SDL_RenderClear(renderer);

        // رسم دایره‌ها
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // تنظیم رنگ قرمز
        for (int i = 0; i < 3; ++i) {
            SDL_Rect rect = { i * 100, 100, 50, 50 }; // مختصات و اندازه دایره
            SDL_RenderFillRect(renderer, &rect);
        }

        // نمایش تغییرات روی صفحه
        SDL_RenderPresent(renderer);

        // تأخیر برای 10 ثانیه
        SDL_Delay(10000);

        // پاک کردن دایره وسط
        SDL_SetRenderDrawColor(renderer, 0, 128, 0, 255); // تنظیم رنگ سبز
        SDL_Rect fillRect = { screenWidth / 2 - 25, screenHeight / 2 - 25, 50, 50 }; // مختصات و اندازه دایره وسط
        SDL_RenderFillRect(renderer, &fillRect);

        // نمایش تغییرات روی صفحه
        SDL_RenderPresent(renderer);

        quit = true; // خروج از حلقه بعد از انجام عملیات
    }

    // خروج از برنامه
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
