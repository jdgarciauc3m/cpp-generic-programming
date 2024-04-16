#include <iostream>

//void print_values() {}

template <typename T, typename... Args>
void print_values(T x, Args... args) {
  std::cout << x << " , ";
  if constexpr(sizeof...(Args) > 0) { print_values(args...); }
}

int main() {
  //print_values();
  print_values("Daniel", 1969);        // NOLINT
  print_values("Daniel", 1969, 1.82);  // NOLINT
}
