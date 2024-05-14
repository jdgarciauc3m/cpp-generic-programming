#include <format>
#include <iostream>

template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template <arithmetic R, arithmetic T, arithmetic U>
R squares_sum(T x, U y) {
  return x * x + y * y;
}

template <typename T, typename U, typename R>
void print_squares_sum(T x, U y, R r) {
  std::cout << std::format("|<{},{}>|^2 = {}\n", x, y, r);
}

int main() {
  auto a = squares_sum<int, int, int>(2, 3);  // NOLINT
  print_squares_sum(2, 3, a);

  auto b = squares_sum<double, double, double>(2.0, 3.1);  // NOLINT
  print_squares_sum(2.0, 3.1, b);                          // NOLINT

  auto c = squares_sum<double, double>(2.0, 3.1);  // NOLINT
  print_squares_sum(2.0, 3.1, c);                  // NOLINT
}
