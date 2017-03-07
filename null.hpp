#ifndef NULL_HPP
#define NULL_HPP

#include "value.hpp"

class Null : public Value{

    inline int weight() { return 1; }

};


#endif