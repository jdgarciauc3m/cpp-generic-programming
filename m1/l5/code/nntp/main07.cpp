#include <format>
#include <gsl/gsl>
#include <iostream>

struct value_limits {
    constexpr value_limits(double vlow, double vhigh)  // NOLINT
      : low{vlow}, high{vhigh} {
      Expects(vlow <= vhigh);
    }

    double low;
    double high;
};

std::ostream & operator<<(std::ostream & out, value_limits const & vlim) {
  return out << std::format("[{},{}]", vlim.low, vlim.high);
}

template <value_limits limits>
double limit_value(double x) {
  if (x < limits.low) { return limits.low; }
  if (x > limits.high) { return limits.high; }
  return x;
}

void f1() {
  constexpr value_limits lim1{1.0, 3.0};                          // NOLINT
  std::cout << lim1 << limit_value<lim1>(5.0) << '\n';            // NOLINT
  std::cout << limit_value<value_limits{3.0, 8.0}>(5.0) << '\n';  // NOLINT
}

int main() {
  f1();
}