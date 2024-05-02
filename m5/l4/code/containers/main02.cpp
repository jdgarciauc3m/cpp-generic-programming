#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template<template<typename, typename> typename R,
    template<typename, typename> typename T, typename E, typename A>
auto convert(T<E, A> const &cont) {
  R<E, A> result;
  std::ranges::copy(cont, std::back_inserter(result));
  return result;
}

template<typename C>
void print(C const &c) {
  for (auto const &elem: c) {
    std::cout << elem << ' ';
  }
  std::cout << '\n';
}

int main() {
  std::vector vec{1.5, 2.2, 3.5}; // NOLINT
  auto lst = convert<std::list>(vec);
  print(vec);
  print(lst);
}

