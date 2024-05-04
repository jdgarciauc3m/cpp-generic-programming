#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main() {
  std::list lst{1, 3, 5, 7, 2, 4, 6, 8}; // NOLINT
  std::vector<std::reference_wrapper<int>> vec{lst.begin(), lst.end()};
  std::ranges::sort(vec);

  std::cout << "vector: ";
  std::ranges::copy(vec, std::ostream_iterator<int>(std::cout, " , "));
  std::cout << '\n';
  std::cout << "list: ";
  std::ranges::copy(lst, std::ostream_iterator<int>(std::cout, " , "));
  std::cout << '\n';
}