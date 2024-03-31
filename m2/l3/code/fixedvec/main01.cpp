#include "fixed_vector.hpp"
#include <string>
#include <iostream>


void f1() {
  // NOLINTBEGIN
  fixed_vector<std::string> names{10};
  names.push_back("Carlos");
  names.push_back("Daniel");
  std::cout << names << '\n';
  // NOLINTEND
}

void f2() {
  std::string person1 = "Daniel";
  std::string person2 = "Carlos";
  fixed_vector<std::string*> names{8};
  names.push_back(&person1);
  names.push_back(nullptr);
  names.push_back(&person2);
  std::cout << names << '\n';
}

int main() {
  f1();
  f2();
}


