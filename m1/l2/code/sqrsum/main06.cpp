#include <iostream>

template<typename T>
concept arithmetic = std::integral<T> or std::floating_point<T>;

template<arithmetic T, arithmetic U, arithmetic R>
R squares_sum(T x, U y) {
  return x * x + y * y;
}

template<typename T, typename U, typename R>
void print_squares_sum(T x, U y, R r) {
  std::cout << "| <" << x << "," << y << "> |^2 = " << r << '\n';
}

int main() {
  auto a = squares_sum<int, int, int>(2, 3);
  print_squares_sum(2, 3, a);

  auto b = squares_sum<double, double, double>(2.0, 3.1);
  print_squares_sum(2, 3, a);

  //auto c = squares_sum<double, double>(2.0, 3.1);
  //auto d = squares_sum(2.0, 3.1);

}



