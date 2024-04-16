#include <iostream>


void print_values() {}

template <typename T>
void print_values(T x) {
  std::cout << x << '\n';
}

template <typename T1, typename T2>
void print_values(T1 x1, T2 x2) {
  std::cout << x1 << " , ";
  print_values(x2);
}

template <typename T1, typename T2, typename T3>
void print_values(T1 x1, T2 x2, T3 x3) {
  std::cout << x1 << " , ";
  print_values(x2, x3);
}

int main() {
  print_values();
  print_values("Daniel", 1969); // NOLINT
  print_values("Daniel", 1969, 1.82); // NOLINT
}
