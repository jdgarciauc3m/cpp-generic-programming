#include <format>
#include <iostream>
#include <span>
#include <vector>

template <typename T, std::size_t N>
void print(std::span<T, N> spn) {
  if constexpr (N == std::dynamic_extent) {
    std::cout << "span<dynamic> -> ";
  } else {
    std::cout << std::format("span<{}> -> ", N);
  };
  std::cout << std::format("[ size() = {}] -> ", spn.size());
  for (auto x : spn) { std::cout << x << ' '; }
  std::cout << std::format("span size in bytes ={}", sizeof(spn));
  std::cout << '\n';
}

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)
// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
void test1() {
  int arr[]{1, 2, 3, 4, 5};
  std::span<int, 5> spn1{arr};
  print(spn1);

  std::array sarr{1, 3, 5, 7};
  std::span<int, 4> spn2{sarr};
  print(spn2);

  std::vector vec{1, 4, 9};
  std::span<int, 3> spn3{vec};
  print(spn3);
}

void test2() {
  int arr[]{1, 2, 3, 4, 5};
  std::span<int> spn1{arr};
  print(spn1);

  std::array sarr{1, 3, 5, 7};
  std::span<int> spn2{sarr};
  print(spn2);

  std::vector vec{1, 4, 9};
  std::span<int> spn3{vec};
  print(spn3);
}

auto get_array() {
  return std::array{1,2,3,4,5};
}

void test3() {
  std::span<int,3> spn{get_array().begin(), 3};
  print(spn);

  std::vector vec{1,2};
  std::span spn2{vec};
  vec.reserve(1000);
  spn2 = vec;
  print(spn2);

  std::span spn3{vec.begin(), vec.end()};
  print(spn3);
}

void print_names(std::span<std::string> names) {
  for (int i=0; auto const & n : names) {
    std::cout << std::format("name[{}] = {}\n", i++, n);
  }
}

void test4() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  std::vector<std::string> vec{"Daniel", "Carlos", "Maria"};
  print_names(vec);
}

template <std::size_t N>
void print_fixed_names(std::span<std::string,N> names) {
  for (int i=0; auto const & n : names) {
    std::cout << std::format("name[{}] = {}\n", i++, n);
  }
}

void test5() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  std::vector<std::string> vec{"Daniel", "Carlos", "Maria"};
  print_fixed_names(std::span<std::string,3>{vec});
  //print_fixed_names(vec);
}
// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
// NOLINTEND(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
}
