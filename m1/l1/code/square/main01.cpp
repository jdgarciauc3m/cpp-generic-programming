#include <iostream>
#include <format>

void print_square(int x) {
  std::cout << std::format("{}^2 = {}\n", x, x * x);
}

void print_square(long x) {
  std::cout << std::format("{}^2 = {}\n", x, x*x);
}

int main() {
  print_square(2);
  print_square(2L);
}
