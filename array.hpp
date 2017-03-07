#ifndef ARRAY_HPP
#define ARRAY_HPP



#include <vector>
#include "value.hpp"


class Array : public Value, public std::vector<Value*> {
public:
  using std::vector<Value*>::vector;
  inline int weight() {return 1 + size(); }

  inline ~Array() { for(auto i : *this) delete i; } 


};

#endif
