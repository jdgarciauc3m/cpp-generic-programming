#include <format>
#include <iostream>

template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template <arithmetic T>
void print_squares_sum(T x, T y) {
  std::cout << std::format("|<{},{}>|^2 = {}\n", x, y, x * x + y * y);
}

int main() {
  print_squares_sum(2, 3);
  // print_squares_sum(2.0,3);
  print_squares_sum<double>(2.0, 3);  // NOLINT
  print_squares_sum<int>(2.0, 3);     // NOLINT
  // print_squares_sum(2,3.0);
}
