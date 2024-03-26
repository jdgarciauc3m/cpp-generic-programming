#include <iostream>

template<typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template<arithmetic T, arithmetic U>
T squares_sum(T x, U y) {
  return x * x + y * y;
}

template<typename T, typename U>
void print_squares_sum(T x, U y) {
  auto r = squares_sum(x, y);
  std::cout << "|<" << x << "," << y << ">|^2 = " << r << '\n';
}

int main() {
  print_squares_sum(2, 3); // OK.
  print_squares_sum(2.1, 3);
  print_squares_sum(2, 3.1);
}


