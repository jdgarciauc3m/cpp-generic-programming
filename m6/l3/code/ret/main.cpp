#include <iostream>
#include <format>

double square(double x) { return x*x; }


template <typename F, typename T>
T call(F fun, T value) {
  std::cout << std::format("input = {}\t", value);
  T result = fun(value);
  std::cout << std::format("result = {}\t", result);
  return result;
}

template <typename T>
std::remove_reference_t<T> increment(T x) {
  auto ret =  ++x;
  return ret;
}

int main() {
  [[maybe_unused]] auto r1 = call(square, 4);
  double x = 3;
  [[maybe_unused]] auto r2 = call(square, x);
  [[maybe_unused]] auto r3 = increment(x);
  std::cout << x << '\n';
  [[maybe_unused]] auto r4 = increment<double&>(x);
  r4 = 0;
  std::cout << x << '\n';
}
