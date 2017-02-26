#ifndef NUMBER_HPP
#define NUMBER_HPP


#include <string> 

class Number : public Value {
public:
    Number(std::string f) : val(f) {}
    std::string val;


};

 
#endif
