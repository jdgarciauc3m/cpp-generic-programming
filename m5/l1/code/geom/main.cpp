#include <iostream>
#include <format>

struct cartesian_position {
  void print() {
    std::cout << std::format("[{},{}]", x, y);
  }

  double x;
  double y;
};

struct polar_position {
  void print() {
    std::cout << std::format("[{} , {}]", r, theta);
  }

  double r;
  double theta;
};

template <typename P>
concept position = requires(P pos) {
  pos.print();
};

template <position P>
class shape {
public:
  explicit shape(P pos) : pos_{pos} {}

  void print_origin() {
    std::cout << "origin =";
    pos_.print();
  }

private:
  P pos_;
};

template <typename P>
class circle : public shape<P> {
public:
  circle(P pos, double r) : shape<P>{pos}, radius{r} {}

  void print()  {
    this->print_origin();
    std::cout << std::format(" radius = {}", radius);
  }

private:
  double radius;
};


int main() {
  cartesian_position center{1.0,1.0};
  circle<cartesian_position> s1{center, 2.0};
  s1.print();
}
