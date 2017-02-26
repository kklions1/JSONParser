#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <memory>
#include <vector>


class Array : public Value, public std::vector<std::unique_ptr<Value>> {
public:
  using std::vector<std::unique_ptr<Value>>::vector;
};

#endif
