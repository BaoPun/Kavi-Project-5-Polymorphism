#ifndef GOLD_HPP
#define GOLD_HPP

#include "./event.hpp"

// Class that represents the gold event.
// Here, we will define the percept function from the Event class, which prints a different message
// For gold, let the message be "You can see a glimmering light nearby."
class Gold : public Event{
public:
    Gold();
    void percept() override;    // we are specifically going to override this.
};



#endif