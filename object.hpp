#ifndef OBJECT_HPP
#define OBJECT_HPP


#include <unordered_map>
#include <memory>
#include <string>





class Object : public Value, std::unordered_map<std::string, std::unique_ptr<Value>> {
public:
  using std::unordered_map<std::string, std::unique_ptr<Value>>::unordered_map;


};



#endif