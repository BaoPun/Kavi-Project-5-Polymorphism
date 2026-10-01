#ifndef NONE_HPP
#define NONE_HPP

#include "./event.hpp"

// The default event state is that there is No event.
// Thus, name of event is "None" and message string is "".
class None : public Event{
public:
    None();
    void percept() override;
};


#endif