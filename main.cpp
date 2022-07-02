#include <unistd.h>
#include "snake.hpp"

//Modification de test

int moves(Snake *snake, int iter, int dir) {
  snake->Move(dir);
  if (iter % 3 == 0) {
    snake->Eat();
  }
  if (iter % 5 == 0) {
    dir=(dir+1) % 4;
  }
  return dir;
}

int main (void) {
  int dir = 1;
  int iter = 0;
  Snake snake(coords_t{10, 10});
  printf("~-~ Let's go! ~-~\n", iter);
  printf("^_^ - init %d - dir = %d\n", iter, dir);
  snake.Print();
  do {
    iter++;
    printf("^.^ - iter %d - dir = %d\n", iter, dir);
    dir = moves(&snake, iter, dir);
    snake.Print();
    sleep(1);
  } while(snake.Collides(snake.head->next)!=1);
  printf("x_X - Self-collision!\n");
  printf("~-~ Game over ~-~\n");
  exit(EXIT_SUCCESS);
}
