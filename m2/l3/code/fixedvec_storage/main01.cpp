#include <iostream>

#include "fixed_vector.hpp"

void f1() {
  fixed_vector<std::string, local_storage<std::string>> names{10};
  names.push_back("Daniel");
  names.push_back("Carlos");
  std::cout << names << "\n";
}

void f2() {
  fixed_vector<std::string, allocated_storage<std::string>> names{10};
  names.push_back("Daniel");
  names.push_back("Carlos");
  std::cout << names << "\n";
}

int main() {
  f1();
  f2();
}
