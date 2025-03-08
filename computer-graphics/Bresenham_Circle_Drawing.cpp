#include <SDL2/SDL.h>

const int WIDTH = 500, HEIGHT = 500;

void drawCircle(SDL_Renderer* renderer, int xc, int yc, int r) {
  int x = 0, y = r;
  int d = 3 - 2 * r;

  while (x <= y) {
    // Draw points for all eight octants
    SDL_RenderDrawPoint(renderer, xc + x, yc + y);
    SDL_RenderDrawPoint(renderer, xc - x, yc + y);
    SDL_RenderDrawPoint(renderer, xc + x, yc - y);
    SDL_RenderDrawPoint(renderer, xc - x, yc - y);
    SDL_RenderDrawPoint(renderer, xc + y, yc + x);
    SDL_RenderDrawPoint(renderer, xc - y, yc + x);
    SDL_RenderDrawPoint(renderer, xc + y, yc - x);
    SDL_RenderDrawPoint(renderer, xc - y, yc - x);

    SDL_RenderPresent(renderer);  // Refresh screen
    SDL_Delay(20);                // Add a small delay for animation

    x++;
    if (d > 0) {
      y--;
      d = d + 4 * (x - y) + 10;
    } else {
      d = d + 4 * x + 6;
    }
  }
}

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window =
      SDL_CreateWindow("Bresenham Circle", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  SDL_Renderer* renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black background
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // White circle

  drawCircle(renderer, WIDTH / 2, HEIGHT / 2, 100);

  // Keep window open
  SDL_Event event;
  bool running = true;
  while (running) {
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT)
        running = false;
    }
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
