#include <iostream>
#include <format>

template <typename T>
auto add(T x) {
  return x;
}
template <typename T, typename ... U>
auto add(T x, U ... y) {
  return x + add(y...);
}


template <typename ... T>
auto add2(T ... x) {
  return (x + ... + 0);
}

void f() {
  auto res = add(1.0, 2, 3.5f); // NOLINT
  std::cout << std::format("Add = {}\n", res);
}

template <typename ... T>
void print(T ... x) {
  (std::cout << ... << x) << '\n';
}

void g() {
  auto res1 = add2(1.0, 2, 3.5f); // NOLINT
  std::cout << std::format("Add = {}\n", res1);
  auto res2 = add2();
  std::cout << std::format("Add = {}\n", res2);
}

template <typename T>
class with_extra {
public:
  with_extra(T const & value) : value_{value} {}

  friend std::ostream & operator<<(std::ostream & os, with_extra const & other) {
    return os << other.value_ << ' ';
  }
private:
  T const & value_; // NOLINT
};

void h1() {
  print(1,2,3);
}

template <typename ... T>
void print_with_extra(T ... x) {
  (std::cout << ... << with_extra{x}) << '\n';
}

void h2() {
  print_with_extra(1,2,3);
}

int main() {
  f();
  g();
  h1();
  h2();
}