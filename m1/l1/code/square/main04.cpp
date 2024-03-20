#include <iostream>
#include <concepts>

template <typename T>
concept arithmetic = std::is_arithmetic_v<T>;

arithmetic auto square(arithmetic auto x) {
  return x*x;
}

std::integral auto reciprocal(std::integral auto x) {
  return 1.0/x;
}

int main() {
  std::cout << square(2) << '\n';
  std::cout << square(2L) << '\n';
  std::cout << square(2.0) << '\n';

  //std::cout << reciprocal(2) << '\n';
}
