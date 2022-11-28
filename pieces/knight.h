#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include "pieces.h"

class Knight: public Pieces {
 public:
  //ctor
  Knight(int owner, bool captured, char id);

  //dtor
  ~Knight();

  // checks if a move is valid for the Knight piece
  bool validMove(Position start, Position end, const Board& board) const override;

};
#endif