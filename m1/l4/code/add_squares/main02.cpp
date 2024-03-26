#include <iostream>

#include "tname.hpp"

template <typename T>
concept arithmetic =
    std::integral<T> or
    std::floating_point<T>;

template <arithmetic T>
T add_squares(T x, T y) {
  auto name = type_name<T>();
  std::cout << "add_squares<" << name << ">(" << name << "," << name << ") -> ";
  return x * x + y * y;
}

template <typename R, typename T>
R add_squares(T x, T y) {
  auto name = type_name<T>();
  auto rname = type_name<R>();
  std::cout << "add_squares<" << rname << ">(" << name << "," << name << ") -> ";
  return x * x + y * y;
}

int main() {
  auto r1 = add_squares(2,3);
  std::cout << r1 << '\n';

  auto r2 = add_squares<double>(2,3);
  std::cout << r2 << '\n';

  //auto r3 = add_squares<int>(2,3); // Ambiguous
}