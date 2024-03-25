#include <iostream>

template<typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template<arithmetic T>
T modulo(T x, T y) {
  return x * x + y * y;
}

template<typename T>
void print_modulo(T x, T y) {
  std::cout << "| <" << x << "," << y << "> | = " << modulo(x,y) << '\n';
}

int main() {
  print_modulo(2, 3);
  print_modulo(2.1,3.2);
  //print_modulo(2.1,3);
}

