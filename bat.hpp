#ifndef BAT_HPP
#define BAT_HPP

#include "./event.hpp"

// Class that represents the bat event.
// Here, we will define the percept function from the Event class, which prints a different message
// For bat, let the message be "You hear some flapping noises from somewhere close."
class Bat : public Event{
public:
    Bat();
    void percept() override;    // we are specifically going to override this.
};

#endif