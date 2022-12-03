#include "knight.h"
#include "board.h"

// ctor
Knight::Knight(int owner, bool captured, char id): Pieces(owner, captured, id) {}

// dtor
Knight::~Knight() {}

bool Knight::validMove(Position start, Position end, Board* board) const {
    int rankChange = end.rank - start.rank;
    int fileChange = end.file - start.file;
    // 4 possible moves:
    if (rankChange == 1 && (fileChange == 2 || fileChange == -2)) {
        // move +1 vertically (rank) and then move +2/-2 horizontally (file)
        return true;
    } else if (rankChange == -1 && (fileChange == 2 || fileChange == -2)) {
        // move -1 vertically (rank) and then move +2/-2 horizontally (file)
        return true;
    } else if (fileChange == 1 && (rankChange == 2 || rankChange == -2)) {
        // move +1 horizontally (file) and then move +2/-2 vertically (rank)
        return true;
    } else if (fileChange == -1 && (rankChange == 2 || rankChange == -2)) {
        // move -1 horizontally (file) and then move +2/-2 vertically (rank)
        return true;
    } else {
        return false;
    }
}

// checks if a move is fully valid, this is overridden by each derived piece
bool Knight::validMoveFinal(Position start, Position end, Board* board) const {
    Pieces* currPiece = board->pieceAt(start);
    int currPlayer = currPiece->getOwner();
    if (currPiece->inBounds(start) == false) {
        return false;
    }
    if (currPiece->inBounds(end) == false) {
        return false;
    }
    // validMove == true
    if (currPiece->validMove(start, end, board) == false) {
        return false;
    }
    // can't capture your own piece: check that the same piece owner isn't at the end position
    Pieces* endPiece = board->pieceAt(end);
    if (endPiece != nullptr) {
        int endPlayer = endPiece->getOwner();
        if (currPlayer == endPlayer) {
            return false;
        }
    }
    // make sure the move doesn't put the king in check
    bool checkMoveKingInCheck = currPiece->myKingInCheck(start, end, board);
    if (checkMoveKingInCheck == false) { // false = move is invalid
        return false;
    }
    return true;
}

Knight* Knight::makeCopy() const {
    return (new Knight(*this));
}

// generate all valid moves for each derived piece -> TO IMPLEMENT STILLL!!!!
std::vector<Position> Knight::moveGenerator(Position loc, Board* board) const {
    std::vector<Position> moveList;
    return moveList;
}
