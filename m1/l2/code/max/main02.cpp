#include <iostream>
#include <format>

template <typename T>
concept arithmetic = std::is_arithmetic_v<T>;

template <arithmetic T>
T maximum(T x, T y) {
  return (x > y) ? x : y;
}

void print(arithmetic auto x) {
  std::cout << std::format("{} -> {}\n", x, typeid(x).name());
}

int main() {
  arithmetic auto r0 = maximum(5,3); // NOLINT
  print(r0);

  // arithmetic auto r1 = maximum(5,3L);
  // print(r1);

  // arithmetic auto r2 = maximum(2.0f, 3);
  // print(r2);
}