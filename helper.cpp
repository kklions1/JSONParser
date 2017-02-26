#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>
#include <fstream>
#include <streambuf>

#include "value.hpp"
#include "null.hpp"
#include "array.hpp"
#include "bool.hpp"
#include "number.hpp"
#include "object.hpp"
#include "string.hpp"

// This file contains definitions for all functions needed for 
// the parser

Value* parseTrue(char*& f, char* l) {
    assert(*++f == 'r');
    assert(*++f == 'u');
    assert(*++f == 'e');
    Boolean* b = new Boolean(true);
    return b;

}

Value* parseFalse(char*& f, char* l) {
    assert(*++f == 'a');
    assert(*++f == 'l');
    assert(*++f == 's');
    assert(*++f == 'e');
    Boolean* b = new Boolean(false);
    return b;

}

Value* parseNull(char*& f, char* l) {
    assert(*++f == 'u');
    assert(*++f == 'l');
    assert(*++f == 'l');
    Null* n = new Null; 
    return n;
}

// When we reach a " character, we enter this function
Value* parseString(char*& f, char*l) {
    String* s = new String; // allocate a new string
    ++f; // increment to the next character
    while(*f != '"') { // this checks for the ending quote mark
        // This if statement checks for escape characters
        if(*f == '\\') {  // the irony of this amuses me
            ++f;
            s->push_back(*f);
            ++f;
        }
        else {  // if no escape character found, push into string
            s->push_back(*f);
            ++f;
        }

    }
    return s;
}
  
Value* parseNumber(char*& f, char* l) {
    std::string n; 
    n.push_back(*f);
    ++f;
    while(isalnum(*f) || *f == '-' || *f == '+' || *f == '.') {
        n.push_back(*f);
        ++f;
    }
    Number* num = new Number(n);
    return num;
}

 

Value* parseJson(std::string& reddit) {

}