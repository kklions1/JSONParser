#ifndef OBJECT_HPP
#define OBJECT_HPP


#include <unordered_map>

#include <string>
#include "value.hpp"




class Object : public Value, public std::unordered_map<std::string, Value*> {
public:
  using std::unordered_map<std::string, Value*>::unordered_map;
  inline int weight() { return 1+ size(); }

  inline ~Object() { for(auto i : *this) { delete i.second; } } 


};



#endif