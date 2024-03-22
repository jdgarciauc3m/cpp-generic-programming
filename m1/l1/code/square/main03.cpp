#include <iostream>

void print_square1(std::integral auto x) {
#if 0
  print("hello"); // Undeclared identifier print
  std::integral auto r = x * x // Syntax error: mssing semicolon
  static_assert(sizeof(int) >= sizeof(long)); // static_assert failed
#endif
}

void print_value(int x) { std::cout << x << '\n'; }
void print_value(long) = delete;

void print_square2(std::integral auto x) {
  print_value(x); // OK if instantiated with x of type int
  std::integral auto r = x * x;
  static_assert(sizeof(x) == sizeof(int));
}

int main() {
  print_square1(2); // OK
#if 0
  print_square2(2L); // Error: cannot instantiate for long
#endif
}