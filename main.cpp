#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include <fstream>
#include <cstring>


#include "value.hpp"
#include "null.hpp"
#include "array.hpp"
#include "bool.hpp"
#include "number.hpp"
#include "object.hpp"
#include "string.hpp"
#include "helper.hpp"




int main(int argc, char* argv[]) {
  assert(argc == 2);  // Crash not-so-gracefully if incorrect number of arguments
  

  std::fstream fileName(argv[1]);
  std::string content( (std::istreambuf_iterator<char>(fileName) ),
                       (std::istreambuf_iterator<char>()    ) );

  fileName.close();

  std::vector<Value*> document;

  char* first = &content[0];
  char* last = &content[content.size()];

  while(first != last) {
    document.push_back( parseJson(first, last) );
    
  }
 
  // int document_weight = weight(document);

  return 0;

}


