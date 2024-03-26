#include <iostream>

#include "tname.hpp"

template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

double add_squares(double x, double y) {
  std::cout << "add_squares(double,double) ->";
  return x * x + y * y;
}

template <arithmetic T>
T add_squares(T x, T y) {
  auto name = type_name<T>();
  std::cout << "add_squares<" << name << ">(" << name << "," << name << ") ->";
  return x * x + y * y;
}

int main() {
  auto r1 = add_squares(2.0, 3.5);
  std::cout << r1 << '\n';

  auto r2 = add_squares(2,3);
  std::cout << r2 << '\n';

  auto r3 = add_squares(2.5f, 3.5f);
  std::cout << r3 << '\n';

  auto r4 = add_squares(2, 3.5);
  std::cout << r4 << '\n';

  auto r5 = add_squares<>(2.0, 3.5);
  std::cout << r5 << '\n';

  auto r6 = add_squares<int>(2.0, 3.5);
  std::cout << r6 << '\n';

  //auto r7 = add_squares<>(2, 3.5); // Ambiguous
}
