#include <iostream>
#include <vector>
#include <list>

template <template <typename, typename> typename C, typename E, typename A>
concept container =
    std::semiregular<C<E,A>> and
    std::ranges::range<C<E,A>> and
    requires(C<E,A> cont, E elem) {
  { cont.push_back(elem) } -> std::same_as<void>;
};

template<template <typename, typename> typename R,
    template<typename, typename> typename S, typename E, typename A>
    requires container<R,E,A> and container<S,E,A>
auto convert(S<E, A> const &s) {
  R<E, A> result;
  for (auto const &elem: s) {
    result.push_back(elem);
  }
  return result;
}

template<std::ranges::range C>
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


