#include <iostream>

template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

void print_squares_sum(arithmetic auto x, arithmetic auto y) {
  std::cout << "|<" << x << "," << y << ">|^2 = " << x*x + y*y <<'\n';
}

int main() {
  print_squares_sum(2, 3);
  print_squares_sum(2.1, 3);
  print_squares_sum(2, 3.1);
}
