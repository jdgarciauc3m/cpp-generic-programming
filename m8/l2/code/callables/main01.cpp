#include <format>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

template <typename T>
void print(T x) {
  std::cout << std::format("size = {}, value = {}\n", sizeof(T), x);
}

class name_printer {
  public:
    name_printer(std::string l, std::string r)
      : left_{std::move(l)}, right_{std::move(r)} { }

    void operator()(std::string s) {
      std::cout << std::format("{} {} {}\n", left_, s, right_);
    }

  private:
    std::string left_;
    std::string right_;
};

template <std::ranges::range C, typename P, typename F>
  requires(std::predicate<F, std::ranges::range_value_t<C>> and
           std::invocable<P, std::ranges::range_value_t<C>>)
void store_filtered(C const & cont, P printer, F filterer) {
  for (auto && x : cont) {
    if (not filterer(x)) { continue; }
    printer(x);
  }
}

void test() {
  std::vector values{.1, .2, .3, .4};  // NOLINT
  store_filtered(values, print<double>, [](auto x) {
    return x > 0.25;  // NOLINT
  });
  using namespace std::literals;
  std::vector names{"Daniel"s, "Carlos"s, "Maria"s};
  store_filtered(
      names,
      [](auto x) {
        std::cout << std::quoted(x) << '\n';
      },
      [](auto x) {
        return not x.empty();
      });
  store_filtered(names, name_printer{"<<", ">>"}, [](auto x) {
    return not x.starts_with("M");
  });
}

int main() {
  test();
}