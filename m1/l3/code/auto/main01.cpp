#include <format>
#include <iostream>
#include <vector>

template <std::integral T>
void print_add(std::vector<T> const & vec1, std::vector<T> const & vec2) {
  for (auto i = vec1.begin(), j = vec2.begin(); i != vec1.end(); ++i, ++j) {
    T sum = *i + *j;
    if (sum > 0) { std::cout << std::format("{} + {} = {}\n", *i, *j, sum); }
  }
}

void test1() {
  std::vector<int> v1{1, -1, 2, - 2};
  std::vector<int> v2{1, 1, 1, 1};
  print_add(v1,v2);
}

int main() {
  test1();
}
