#include <iostream>

#include "tname.hpp"

template <typename T>
concept arithmetic =
    std::integral<T> or
    std::floating_point<T>;

template <arithmetic T>
T squares_sum(T x, T y) {
  auto name = type_name<T>();
  std::cout << "squares_sum<" << name << ">(" << name << "," << name << ") -> ";
  return x * x + y * y;
}

template <typename R, typename T>
R squares_sum(T x, T y) {
  auto name = type_name<T>();
  auto rname = type_name<R>();
  std::cout << "squares_sum<" << rname << ">(" << name << "," << name << ") -> ";
  return x * x + y * y;
}

int main() {
  auto r1 = squares_sum(2, 3);
  std::cout << r1 << '\n';

  auto r2 = squares_sum<double>(2, 3);
  std::cout << r2 << '\n';

  //auto r3 = squares_sum<int>(2,3); // Ambiguous
}