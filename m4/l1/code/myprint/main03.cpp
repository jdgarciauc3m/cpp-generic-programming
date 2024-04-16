#include <iostream>

void print_values() { std::cout << '\n'; }

template <typename T>
void print_values(T x) {
  std::cout << x << '\n';
}

template <typename T, typename ... Args>
void print_values(T x, Args ... args) {
  std::cout << x << " , ";
  print_values(args...);
}

int main() {
  print_values();
  print_values("Daniel", 1969); // NOLINT
  print_values("Daniel", 1969, 1.82); // NOLINT
}
