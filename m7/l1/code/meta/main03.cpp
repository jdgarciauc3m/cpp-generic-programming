#include <format>
#include <iostream>

template <typename T, std::size_t ... I>
void print_dimension(T & , std::index_sequence<I...>) { // NOLINT
  ((std::cout << std::format("  Dimension {}: {}\n",I, std::extent_v<T,I>)), ...);
}

template <typename T>
void print_info(std::string_view name, T & arr) {
  std::cout << std::format("name {}\n", name);
  if constexpr (std::is_array_v<T>) {
    std::cout << std::format("  is an array of {} dimensions\n", std::rank_v<T>);
    print_dimension(arr, std::make_index_sequence<std::rank_v<T>>{});
  } else {
    std::cout << "  Is not an array\n";
  }
}

void test1() {
  int x = 0;
  print_info("x", x);
  int v1[100];  // NOLINT
  print_info("v1", v1);
  double v2[50][200];  // NOLINT
  print_info("v2", v2);
}

int main() {
  test1();
}
