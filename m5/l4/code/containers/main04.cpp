#include <iostream>
#include <vector>
#include <format>
#include <ranges>

template<template<typename, typename> typename C>
class filtered_numbers {
public:
  filtered_numbers(int low, int high) : minval_{low}, maxval_{high} {}

  void add_value(int x) {
    if (x < minval_ or x > maxval_) { return; }
    values_.push_back(x);
  }

  void print() const {
    std::ranges::copy(values_, std::ostream_iterator<int>(std::cout, ", "));
  }

private:
  int minval_;
  int maxval_;
  C<int, std::allocator<int>> values_{};
};

int main() {
  filtered_numbers<std::vector> num{0, 10}; // NOLINT
  num.add_value(2); // NOLINT
  num.add_value(5); // NOLINT
  num.add_value(12); // NOLINT
  num.add_value(3); // NOLINT
  num.print();
}
