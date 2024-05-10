#include <format>
#include <iostream>
#include <vector>

template <std::integral T, std::integral U>
void print_add(std::vector<T> const & vec1, std::vector<U> const & vec2) {
  auto i = vec1.begin();
  auto j = vec2.begin();
  for (; i != vec1.end(); ++i, ++j) {
    std::integral auto sum = *i + *j;
    if (sum > 0) { std::cout << std::format("{} + {} = {}\n", *i, *j, sum); }
  }
}

void test1() {
  std::vector<int> v1{1, -1, 2, - 2};
  std::vector<long> v2{1, 1, 1, 1};
  print_add(v1,v2);
}

int main() {
  test1();
}

