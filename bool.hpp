#ifndef BOOL_HPP
#define BOOL_HPP

#include "value.hpp"

class  Boolean : public Value {
public:
  inline Boolean(bool b) : val(b) {}
  bool val;
  inline ~Boolean() { delete this; }
  inline int weight() { return 1; } 
  
};

#endif

