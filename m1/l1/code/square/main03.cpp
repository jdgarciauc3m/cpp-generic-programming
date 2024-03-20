#include <iostream>

void print_square(std::integral auto x) {
  std::integral auto r = x * x;
  //print(x);
  static_assert(sizeof(int) <= sizeof(long));
}

void print_value(int x) { std::cout << x << '\n'; }
void print_value(long) = delete;

void print_square2(std::integral auto x) {
  std::integral auto r = x * x;
  print_value(x);
  static_assert(sizeof(x) == sizeof(int));
}

int main() {
  print_square2(2);
  print_square2(2L);
}