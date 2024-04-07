#include <iostream>

struct value_limits {
    double low;
    double high;
};

template <value_limits * limits>
double limit_value(double x) {
  static_assert(limits !=nullptr);
  if (x < limits->low) { return limits->low; }
  if (x > limits->high) { return limits->high; }
  return x;
}

value_limits lim1{1.0, 5.0}; // NOLINT

void f1() {
  std::cout << limit_value<&lim1>(0.0) << '\n';

  static value_limits lim2{3.0, 7.0}; // NOLINT
  std::cout << limit_value<&lim2>(10.0) << '\n'; // NOLINT

  //value_limits lim3{-3.0, 3.0}; // NOLINT
  //std::cout << limit_value<&lim3>(10.0) << '\n'; // NOLINT

  //constexpr value_limits * pnull = nullptr;
  //std::cout << limit_value<pnull>(10.0) << '\n'; // NOLINT
}

int main() {
  f1();
}
