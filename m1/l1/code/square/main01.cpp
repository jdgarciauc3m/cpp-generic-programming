#include <iostream>

void print_square(int x) {
  std::cout << x << "^2 = " << x*x << '\n';
}

void print_square(long x) {
  std::cout << x << "^2 = " << x*x << '\n';
}

int main() {
  print_square(2);
  print_square(2L);
}
