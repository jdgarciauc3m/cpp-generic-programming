#include <iostream>
#include <cstring>

template <std::totally_ordered T>
T maximum(T x, T y) {
  return x > y ? x : y;
}

template <typename T>
T * maximum(T * px, T * py) {
  return (*px > * py) ? px : py;
}

char const * maximum(char const * s1, char const * s2) {
  return std::strcmp(s1,s2)>0 ? s1 : s2;
}

template <typename T>
T maximum(T x, T y, T z) {
  return maximum(maximum(x,y),z);
}

int main() {
  auto r1 = maximum(2,4);
  std::cout << r1 << '\n';

  double a = 2.5, b = 3.2;
  double *pa = &a, *pb = &b;
  auto r2 = maximum(pa,pb); // max of pointers
  std::cout << r2 << '\n';

  // Max of C-strings
  auto r3 = maximum("Daniel", "Carlos");
  std::cout << r3 << '\n';

  auto r4 = maximum("Daniel", "Carlos", "Maria");
  std::cout << r4 << '\n';
}
