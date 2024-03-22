#include <iostream>
#include <concepts>

void print_square(std::integral auto x) {
  std::cout << x << "^2 = " << x*x << '\n';
}

int main() {
  print_square(2); // OK. Invoke print_square(int)
  print_square(2L); // OK. Invoke print_square(long)
#if 0
  print_square(2.0); // Error. No matching print_square(double)
#endif
}