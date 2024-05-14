#include <format>
#include <iostream>

template <typename T, typename U>
  requires std::totally_ordered_with<T, U>
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
  auto r1 = maximum(5, 3L);  // NOLINT
  print(r1);
  std::cout << typeid(std::common_type_t<int, long>).name() << '\n';

  auto r2 = maximum(2.0F, 3);  // NOLINT
  print(r2);

  auto r3 = maximum("carlos", "daniel");  // NOLINT
  print(r3);

  using namespace std::literals;
  auto r4 = maximum("carlos"s, "daniel"s);
  print(r4);

  auto r5 = maximum(std::tuple<double, int>{2, 3}, std::tuple<double, int>{0, 0});
  print(r5);
}
