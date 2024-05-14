#include "fixed_vector1.hpp"
#include <string>
#include <iostream>


void f1() {
  // NOLINTBEGIN
  fixed_vector<std::string> names{10};
  names.push_back("Carlos");
  names.push_back("Daniel");
  //serialize(std::cout, names);
  // NOLINTEND
  std::cout << "size = " << names.size() << '\n';
}

int main() {
  f1();
}
