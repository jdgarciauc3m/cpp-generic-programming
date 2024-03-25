#include <iostream>

template<typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template<arithmetic T, arithmetic U>
T modulo(T x, U y) {
  return x * x + y * y;
}

template<typename T, typename U>
void print_modulo(T x, U y) {
  auto r = modulo(x,y);
  std::cout << "| <" << x << "," << y << "> | = " << r << '\n';
}

int main() {
  print_modulo(2, 3); // OK.
  print_modulo(2.1,3);
  print_modulo(2,3.1);
}


