#ifndef STRING_HPP
#define STRING_HPP

#include "value.hpp"
#include <string>

class String : public Value, public std::string {
public:
    using std::string::string;
    
    inline int weight() { return 1; }

};


#endif
