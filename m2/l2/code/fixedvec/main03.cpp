#include "fixed_vector3.hpp"
#include <string>
#include <iostream>


void f1() {
  // NOLINTBEGIN
  fixed_vector<std::string> names{10};
  names.push_back("Carlos");
  names.push_back("Daniel");
  serialize(std::cout, names);
  std::cout << '\n' << names;
  // NOLINTEND
}

int main() {
  f1();
}


