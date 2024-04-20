#include <iostream>

template <typename T, T ... Is>
void print_seq(std::integer_sequence<T,Is...>) {
  std::cout << "[";
  ((std::cout << Is << ' '),...);
  std::cout << "]\n";
}

void f() {
  std::integer_sequence<int, 1, 3, 5, 7> s1;
  print_seq(s1);
  print_seq(std::integer_sequence<long,2,4>{});
}

int main() {
  f();
}
