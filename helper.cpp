#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cctype>
#include <cassert>
#include <fstream>
#include <streambuf>
#include <unordered_map>
#include <cstring>

#include "value.hpp"
#include "null.hpp"
#include "array.hpp"
#include "bool.hpp"
#include "number.hpp"
#include "object.hpp"
#include "string.hpp"

// This file contains definitions for all functions needed for 
// the parser


void skip(char*& f, char* l) {
    while(f != l && isspace(*f)) 
        ++f;
}

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

Value* parseJson(char*& f, char* l); 
/* okay, so breaking the 'formal writing' tone these comments
 * generally follow, should i have to forward declare
 * this function? Its declared in the header file, which is included here
 * but the compiler still thinks parseJson is not defined unless this line exists
 * so did I do something wrong? 
 * I mean this works so I'm gonna stick with it.
*/ 

 Value* parseArray(char*& f, char* l) {
     Array* arr = new Array();
     while(*f != ']') {
         ++f;
         char* comma = strchr(f, ',');
         arr->push_back(parseJson(f, comma));
         ++f;
     }
     return arr;
 }



std::string parseSTDString(char*& f, char* l) {
    std::string s;
    ++f;

    while(*f != '"') {
        if(*f == '\\') {
            ++f;
            s.push_back(*f);
            ++f;
        }
        else {
            s.push_back(*f);
            ++f;
        }
    }
    return s;
}

Value* parseObject(char*& f, char* l) {
    Object* object = new Object();

    while(*f != '}') {
        ++f;
        std::string key = parseSTDString(f, l);

        f += 3;
        
        char* parse_until = strchr(f, ',');
        Value* val = parseJson(f, parse_until);

        object->emplace(key, val);
        
        ++f;

    }
    return object;

}


Value* parseJson(char*& f, char* l) {
    if(f != l) {
        if(isspace(*f)) 
        skip(f,l);
    }
    else if(*f == 't') 
        return parseTrue(f, l);
    
    else if(*f == 'f') 
        return parseFalse(f, l);
    
    else if(*f == 'n') 
        return parseNull(f, l);
    
    else if(*f == '"') 
        return parseString(f, l);

    else if(*f == '[') 
        return parseArray(f, l);

    else if(*f == isalnum(*f)) 
        return parseNumber(f, l);
    
    else if(*f == '{') 
        return parseObject(f, l);
    
    else 
        return new Null();

}