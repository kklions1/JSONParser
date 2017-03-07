#ifndef HELPER_HPP
#define HELPER_HPP


Value* parseTrue(char*&, char*);  
Value* parseFalse(char*&, char*); 
Value* parseString(char*&, char*);
Value* parseNull(char*&, char*);  
Value* parseNumber(char*&, char*);
Value* parseJson(char*& , char*);
Value* parseArray(char*&, char*);
Value* parseObject(char*&, char*);
void skip(char*&, char*);





#endif