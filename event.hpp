#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

// Abstract class for all the possible events
class Event{
private:
    string name;                    // what kind of event is this?
    string message;                 // what kind of message will the event print?

public:
    Event(string = "None", string = "");
    virtual void percept() = 0;     // this makes Event abstract, meaning that we cannot instantiate it directly
                                    // children must be instantiated instead
    string get_name() const;
    string get_message() const;
};


#endif