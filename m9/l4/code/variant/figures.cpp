#include <iostream>
#include <format>
#include <numbers>
#include <vector>
#include <algorithm>
#include <numeric>

struct point {
    double x;
    double y;
};

std::ostream & operator<<(std::ostream & os, point p) {
  return os << std::format("({},{})",p.x, p.y);
}

struct size {
    double width, height;
};

std::ostream & operator<<(std::ostream & os, size s) {
  return os << std::format("({},{})", s.width, s.height);
}

class circle {
  public:
    circle(point c, double r) : center_{c}, radius_{r} {}
    [[nodiscard]] double area() const { return radius_ * std::numbers::pi; }
    friend std::ostream & operator<<(std::ostream & os, circle const & c) {
      return os << "circle[" << c.center_ << " , " << c.radius_ << "]";;
    }
  private:
    point center_;
    double radius_;
};

class rectangle {
  public:
    rectangle(point o, size s) : origin_{o}, size_{s} {}
    [[nodiscard]] double area() const { return size_.width * size_.height; }
    friend std::ostream & operator<<(std::ostream & os, rectangle const & r) {
      return os << "circle[" << r.origin_ << " , " << r.size_ << "]\n";;
    }
  private:
    point origin_;
    size size_;
};

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
int main() try {
  using figure = std::variant<circle, rectangle>;
  using diagram = std::vector<figure>;
  diagram diag{
    circle{{1.0,1.0}, 3.0},
    rectangle{{1.5, 1.5}, {3.2, 4.1}}
  };
  for (auto const & fig : diag) {
    std::visit([](auto const & f) { std::cout << f << '\n'; }, fig);
  }
  auto sum = std::transform_reduce(diag.begin(), diag.end(), 0.0,
              [](double x, double y) {return x+y; },
              [](auto const & fig) {
                return std::visit([](auto const & f) { return f.area(); }, fig);
              });
  std::cout << std::format("sum areas = {}\n", sum);
}
catch (std::exception const & e) {
  std::cerr << "Error: " << e.what() << '\n';
}
// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)