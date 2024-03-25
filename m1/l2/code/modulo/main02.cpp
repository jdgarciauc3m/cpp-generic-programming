#include <iostream>

template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template <arithmetic T, arithmetic U>
void print_modulo(T x, U y) {
  std::cout << "| <" << x << "," << y << "> | = " << x*x + y*y <<'\n';
}

int main() {
  print_modulo(2,3);
  print_modulo(2.1,3);
  print_modulo(2,3.1);
  print_modulo<int>(2,3.1);
  print_modulo<int,double>(2,3.1);
  print_modulo<int,int>(2,3.1);
}

