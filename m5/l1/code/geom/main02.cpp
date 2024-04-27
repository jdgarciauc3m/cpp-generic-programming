#include <iostream>
#include <format>

namespace geom {
  struct point {double x, y; };

  void print(point p) {
    std::cout << std::format("[{} , {}]\n", p.x, p.y);
  }

}

void print(int x) {
  std::cout << std::format("value ={}\n", x);
}

  template <typename T>
  void print_value(T value) {
    print(value);
  }


void f() {
  int value = 42;
  print(value);
  geom::point origin{0.0, 0.0};
  print_value(origin);
}

int main() {
  f();
}