#include <iostream>
#include <array>

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)
// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
void f1() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  int vec1[5] {1, 2, 3, 4, 5};
  for (auto x : vec1) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  double vec2[] {1, 2, 3, 4, 5};
  for (auto x : vec2) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}
// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
// NOLINTEND(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
void f2() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  std::array<int, 5> vec1{1, 2, 3, 4, 5};
  for (auto x : vec1) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  std::array vec2 = std::to_array<double>({1, 2, 3, 4, 5});
  for (auto x : vec2) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

  std::array vec3{1, 2, 3, 4, 5};
  for (auto x : vec3) {
    std::cout << x << ' ';
  }
  std::cout << '\n';

}
// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)

int main() {
  f1();
  f2();
}
