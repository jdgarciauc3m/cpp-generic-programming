#include <iostream>
#include <format>

namespace geom {
  class shape {
  public:
    shape(double cx, double cy) : x_{cx}, y_{cy} {}

    template <char left ='<', char right = '>'>
    void print() const {
      std::cout << std::format("{} {} , {} {}", left, x_, y_, right);
    }
  private:
    double x_;
    double y_;
  };
}


void f() {
  geom::shape shp{{1.0, 2.0}};
  shp.print<'[',']'>();
}

template <typename S>
void g() {
  S shp{{1.0,2.0}};
  shp.template print<'[',']'>();
}

int main() {
  f();
  g<geom::shape>();
}
