#include <format>
#include <iostream>
#include <source_location>

template <typename T>
consteval std::string_view full_name_of() noexcept {
  return std::source_location::current().function_name();
}

template <typename T>
consteval std::string_view nameof() noexcept {
  constexpr std::string_view str = full_name_of<T>();
  constexpr std::string_view prefix = "[with T = ";
  constexpr std::size_t start = str.find(prefix) + prefix.length();
  constexpr std::size_t count = str.find(';') - start;
  return str.substr(start, count);
}

template <typename T>
constexpr std::string_view type_name_v = nameof<T>();

void print_values() { }

template <typename T>
void print_values(T x) {
  std::cout << std::format("{} ({})\n", x, type_name_v<T>);
}

template <typename T1, typename T2>
void print_values(T1 x1, T2 x2) {
  std::cout << std::format("{} ({}) , ", x1, type_name_v<T1>);
  print_values(x2);
}

template <typename T1, typename T2, typename T3>
void print_values(T1 x1, T2 x2, T3 x3) {
  std::cout << std::format("{} ({}) , ", x1, type_name_v<T1>);
  print_values(x2, x3);
}

int main() {
  print_values();
  print_values("Daniel", 1969);        // NOLINT
  print_values("Daniel", 1969, 1.82);  // NOLINT
}
