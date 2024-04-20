#include <iostream>
#include <format>
#include <vector>

template<typename T, typename ... U>
void print(T x, U ... u) {
  std::cout << x << '\n';
  if constexpr (sizeof...(U) > 0) {
    print(u...);
  }
}

template<typename ... T>
void print_values(T const &... x) {
  print(x...);
}

template<typename ... T>
void print_addresses(T const &... x) {
  print(&x...);
}

template<typename T, typename U>
int print_pair(std::pair<T, U> const &value) {
  std::cout << "<" << value.first << " , " << value.second << ">";
  return 0;
}

template<typename ... T>
void print_addresses_sizes(T const &... x) {
  [[maybe_unused]] int vec[sizeof...(T)] = {(print_pair(std::pair{&x, sizeof(x)})) ...}; // NOLINT
}

template <typename ... T>
std::vector<std::string> stringfy(T ... x) {
  return std::vector<std::string> { std::to_string(x)...};
}

int main() {
  int year = 1969; // NOLINT
  std::string name = "Daniel";
  double height = 1.82; // NOLINT
  print_values(year, name, height);
  print_addresses(year, name, height);
  print_addresses_sizes(year, name, height);

  auto str = stringfy(1, 2.5, 3.3f); // NOLINT
  for (auto s : str) { // NOLINT
    std::cout << s << '\n';
  }
}
