#include <format>
#include <iostream>

template <typename T>
int use_count = 0; // NOLINT

template <typename T>
void log(T x) {
  std::cout << std::format("log: {}, uses = {}\n", x, use_count<T> ++);
}

void f() {
  log(42);    // NOLINT
  log(42.5);  // NOLINT
  log(0);     // NOLINT
  log(-3);    // NOLINT
  log(1);     // NOLINT
  log(3.5);   // NOLINT
}

int main() {
  f();
}
