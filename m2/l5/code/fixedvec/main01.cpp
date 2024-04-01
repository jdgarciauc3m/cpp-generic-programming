#include <iostream>

#include "fixed_vector.hpp"

template <std::semiregular T>
using allocated_vector = fixed_vector<T, allocated_storage<T>>;

template <std::semiregular T>
using local_vector = fixed_vector<T, local_storage<T>>;

template <std::semiregular T>
void print(local_vector<T> const & v) {
  std::cout << v << '\n';
}
void f1() {
  local_vector<std::string> names{10};
  names.push_back("Daniel");
  names.push_back("Carlos");
  print(names);
}

int main() {
  f1();
}
