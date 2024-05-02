#include <iostream>
#include <vector>
#include <list>
#include <deque>

template<typename R, typename T>
R convert(T const & s) {
  R result;
  for (auto const & elem : s) {
    result.push_back(elem);
  }
  return result;
}

template <typename C>
void print(C const & c) {
  for (auto const & elem : c) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}

int main() {
  std::vector vec{1.5, 2.2, 3.5}; // NOLINT
  auto lst = convert<std::list<int>>(vec);
  print(vec);
  print(lst);
  auto flst = convert<std::deque<double>>(lst);
}
