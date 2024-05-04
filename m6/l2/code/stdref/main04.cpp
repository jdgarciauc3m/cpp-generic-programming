#include <format>
#include <functional>
#include <iostream>

void print(std::string_view prefix, std::string_view postfix, int value) {
  std::cout << std::format("{} {} {}\n", prefix, value, postfix);
}

void update(double & value, double delta) {
  value += delta;
}

void test1() {
  using namespace std::placeholders;
  auto f = std::bind(print,"[ ", " ]", _1); // NOLINT
  f(42); // NOLINT

  double x = 1.2; // NOLINT
  auto g = std::bind(update, _1, .5); // NOLINT
  g(x);
  std::cout << std::format("x = {}\n", x);
  auto h = std::bind(update,x, .25); // NOLINT
  h();
  std::cout << std::format("x = {}\n", x);
}

void test2() {
  using namespace std::placeholders;
  auto f = std::bind(print,"[ ", " ]", _1); // NOLINT
  f(42); // NOLINT

  double x = 1.2; // NOLINT
  auto g = std::bind(update, _1, .5); // NOLINT
  g(x);
  std::cout << std::format("x = {}\n", x);
  auto h = std::bind(update,std::ref(x), .25); // NOLINT
  h();
  std::cout << std::format("x = {}\n", x);
}

void test3() {
  using namespace std::placeholders;
  auto f = [](int x) { print("[ ", " ]", x); };
  f(42); // NOLINT

  double x = 1.2; // NOLINT
  auto g = [](double & x) { update(x, .5); };
  g(x);
  std::cout << std::format("x = {}\n", x);
  auto h = [&x] { update(x, .25); };
  h();
  std::cout << std::format("x = {}\n", x);

}

int main() {
  test1();
  test2();
  test3();
}