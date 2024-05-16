#include <format>
#include <iostream>
#include <span>
#include <vector>

template <typename T, std::size_t N>
void print(std::span<T, N> spn) {
  if constexpr (N == std::dynamic_extent) {
    std::cout << "span<extent = dynamic> -> ";
  } else {
    std::cout << std::format("span<extent = {}> -> ", N);
  };
  std::cout << std::format(" bytes={} ", sizeof(spn));
  std::cout << std::format("[ size() = {}] -> ", spn.size());
  for (auto x : spn) { std::cout << x << ' '; }
  std::cout << '\n';
}

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)
// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
void test1() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  std::vector vec{1, 2, 3, 4, 5};
  print(std::span{vec.begin(), vec.end()});
  print(std::span{vec.begin(), vec.size()});

  print(std::span<int, 3>{vec.begin(), vec.end()});
  print(std::span<int, 7>{vec.begin(), vec.size()});
}

void test2() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  int v[]{1, 2, 3, 4, 5};
  print(std::span{v});
  print(std::span<int>{v});
  print(std::span<int,5>{v});
  //print(std::span<int,7>{v});
}

void test3() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  std::array v{1, 2, 3, 4, 5};
  print(std::span{v});
  print(std::span<int>{v});
  print(std::span<int,5>{v});
  //print(std::span<int,7>{v});
}

void test4() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  std::vector v{1, 2, 3, 4, 5};
  print(std::span{v});
  print(std::span<int>{v});
  print(std::span<int,5>{v});
  print(std::span<int,7>{v});
}

void test5() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
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
