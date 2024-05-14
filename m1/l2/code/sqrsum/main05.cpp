#include <format>
#include <iostream>

template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template <arithmetic T, arithmetic U>
T squares_sum(T x, U y) {
  return x * x + y * y;
}

template <typename T, typename U>
void print_squares_sum(T x, U y) {
  auto r = squares_sum(x, y); // NOLINT
  std::cout << std::format("|<{},{}>|^2 = {}\n", x, y, r);
}

int main() {
  auto a = squares_sum(2, 3); // NOLINT
  std::cout << std::format("a = {}\n", a);

  auto b = squares_sum(2.1, 3); // NOLINT
  std::cout << std::format("b = {}\n", b);

  auto c = squares_sum(2, 3.1); // NOLINT
  std::cout << std::format("c = {}\n", c);

  print_squares_sum(2, 3);  // OK.
  print_squares_sum(2.1, 3); // NOLINT
  print_squares_sum(2, 3.1); // NOLINT
}
