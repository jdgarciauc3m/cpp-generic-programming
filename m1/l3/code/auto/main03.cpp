#include <format>
#include <iostream>
#include <vector>

int f() {
  return 0;
}

void test1() {
  // X x1 = f();
  auto x1 = f();  // X x1
  std::cout << std::format("x1 = {}\n", x1);

  // X & x2 = f(); // Error. Cannot bind reference to temporal.
  // auto & x2 = f(); // Error. Cannot bind reference to temporal.

  auto && x3 = f();
  std::cout << std::format("x3 = {}\n", x3);
}

int max = 0;  // NOLINT

int & g() {
  return max;
}

void test2() {
  // X x1 = g();
  auto x1 = g();  // X x1
  std::cout << std::format("x1 = {}\n", x1);

  // X & x2 = g();
  auto & x2 = g();  // X & x2
  std::cout << std::format("x2 = {}\n", x2);

  auto && x3 = g();
  std::cout << std::format("x3 = {}\n", x3);
}

auto make_vector() {
  return std::vector{1, 2, 3};
}

void test3() {
  std::vector<int> v1{1, 2, 3};
  for (auto x : v1) { std::cout << std::format("{}\n", x); }
  for (auto & x : v1) { std::cout << std::format("{}\n", x); }
  for (auto && x : v1) { std::cout << std::format("{}\n", x); }
}

void test4() {
  for (auto x : make_vector()) { std::cout << std::format("{}\n", x); }
  for (auto & x : make_vector()) { std::cout << std::format("{}\n", x); }
  for (auto && x : make_vector()) { std::cout << std::format("{}\n", x); }
}

template <typename R>
void print(R && rng) {  // NOLINT
  for (auto x : rng) { std::cout << std::format("{}\n", x); }
  for (auto & x : rng) { std::cout << std::format("{}\n", x); }
  for (auto && x : rng) { std::cout << std::format("{}\n", x); }
}

void test5() {
  std::vector<int> v1{1, 2, 3};
  print(v1);
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
}
