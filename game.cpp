#include "./game.hpp"

Game::Game(bool debug) : debug(debug){
    this->player_x = BOARD_SIZE - 1;
    this->player_y = 0;
    this->num_arrows = 3;
    this->has_gold = false;
    this->has_killed_wumpus = false;
    this->has_died = false;
    this->quit = false;
    this->mode = 1;         // default the mode to move
}

/**
 * Prints the current state of the board with the player's current coordinates + the debug parameter
 */
void Game::print_board() const{
    this->board.print_board(this->player_x, this->player_y, this->debug);
}

/**
 * Determines if the player wants to move or shoot.
 * 
 * Note: the default action for the player is to move if the player has no arrows left or if the wumpus is dead.
 *       otherwise, give the player a choice between moving and shooting.
 */
void Game::action(){
    // TODO
}

/**
 * Move the player in a specified direction (WASD is the preferred control scheme)
 */
void Game::move_player(){
    // TODO
}

/**
 * Shoot one arrow across a specified direction.  
 * If the arrow hits the wumpus, then the wumpus dies.
 * Otherwise, the wumpus has a 75% chance of waking up and moving to a new, unoccupied location.
 * 
 * This function assumes you have at least 1 arrow.
 */
void Game::shoot(){
    // TODO
}

/**
 * After moving the player, check to see if the player ended up on an event.
 * If not, then do nothing
 * Otherwise, do something with that event
 */
void Game::trigger_event(){
    // TODO
}

/**
 * If the player is surrounded by at least one event, then print its details
 */
void Game::print_percepts() const{
    // TODO
    // This one should be simple: simply call the board's print_percepts() function
}


/**
 * The game ends when the player either wins or loses or chooses to quit
 */
bool Game::is_game_over() const{
    // TODO
}

/**
 * The player wins if all of the following conditions hold:
 * 1. The player is at the starting space
 * 2. The wumpus has been slain
 * 3. Gold has been picked up
 */
bool Game::win() const{
    // TODO
}

/**
 * The player loses if they die.  They can die in two ways: falling from the pit or getting eaten by the wumpus
 */
bool Game::lose() const{
    // TODO
}