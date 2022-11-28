#ifndef HUMAN_H
#define HUMAN_H
#include <string.h>
#include "player.h"
#include "square.h"

using namespace std;

class Human : public Player {
    //checks if the player has moved yet
    bool moved;

    public:
        //constructor 
        Human(string name);

        //gets the player's name
        string getName() override; 
        //checks if the king is on the board
        bool kingIsThere() override; 
        //checks if the player has moved
        bool hasMoved() override;
        //allows the player to make a valid move
        void makeMove() override; 
        //gets the score of the player
        int score() override;
        //captures opponent's piece
        void capture(Piece *p) override; 
        //moves to a valid square on the board
        Square moveTo() override;
        //reverses a player's move
        void reverseMove() override;

        //destructor
        ~Human();
};

#endif 