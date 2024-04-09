#include <iostream>
#include <gsl/gsl>
#include <limits>
#include <format>

template <std::integral>
class safe_value;

template <>
class safe_value<int> {
public:
  safe_value() = default;
  explicit safe_value(int x) : value{x} {}

  auto & operator++() {
    Expects(value < std::numeric_limits<int>::max());
    value++;
    return *this;
  }

  [[nodiscard]] int to_int() const { return value; }
private:
  int value{};
};

template <typename T>
concept safe = requires {
  typename safe_value<T>;
};

template <typename T>
concept safe2 = requires {
  safe_value<T>{};
};

template <safe T>
void test1() {
  safe_value<T> var{42}; // NOLINT
  ++var;
  std::cout << std::format("varx = {}\n", var.to_int()) << '\n';
}

template <safe2 T>
void test2() {
  std::cout << "test2()\n";
}


void f() {
  test1<int>();
  //test1<long>();
  test2<int>();
  //test2<long>();
}

int main() {
  f();
}