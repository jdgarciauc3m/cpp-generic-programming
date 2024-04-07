#include <iostream>
#include <format>

template <bool formatted, std::integral T>
void print_value(T x) {
  if constexpr (formatted) {
    std::cout << std::format("{:10}\n", x);
  }
  else {
    std::cout << x << '\n';
  }
}

template <std::integral T, bool formatted = (sizeof(T) > sizeof(int)) >
void print_integral(T x) {
  std::cout << std::format("size = {}\n", sizeof(T));
  if constexpr (formatted) {
    std::cout << std::format("{:10}\n", x);
  }
  else {
    std::cout << x << '\n';
  }
}

void f1() {
  print_value<true>(2);
  print_value<false>(2);
}

void f2() {
  print_integral(42); // NOLINT
  print_integral(42L); // NOLINT
  print_integral(42LL); // NOLINT
}

int main() {
  f1();
  f2();
}
