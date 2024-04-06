#include <iostream>

#include "fixed_vector.hpp"

template <std::semiregular T>
using allocated_vector = fixed_vector<T, allocated_storage<T>>;

template <std::semiregular T>
using local_vector = fixed_vector<T, local_storage<T,100>>;

template <std::semiregular T>
void print(local_vector<T> const & v) {
  std::cout << v << '\n';
}

void f1() {
  std::cout << "Running f1()\n";
  local_storage<double,30> space;
  space[1] = 3.5;
  std::cout << "space[1] = " << space[1] << '\n';
  double x = space[3];
  std::cout << "space[3] = " << x << '\n';
}

void f2() {
  local_storage<std::string,10> names;
  local_storage<std::string,4> seasons;

  if (std::is_same_v<decltype(names), decltype(seasons)>) { // NOLINT
    std::cout << "Same type\n";
  }
  else {
    std::cout << "Different types\n";
  }
}

void f3() {
  std::cout << "Running f3()\n";
  local_vector<std::string> names{10};
  names.push_back("Daniel");
  names.push_back("Carlos");
  print(names);
}

int main() {
  f1();
  f2();
  f3();
}
