#include "snake.hpp"

// Constructor: Set passed coordinates and init pointers to NULL:
Segment::Segment(coords_t xy) {
  SetCoords(xy);
  next=nullptr;
}

// Destructor: deletes all segments if not NULL:
Segment::~Segment() {
  if (next) {
    delete next;
    next=nullptr;
  }
}

// Move the Snake along direction dir:
void Segment::SetCoords(coords_t xy) {
  if (next) {
    next->SetCoords(this->xy);
  }
  this->xy = coords_t{xy.x, xy.y};
}

// Create a new Segment at coordinates xy:
Segment *Segment::CreateNext(coords_t xy) {
  next=new Segment(xy);
  return next;
}

// Print its coordinates as "(x, y) ", the prints other Segment's coordinates:
void Segment::Print(void) {
  printf("(%d, %d) ", xy.x, xy.y);
  if (next) {
    next->Print();
  }
}

// Constructor: Create the head Segment, set tail = head.
Snake::Snake(coords_t xy) {
  head=new Segment(xy);
  tail=head;
}

// Destructor: deletes head, which in turn deletes the other segments:
Snake::~Snake() {
  delete head;
  head=nullptr;
  tail=nullptr;
}

// Move the Snake along direction dir.  Transforms UP, DOWN, LEFT,
// RIGHT into new xy coordinates to be set to Snake's head:
void Snake::Move(int dir) {
  prev_tail_coords=tail->xy;
  coords_t new_xy;
  switch (dir) {
    case UP:
      new_xy = coords_t{head->xy.x, head->xy.y-1};
      break;
    case DOWN:
      new_xy = coords_t{head->xy.x, head->xy.y+1};
      break;
    case LEFT:
      new_xy = coords_t{head->xy.x-1, head->xy.y};
      break;
    case RIGHT:
      new_xy = coords_t{head->xy.x+1, head->xy.y};
      break;
  }
  head->SetCoords(new_xy);
}

// Add a new Segment at the end of the chain list of segments.
// Since Segment::CreateNext() returns the pointer to the newly
// created Segment object, set it as the new tail of the Snake:
void Snake::Eat() {
  tail=tail->CreateNext(prev_tail_coords);
}

// Print the coordinates of all of the Segments, terminate with the print with a new line:
void Snake::Print(void) {
  head->Print();
  printf("\n");
}

// This is a recursive function
int Snake::Collides(Segment *seg) {
  if (head == tail) {
    return 0;
  }
  else {
    if (head->xy.x==seg->xy.x && head->xy.y==seg->xy.y) {
      return 1;
    }
    else if (seg->next) {
      return Collides(seg->next);
    }
    else {
      return 0;
    }
  }
}
