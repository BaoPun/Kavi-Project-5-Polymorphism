#include "./board.hpp"

// Adding a macro for checking against player locations
#define PLAYER_ADJACENT(x, y) ((x == 15 && y == 0) || (x == 14 && y == 0) || (x == 15 && y == 1))

Board::Board(){
    // Before we create the board, we must first determine where the events will randomly be placed.
    // Three restrictions: 
    //      1. Only one event can occur in a single cell at a time.
    //      2. The player always starts at the bottom left, so an event cannot be placed there.
    //      3. Do not generate events adjacent to the player's starting position. 
    vector<int> gold_location;  // generate the gold anywhere except for the bottom left corner and its adjacent cells
    gold_location.resize(2);

    // seed the random generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> random_location(0, 15);

    // generate gold location.
    // note that the gold location must obey the above restrictions.
    int gold_x = -1, gold_y = -1;
    while(gold_x == -1 || gold_y == -1 || PLAYER_ADJACENT(gold_x, gold_y)){
        gold_x = random_location(gen);
        gold_y = random_location(gen);
    }

    // Generate the Wumpus location.
    // An additional restriction is that the wumpus cannot be placed in the same cell as the gold.
    this->wumpus_x = -1;
    this->wumpus_y = -1;
    while(this->wumpus_x == -1 || this->wumpus_y == -1 || (this->wumpus_x == gold_x && this->wumpus_y == gold_y) || PLAYER_ADJACENT(this->wumpus_x, this->wumpus_y)){
        this->wumpus_x = random_location(gen);
        this->wumpus_y = random_location(gen);
    }

    // Create the board.
    // For placing the pits and the bats, we will do this after creating the board.
    this->board = new Event**[BOARD_SIZE];
    for(int i = 0; i < BOARD_SIZE; i++){
        this->board[i] = new Event*[BOARD_SIZE];
        for(int j = 0; j < BOARD_SIZE; j++){
            // Either place the gold, the wumpus, or None at the start
            if(i == gold_x && j == gold_y){
                this->board[i][j] = new Gold();
            }
            else if(i == wumpus_x && j == wumpus_y){
                this->board[i][j] = new Wumpus();
            }
            else{
                this->board[i][j] = new None();
            }
        }
    }

    // Place the pits at random locations (25 locations in total)
    for(int i = 0; i < 25; i++){
        int pit_x = random_location(gen), pit_y = random_location(gen);

        // Check if the typecasted event is None and also if the pit is not adjacent to the player
        bool success = false;
        while(!success){
            if(dynamic_cast<None*>(this->board[pit_x][pit_y]) && !PLAYER_ADJACENT(pit_x, pit_y)){
                // If so, place the pit here.
                delete this->board[pit_x][pit_y];
                this->board[pit_x][pit_y] = new Pit();
                success = true;
            }
            else{
                pit_x = random_location(gen);
                pit_y = random_location(gen);
            }
        }
    }

    // Place the bats at random locations (20 locations in total)
    for(int i = 0; i < 25; i++){
        int bat_x = random_location(gen), bat_y = random_location(gen);

        // Check if the typecasted event is None and also if the pit is not adjacent to the player
        bool success = false;
        while(!success){
            if(dynamic_cast<None*>(this->board[bat_x][bat_y]) && !PLAYER_ADJACENT(bat_x, bat_y)){
                // If so, place the pit here.
                delete this->board[bat_x][bat_y];
                this->board[bat_x][bat_y] = new Bat();
                success = true;
            }
            else{
                bat_x = random_location(gen);
                bat_y = random_location(gen);
            }
        }
    }
}

Board::~Board(){
    // Deallocate the entire board
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            delete this->board[i][j];
            this->board[i][j] = nullptr;
        }
        delete[] this->board[i];
        this->board[i] = nullptr;
    }
    delete[] this->board;
    this->board = nullptr;
}

// Prints out the current board state, as well as the player's current location.
// If the debug flag is set, then print the entire board state with the events.
// Otherwise, omit the events.
void Board::print_board(int player_x, int player_y, bool debug) const{
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            cout << "[";
            if(i == player_x && j == player_y){
                // ansi color codes: https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797
                // 0 is default, foreground colors are 30-37; 33 = red
                cout << "\033[91mP\033[0m";
            }
            else{
                // Hint: look very carefully here.
                //       there is polymorphic behavior happening here,
                //       where we are getting the name's first char via polymorphism.
                //       this is how you will perform polymorphism when accessing event functions
                cout << (debug ? (dynamic_cast<None*>(this->board[i][j]) ? ' ' : this->board[i][j]->get_name()[0]) : ' ');
            }
            cout << "]";
        }
        cout << endl;
    }
}

/**
 * Given the player's coordinates, print the percepts around them
 */
void Board::print_percepts(int x, int y) const{
    // TODO
    // Hint: polymorphism is needed here.  Given an x, y coordinate of the board, print the percept
}

/**
 * Given the player's coordinates, retrieve the event space via its name and return it
 */
string Board::retrieve_event_name(int x, int y){
    // TODO
}

/**
 * After the gold has been picked up at location (x, y), replace the gold space with None
 */
void Board::gold_picked_up(int x, int y){
    // TODO
}

/**
 * After the wumpus has heard the arrow, it needs to retreat to a new, unoccupied space.
 * However, it cannot move to a space occupied to the player (x, y)
 */
void Board::move_wumpus(int x, int y){
    // TODO
}

/**
 * This function is called when an arrow hits the wumpus and kills it.
 * Replace the occupied Wumpus space with a None
 */
void Board::killed_wumpus(){
    // TODO
}

/**
 * This function is called when the player fires an arrow and misses the wumpus.
 * The arrow will then randomly move to a new location that is unoccupied.
 */
void Board::move_arrow(int x, int y){
    // TODO
}