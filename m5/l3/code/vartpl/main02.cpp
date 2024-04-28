#include <format>
#include <iostream>

template <std::floating_point T>
constexpr T pi = T(3.1415926535897932385); // NOLINT

template <std::floating_point T>
T circle_area(T r) {
  return pi<T> * r * r;
}

template <std::floating_point T>
void print_area(T x) {
  std::cout << std::format("area({}) = {}\n", x, circle_area(x));
}

void f() {
  print_area(2.0); // NOLINT
  print_area(2.0f); // NOLINT
}

int main() {
  f();
}
