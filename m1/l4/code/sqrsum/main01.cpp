#include <iostream>

#include "tname.hpp"

template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

double squares_sum(double x, double y) {
  std::cout << "squares_sum(double,double) ->";
  return x * x + y * y;
}

template <arithmetic T>
T squares_sum(T x, T y) {
  auto name = type_name<T>();
  std::cout << "squares_sum<" << name << ">(" << name << "," << name << ") ->";
  return x * x + y * y;
}

int main() {
  auto r1 = squares_sum(2.0, 3.5);
  std::cout << r1 << '\n';

  auto r2 = squares_sum(2, 3);
  std::cout << r2 << '\n';

  auto r3 = squares_sum(2.5f, 3.5f);
  std::cout << r3 << '\n';

  auto r4 = squares_sum(2, 3.5);
  std::cout << r4 << '\n';

  auto r5 = squares_sum<>(2.0, 3.5);
  std::cout << r5 << '\n';

  auto r6 = squares_sum<int>(2.0, 3.5);
  std::cout << r6 << '\n';

  //auto r7 = squares_sum<>(2, 3.5); // Ambiguous
}
