#include <iostream>

template <typename TPL, std::size_t ... Is>
void print_helper(TPL const & tpl, std::index_sequence<Is...>) {
  ((std::cout << (Is==0 ? "" : ", ") << std::get<Is>(tpl)), ...);
}

template <typename ... T>
void print(std::tuple<T...> const & tpl) {
  std::cout << "[";
  print_helper(tpl, std::index_sequence_for<T...>{});
  std::cout << "]\n";
}

void f() {
  std::tuple var{1969, "Daniel", 1.82};
  print(var);
}

int main() {
  f();
}
