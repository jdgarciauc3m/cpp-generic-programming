#include <iostream>

void print_values() { }

template <typename T, typename ... Args>
void print_values(T x, Args ... args) {
  std::cout << x;
  if (sizeof...(args) > 0) {
    std::cout << " , ";
    print_values(args...);
  }
  else {
    std::cout << "\n";
  }
}

int main() {
  print_values();
  print_values("Daniel", 1969); // NOLINT
  print_values("Daniel", 1969, 1.82); // NOLINT
}