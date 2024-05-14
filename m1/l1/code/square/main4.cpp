#include <iostream>
#include <concepts>
#include <format>

void print_square(std::integral auto x) {
  std::cout << std::format("{}^2 = {}\n", x, x*x);
}

void print_square(std::floating_point auto x) {
  std::cout << std::format("{}^2 = {}\n", x, x*x);
}

int main() {
  print_square(2);
  print_square(2L);
  print_square(2.0); // NOLINT
}
