#ifndef _PAWN_H_
#define _PAWN_H_
#include "pieces.h"

class Pawn: public Pieces {
  bool firstMove; // stores whether it is the first move for the pawn

 public:
  //ctor
  Pawn(int owner, bool captured, char id, bool firstMove, bool possibleCapture);

  //dtor
  ~Pawn();

  // set whether it is the pawn's first move: controller responsible to set this to false after the pawn's first move
  void setFirstMove(bool newMove);

  // checks if there is a piece of the other player diagonal to the pawn
  bool potentialCapture(Position start, Position end, const Board& board) const;

  // checks if a move is valid for the pawn piece
  bool validMove(Position start, Position end, const Board& board) const override;

};
#endif