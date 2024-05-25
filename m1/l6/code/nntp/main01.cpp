#include <algorithm>
#include <experimental/iterator>
#include <iostream>
#include <vector>

template <std::integral T, int value>
bool is_less_than(T x) {
  return x < value;
}

template <int value, std::integral T>
bool is_greater_than(T x) {
  return x > value;
}

template <std::regular T, T value>
bool is_less_than_regular(T x) {
  return x < value;
}

template <int value, std::regular T>
bool is_greater_than_regular(T x) {
  return x > value;
}


template <std::regular auto value>
bool is_greater_auto_than(decltype(value) x) {
  return x > value;
}

template <double value, std::floating_point T>
bool is_greater_fp(T x) {
  return x > value;
}

void f1() {
  int x = 5;  // NOLINT
  std::cout << is_less_than<int, 2>(x) << '\n';
  std::cout << is_greater_than<2>(x) << '\n';
  std::cout << is_greater_auto_than<2>(x) << '\n';
}

void f2() {
  std::vector<int> values{1, 3, 5, 7, 9, 2, 4, 6, 8};  // NOLINT
  std::vector<int> results{};
  std::ranges::copy_if(values, std::back_inserter(results), is_greater_than<4, int>);

  std::ranges::copy_if(values, std::back_inserter(results), [](auto x) {
    return is_greater_than<4>(x);
  });
  std::copy(results.begin(), results.end(),
            std::experimental::make_ostream_joiner(std::cout, " , "));
  std::cout << "\n";
}

void f3() {
  double x = 5.0; // NOLINT
  std::cout << is_greater_fp<2.0>(x) << '\n'; // NOLINT
}

void f4() {
  std::vector<double> values{1, 3, 5, 7, 9, 2, 4, 6, 8};  // NOLINT
  std::vector<double> results{};
  std::ranges::copy_if(values, std::back_inserter(results), is_greater_fp<4.0, double>); // NOLINT
  std::copy(results.begin(), results.end(),
            std::experimental::make_ostream_joiner(std::cout, " , "));
  std::cout << "\n";

}

int main() {
  f1();
  f2();
  f3();
  f4();
}
