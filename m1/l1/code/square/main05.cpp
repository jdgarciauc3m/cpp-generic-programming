#include <iostream>
#include <concepts>

template <typename T>
concept arithmetic = std::is_arithmetic_v<T>;

void print_square(arithmetic auto x) {
  std::cout << x << "^2 = " << x*x << '\n';
}

int main() {
  print_square(2);
  print_square(2L);
  print_square(2.0);
}
