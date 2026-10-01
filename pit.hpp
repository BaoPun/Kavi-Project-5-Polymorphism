#ifndef PIT_HPP
#define PIT_HPP

#include "./event.hpp"


// Class that represents the pit event.
// Here, we will define the percept function from the Event class, which prints a different message
// For pit, let the message be "You suddenly feel a chilly breeze."
class Pit : public Event{
public:
    Pit();
    void percept() override;    // we are specifically going to override this.
};

#endif