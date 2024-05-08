#include <functional>
#include <iostream>
#include <format>

auto positive(int x) { return x>0; }

struct max_value {
    auto operator()(double x, double y) const { return x>y?x:y; }
};

struct add_value {
    static auto apply(long x, long y) { return x+y; }
    using func_ptr = long(*)(long,long);
    operator func_ptr() const { return apply; }
};

struct value {
    [[nodiscard]] bool greater_than(float k) const { return x>k; }
    float x;
};

void test() {
  using ret1 = std::invoke_result_t<decltype(positive), int>;
  static_assert(std::is_same_v<ret1, bool>);
  auto positive_ptr = positive;
  using ret1b = std::invoke_result_t<decltype(positive_ptr), int>;
  static_assert(std::is_same_v<ret1b, bool>);

  auto res1 = std::invoke(positive, 42);
  std::cout << std::format("res1 = {}\n", res1);

  using ret2 = std::invoke_result_t<max_value, double, double>;
  static_assert(std::is_same_v<ret2,double>);

  max_value mvobj;
  auto res2 = std::invoke(mvobj, 1.5, 2.5);
  std::cout << std::format("res1 = {}\n", res2);

  auto lmb = [] { std::cout << "lambda\n"; };
  using ret3 = std::invoke_result_t<decltype(lmb)>;
  static_assert(std::is_same_v<ret3,void>);

  std::invoke(lmb);

  using ret4 = std::invoke_result_t<add_value,long,long>;
  static_assert(std::is_same_v<ret4,long>);

  auto res4 = std::invoke(add_value{}, 1L, 2L);
  std::cout << std::format("res4 = {}\n", res4);

  using ret5 = std::invoke_result_t<decltype(&value::greater_than),value,double>;
  static_assert(std::is_same_v<ret5, bool>);

  auto res5 = std::invoke(&value::greater_than, value{}, -3);
  std::cout << std::format("res5 = {}\n", res5);

  using ret6 = std::invoke_result_t<decltype(&value::x), value>;
  static_assert(std::is_same_v<ret6,float&&>);

  value val6{33}; // NOLINT
  auto res6 = std::invoke(&value::x, val6);
  std::cout << std::format("res6 = {}\n", res6);
}

int main() {
  test();
}