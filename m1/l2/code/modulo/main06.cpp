#include <iostream>

template<typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template<arithmetic T, arithmetic U, arithmetic R>
R modulo(T x, U y) {
  return x * x + y * y;
}

template<typename T, typename U, typename R>
void print_modulo(T x, U y, R r) {
  std::cout << "| <" << x << "," << y << "> | = " << r << '\n';
}

int main() {
  auto a = modulo<int,int,int>(2,3);
  print_modulo(2,3,a);

  auto b = modulo<double,double,double>(2.0, 3.1);
  print_modulo(2,3,a);

  auto c = modulo<double,double>(2.0,3.1);
  auto d = modulo(2.0,3.1);

}



