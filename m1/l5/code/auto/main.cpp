#include <iostream>
#include <vector>
#include <ranges>

template <typename T, typename U>
std::vector<decltype(T{}+U{})> add(std::vector<T> const & v1, std::vector<U> const & v2) {
  std::vector<decltype(v1[0]+v2[0])> result;
  auto i = v1.begin();
  auto j = v2.begin();
  auto end = v1.end();
  for (;i!=end; ++i, ++j) {
    result.push_back(*i+*j);
  }
  return result;
}

template <typename T, typename U>
auto mul(std::vector<T> const & v1, std::vector<U> const & v2) -> std::vector<decltype(v1[0]+v2[0])> {
  std::vector<decltype(v1[0]+v2[0])> result;
  auto i = v1.begin();
  auto j = v2.begin();
  auto end = v1.end();
  for (;i!=end; ++i, ++j) {
    result.push_back(*i**j);
  }
  return result;
}

void print(std::ranges::range auto && rng) {
  for (auto && x : rng) {
    std::cout << x << ", ";
  }
  std::cout << '\n';
}

int main() {
  std::vector a {1,2,3,4};
  std::vector b {5,6,7,8};
  auto c = add(a,b);
  auto d = mul(a,b);
  print(c);
  print(d);
}
