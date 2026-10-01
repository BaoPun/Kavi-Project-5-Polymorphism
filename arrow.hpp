#ifndef ARROW_HPP
#define ARROW_HPP

#include "./event.hpp"

// Class that represents the arrow event.
// Here, we will define the percept function from the Event class, which prints a different message
// For arrow, let the message be "You see a familiar object nearby."
class Arrow : public Event{
public:
    Arrow();
    void percept() override;    // we are specifically going to override this.
};



#endif