#include <iostream>
#include <format>
#include <vector>
#include <algorithm>

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

template <double value, std::floating_point T>
bool is_greater(T x) {
  return x>value;
}

void f3() {
  double x = 5.0; // NOLINT
  std::cout << "Greater<5.0>(2.0): " << is_greater<5.0>(x) << '\n'; // NOLINT
  x = 1.0;
  std::cout << "Greater<5.0>(7.0): " << is_greater<5.0>(x) << '\n'; // NOLINT

  std::vector<double> values{1, 3, 5, 7, 9, 2, 4, 6, 8}; // NOLINT
  std::vector<double> results{};
  std::ranges::copy_if(values,
                       std::back_inserter(results),
                       is_greater<4.0, double>); // NOLINT
  for (auto val : results) {
    std::cout << val << ", ";
  }
  std::cout << '\n';
}

int main() {
  f1();
  f2();
  f3();
}
