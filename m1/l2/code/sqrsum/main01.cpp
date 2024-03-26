#include <iostream>

template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template <arithmetic T>
void print_squares_sum(T x, T y) {
  std::cout << "|<" << x << "," << y << ">|^2 = " << x*x + y*y <<'\n';
}

int main() {
  print_squares_sum(2, 3);
  //print_modulo(2.0,3);
  print_squares_sum<double>(2.0, 3);
  print_squares_sum<int>(2.0, 3);
  //print_modulo(2,3.0);
}
