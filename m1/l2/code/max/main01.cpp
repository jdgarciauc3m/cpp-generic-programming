#include <iostream>
#include <format>

template <typename T>
concept arithmetic = std::is_arithmetic_v<T>;

auto maximum(arithmetic auto x, arithmetic auto y) {
  return (x > y) ? x : y;
}

void print(arithmetic auto x) {
  std::cout << std::format("{} -> {}\n", x, typeid(x).name());
}

int main() {
  arithmetic auto r1 = maximum(5, 3L); // NOLINT
  print(r1);

  arithmetic auto r2 = maximum(2.0F, 3); // NOLINT
  print(r2);
}
