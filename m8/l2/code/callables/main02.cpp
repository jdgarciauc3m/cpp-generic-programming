#include <format>
#include <iostream>
#include <vector>

struct point {
    void print() const { std::cout << std::format("{}, {}\n", x, y); }

    [[nodiscard]] bool first_quadrant() const { x > 0 and y > 0; }

    double x;
    double y;
};

template <std::ranges::range C, typename P, typename F>
  requires(std::predicate<F, std::ranges::range_value_t<C>> and
           std::invocable<P, std::ranges::range_value_t<C>>)
void print_filtered(C const & cont, P printer, F filterer) {
  for (auto && x : cont) {
    if (not filterer(x)) { continue; }
    printer(x);
  }
}

void test() {
  // NOLINTBEGIN
  std::vector<point> vec{
    { 1.0, 2.0},
    {-1.0,   0},
    { 3.5, 2.5}
  };
  // NOLINTEND
  // print_filtered(vec, &point::print, &point::first_quadrant);
  print_filtered(
      vec,
      [](auto const & p) {
        p.print();
      },
      [](auto const & p) {
        return p.first_quadrant();
      });
}
