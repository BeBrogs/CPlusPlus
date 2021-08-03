#include <iostream>
#include "profile.hpp"

int main() {
  Profile brogan("Brogan", 21, "Belfast", "Ireland");
  std::cout << brogan.get_name() << std::endl; 
  
}
