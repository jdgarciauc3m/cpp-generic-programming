#include <iostream>
#include <vector>
#include <gsl/gsl>
#include <format>

template <typename T>
auto min_value(std::vector<T> const & v) {
  if (v.empty()) { throw std::invalid_argument{"empty vector"}; }
  auto result = v[0];
  for (auto const & value : std::span{v.begin()+1, v.end()}) {
    if (value < result) { result = value; }
  }
  return result;
}

void f() {
  std::vector v{1, 3, 5, 0, 2, 4};
  std::cout << std::format("min = {}\n", min_value(v));
}

class string_value;

void print_min(std::vector<string_value> const & v) {
  std::cout << std::format("min = {}\n", min_value(v).to_string());
}

class string_value {
public:
  explicit string_value(std::string init) : value_{std::move(init)} {}
  friend auto operator<=>(string_value const &, string_value const &) = default;
  [[nodiscard]] auto to_string() const { return value_; }
private:
  std::string value_;
};

void g() {
  std::vector v{
      string_value{"Donald"},
      string_value{"Bjarne"},
      string_value{"Alan"}};
  //print_min(v);
}


int main() {
  f();
  g();
}
