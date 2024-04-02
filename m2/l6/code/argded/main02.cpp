#include <iostream>
#include "counted_value.hpp"

void f1() {
  counted_value a{2.5};
  std::cout << *a << '\n';
  a = 7.5;
  std::cout << *a << '\n';
  std::cout << "count = " << a.count() << '\n';
}

int main() {
  f1();
}