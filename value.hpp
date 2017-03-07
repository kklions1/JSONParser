#ifndef VALUE_HPP
#define VALUE_HPP


class Value  {
public:
  inline virtual ~Value() {} 

  virtual int weight() = 0;

};


#endif
