#include <iostream>
#include <concepts>
#include <format>

template <typename T>
concept arithmetic = std::is_arithmetic_v<T>;

void print_square(arithmetic auto x) {
  std::cout << std::format("{}^2 = {}\n", x, x*x);
}

int main() {
  print_square(2);
  print_square(2L);
  print_square(2.0); // NOLINT
}
