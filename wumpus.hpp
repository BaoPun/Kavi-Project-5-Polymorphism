#ifndef WUMPUS_HPP
#define WUMPUS_HPP

#include "./event.hpp"

// Class that represents the wumpus event.
// Here, we will define the percept function from the Event class, which prints a different message
// For wumpus, let the message be "You smell something foul."
class Wumpus : public Event{
public:
    Wumpus();
    void percept() override;    // we are specifically going to override this.
};

#endif