#include <iostream>
#include <concepts>

std::integral auto square(std::integral auto x) {
  return x*x;
}

std::floating_point auto square(std::floating_point auto x) {
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