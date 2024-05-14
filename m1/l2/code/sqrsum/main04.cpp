#include <iostream>
#include <format>

template<typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template<arithmetic T>
T squares_sum(T x, T y) {
  return x * x + y * y;
}

template<typename T>
void print_squares_sum(T x, T y) {
  std::cout << std::format("|<{},{}>|^2 = {}\n", x, y, squares_sum(x,y));
}

int main() {
  auto a = squares_sum(2, 3); // NOLINT
  std::cout << std::format("a = {}\n", a);

  auto b = squares_sum(2.1, 3.2); // NOLINT
  std::cout << std::format("b = {}\n", b);

  //auto c = squares_sum(2.1, 3);
  //std::cout << std::format("c = {}\n", c);

  print_squares_sum(2, 3);
  print_squares_sum(2.1, 3.2); // NOLINT
  //print_squares_sum(2.1,3);
}

