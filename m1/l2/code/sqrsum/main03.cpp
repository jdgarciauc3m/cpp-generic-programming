#include <format>
#include <iostream>

template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

void print_squares_sum(arithmetic auto x, arithmetic auto y) {
  std::cout << std::format("|<{},{}>|^2 = {}\n", x, y, x * x + y * y);
}

int main() {
  print_squares_sum(2, 3);
  print_squares_sum(2.1, 3); // NOLINT
  print_squares_sum(2, 3.1); // NOLINT
}
