#include <format>
#include <iostream>
#include <variant>

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
void test1() try {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  std::variant<int, std::string, double> v;

  v               = 42.0;
  auto x          = get<double>(v);  // x == 42
  std::size_t idx = v.index();       // idx == 2
  std::cout << std::format("index = {}, value = {}\n", idx, x);

  v = "Daniel";
  auto y = get<1>(v);
  std::cout << std::format("index = {}, value = {}\n", 1, y);

  auto d = get<int>(v);  // Might throw
  std::cout << d << '\n';
} catch (std::bad_variant_access const & e) { std::cerr << e.what() << '\n'; }

struct point {
    point(double cx, double cy) : x{cx}, y{cy} {}
    double x, y;
};

void test2() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  std::variant<int, std::string, double> var1;
  auto value      = get<0>(var1);
  std::size_t idx = var1.index();
  std::cout << std::format("index = {}, value = {}\n", idx, value);

  // std::variant<point, double> var2;

  std::variant<std::monostate, point, std::array<double,2>> var3  ; // NOLINT
  [[maybe_unused]] auto value3      = get<0>(var3);
  std::size_t idx3 = var3.index();
  std::cout << std::format("index = {}, value = empty\n", idx3);
  var3.emplace<std::array<double,2>>(std::array{1.0,2.0}); // NOLINT
  idx3 = var3.index();
  std::cout << std::format("index = {}, value = {}\n", idx3, get<2>(var3)[1]);

  // std::variant<> var4;
}

void test3() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  std::variant<int, point> var1{std::in_place_type<point>, 1, 1};
  std::cout << std::format("index = {}\n", var1.index());
  std::variant<int, point,double> var2{std::in_place_index<2>, 1};
  std::cout << std::format("index = {}\n", var2.index());
}
// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)

int main() try {
  test1();
  test2();
  test3();
} catch (std::bad_variant_access const & e) { std::cerr << e.what() << '\n'; }
