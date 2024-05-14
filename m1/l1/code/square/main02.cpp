#include <concepts>
#include <format>
#include <iostream>

void print_square(std::integral auto x) {
  std::cout << std::format("{}^2 = {}\n", x, x * x);
}

int main() {
  print_square(2);   // OK. Invoke print_square(int)
  print_square(2L);  // OK. Invoke print_square(long)
  //print_square(2.0); // Error. No matching print_square(double)
}