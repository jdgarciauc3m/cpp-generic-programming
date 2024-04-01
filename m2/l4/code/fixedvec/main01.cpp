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

void f3() {
  fixed_vector<std::string> names{10};
  names.push_back("Daniel");
  names.push_back("Carlos");
  std::cout << names << "\n";
}

void f4() {
  fixed_vector<> values{10};
  values.push_back(1.5);
  values.push_back(2.5);
  values.push_back(3.5);
  std::cout << values << '\n';
}

int main() {
  f1();
  f2();
  f3();
  f4();
}
