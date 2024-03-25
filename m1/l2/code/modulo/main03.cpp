#include <iostream>

template <typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

void print_modulo(arithmetic auto x, arithmetic auto y) {
  std::cout << "| <" << x << "," << y << "> | = " << x*x + y*y <<'\n';
}

int main() {
  print_modulo(2,3);
  print_modulo(2.1,3);
  print_modulo(2,3.1);
}
