#include <iostream>
#include <format>

template <typename T, typename U>
  requires std::totally_ordered_with<T, U> and (not std::is_pointer_v<T>) and
           (not std::is_pointer_v<U>)
std::common_type_t<T, U> maximum(T x, U y) {
  return (x > y) ? x : y;
}

void print(auto x) {
  std::cout << x << " -> " << typeid(x).name() << '\n';
}

template <typename T, typename U>
void print(std::tuple<T, U> t) {
  std::cout << std::format("{} , {} -> {}\n", std::get<0>(t), std::get<1>(t), typeid(t).name());
}

int main() {
  // auto r3 = maximum("carlos", "daniel");
  // print(r3);

  using namespace std::literals;
  auto r4 = maximum("carlos"s, "daniel"s);
  print(r4);
}
