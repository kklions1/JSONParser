#include <iostream>
#include <memory>
#include <string>
#include <cctype>
#include <cassert>
#include <fstream>


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
  
  
  std::fstream ifs("fart.txt");
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );

   std::string filename = argv[1];
/*
   std::ifstream redditJson;
   redditJson.open("reddit.txt");


  // reads the whole file into a large string
  std::string content( (std::istreambuf_iterator<char>(redditJson) ),
                       (std::istreambuf_iterator<char>()    ) );
*/

  std::cout << filename << std::endl;
  std::cout << content << std::endl;
  
  auto first = content.begin();
  auto last = content.end();

  for(int i = 0; i < content.size(); ++i) {
    


  }


  return 0;

}


