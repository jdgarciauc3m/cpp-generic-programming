#include <algorithm>
#include <complex>
#include <format>
#include <iostream>
#include <vector>

struct point {
    [[nodiscard]] bool is_first_quadrant() const { return x > 0 and y > 0; }

    double x, y;
};

double distance(point p, point q) {
  auto square = [](auto x) { return x*x; };
  return std::sqrt(square(p.x-q.x) + square(p.y-q.y));
}

void test1() {
  // NOLINTBEGIN
  std::vector<point> vec{ {1.0, 1.0}, {-1.0, 2.0}, {3.5, 2.5}, {-1, -2}};
  // NOLINTEND
  auto cnt = std::ranges::count_if(vec, &point::is_first_quadrant);
  std::cout << std::format("num points = {}\n", cnt);
  auto rightmost = std::ranges::max(vec, {}, &point::x);
  std::cout << std::format("right most point = {}, {}\n", rightmost.x, rightmost.y);
}

int main() {
  test1();
}
