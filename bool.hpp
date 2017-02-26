#ifndef BOOL_HPP
#define BOOL_HPP


class  Boolean : public Value {
public:
  Boolean(bool b) : val(b) {}
  bool val;
  ~Boolean();

};

#endif

