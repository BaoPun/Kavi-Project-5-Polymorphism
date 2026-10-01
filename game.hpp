#ifndef GAME_HPP
#define GAME_HPP

#include "./board.hpp"

class Game{
private:
    Board board;
    int player_x, player_y;
    int num_arrows;
    bool has_gold, has_killed_wumpus, has_died;
    bool debug;
    bool quit;
    int mode;   // 1 to move, 2 to shoot

    // Upon moving, an event may (not) happen
    void trigger_event();

    // Specific actions are private.  Use the public action() to determine which action to take.
    void move_player();
    void shoot();

public:
    Game(bool = true);

    void print_board() const;
    void action();
    
    void print_percepts() const;

    bool is_game_over() const;
    bool win() const;
    bool lose() const;
};



#endif