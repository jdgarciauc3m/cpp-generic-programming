#include <iostream>
#include <string>
#include <complex>

template <typename T>
concept arithmetic = std::is_arithmetic_v<T>;

template <arithmetic T>
T maximum(T x, T y) {
  return (x>y) ? x : y;
}

void print(arithmetic auto x) {
  std::cout << x << " -> " << typeid(x).name() << '\n';
}

int main() {
  //arithmetic auto r1 = maximum(5,3L);
  //print(r1);

  //arithmetic auto r2 = maximum(2.0f, 3);
  //print(r2);
}