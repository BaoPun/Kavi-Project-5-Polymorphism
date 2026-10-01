#include "./game.hpp"


// When compling with ncurses within powershell command prompt:
//  g++ *.cpp -IC:/msys64/ucrt64/include/ncurses -LC:/msys64/ucrt64/lib -o wumpusgame -lncursesw -DNCURSES

// If you want debug to be on, compile with -DEBUG flag
#ifdef EBUG
#define DEBUG true
#else
#define DEBUG false
#endif

int main(int argc, char* argv[]){
    cout << "Welcome to Hunt the Wumpus." << endl;
    cout << "The objective of the game is to traverse the maze, collect the gold, kill the wumpus, and then escape." << endl;

    // Print the randomized board state for now
    // TODO: initialize the game by passing in the DEBUG macro
    


    // TODO: set up the game loop: print the board, print the percepts around player, and then choose an action.
    //       to continue the game, the game must not be over.  This will be the starting basis of your loop.
    //       I would recommend not doing the loop until you have the components inside the loop done first.


    return 0;
}
