#ifndef BOARD_HPP
#define BOARD_HPP

#include "./gold.hpp"
#include "./wumpus.hpp"
#include "./pit.hpp"
#include "./bat.hpp"
#include "./none.hpp"
#include "./arrow.hpp"

// Class that represents the wumpus board.
// For this project, the board will be a massive 16x16 grid
// where each cell represents a single event (either none or one of the four events).

#define BOARD_SIZE 16

class Board{
private:
    Event*** board;  // 2d array of Event pointers.  Note that each Event is abstract.
    int wumpus_x, wumpus_y;     // this keeps track of the wumpus's location

public:
    Board();        // default constructor is responsible for creating the board state.
    ~Board();       // delete the board after we are done playing.

    // TODO: auxilary functions for viewing/changing the board state.
    void print_board(int, int, bool) const;     // print the current board state with the player's coordinates
    void print_percepts(int, int) const;        // print the different events surrounding the player
    string retrieve_event_name(int, int);             // trigger the event that the player is in post moving, by passing the name to the game class
    void gold_picked_up(int, int);              // gold has been picked up, so now replace the event space with a None
    void move_wumpus(int, int);                         // the wumpus has heard the arrow, so now it needs to retreat to a new, unoccupied space.
    void killed_wumpus();                       // the wumpus has been killed, so now replace the event space with a None   
    void move_arrow(int, int);                          // the player fired a missing shot, so randomly move the arrow to a different location that is unoccupied
};

#endif