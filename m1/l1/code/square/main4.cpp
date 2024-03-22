#include <iostream>
#include <concepts>

void print_square(std::integral auto x) {
  std::cout << x << "^2 = " << x*x << '\n';
}

void print_square(std::floating_point auto x) {
  std::cout << x << "^2 = " << x*x << '\n';
}

int main() {
  print_square(2);
  print_square(2L);
  print_square(2.0);
}
