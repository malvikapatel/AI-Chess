#include "king.h"

// ctor
King::King(int owner, int id): Pieces(owner, id) {}

// dtor
King::~King() {}

bool King::validMove(Position start, Position end, const Board& board) const {
    // implementaion here
    return true;
}

