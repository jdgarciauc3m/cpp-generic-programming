#include <iostream>

template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template <arithmetic T>
void print_modulo(T x, T y) {
  std::cout << "| <" << x << "," << y << "> | = " << x*x + y*y <<'\n';
}

int main() {
  print_modulo(2,3);
  //print_modulo(2.0,3);
  print_modulo<double>(2.0,3);
  print_modulo<int>(2.0,3);
  //print_modulo(2,3.0);
}
