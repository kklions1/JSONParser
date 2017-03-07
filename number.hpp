#ifndef NUMBER_HPP
#define NUMBER_HPP


#include <string> 
#include "value.hpp"

class Number : public Value {
public:

    std::string val;
    inline Number(std::string f) : val(f) {}
    inline int weight() { return 1; }

};

 
#endif
