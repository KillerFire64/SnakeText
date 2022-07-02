#pragma once
#include <stdlib.h>
#include <stdio.h>

#define DOWN 0
#define UP 1
#define LEFT 2
#define RIGHT 3

// 2D Coordinates struct:
typedef struct {
  int x;
  int y;
} coords_t;

// Elements of Snake's body:
class Segment {
public:
  Segment(coords_t xy);
  ~Segment();
  void SetCoords(coords_t xy);
  void Print(void);
  Segment *CreateNext(coords_t xy);

  coords_t xy;
  Segment *next;
};

// The Snake, it always has a head.
// Note: At the begining, the tail = head:
class Snake {
public:
  Snake(coords_t xy);
  ~Snake();
  void Move(int dir);
  void Eat();
  void Print(void);
  int Collides(Segment *seg);

  Segment *head;
  Segment *tail;
  coords_t prev_tail_coords; // previous coordinates of the tail
};
