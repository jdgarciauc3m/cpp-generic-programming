#include <experimental/iterator>
#include <gsl/gsl>
#include <iostream>
#include <ranges>

template <typename T>
void classic_print_array(T * vec, std::size_t size) {
  for (std::size_t i=0; i<size; ++i) {
    std::cout << vec[i] << ", "; // NOLINT
  }
  std::cout << '\n';
}

template <typename T, std::size_t size>
void print_array(T (&vec)[size]) {  // NOLINT
  for (auto x : vec) { // NOLINT
    std::cout << x << ", ";
  }
  std::cout << '\n';
}

int main() {
  int values[4] = {1, 2, 3, 4};    // NOLINT
  classic_print_array(values, 4);  // NOLINT
  print_array(values);
}
