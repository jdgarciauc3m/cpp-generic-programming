#include <format>
#include <iostream>

template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template <arithmetic T, arithmetic U>
void print_squares_sum(T x, U y) {
  std::cout << std::format("|<{},{}>|^2 = {}\n", x, y, x * x + y * y);
}

int main() {
  print_squares_sum(2, 3);
  print_squares_sum(2.1, 3);               // NOLINT
  print_squares_sum(2, 3.1);               // NOLINT
  print_squares_sum<int>(2, 3.1);          // NOLINT
  print_squares_sum<int, double>(2, 3.1);  // NOLINT
  //print_squares_sum<int, int>(2, 3.1);     // NOLINT
}
