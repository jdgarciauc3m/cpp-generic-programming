#include <iostream>
#include <cstring>

template <std::totally_ordered T>
T const & maximum(T const & x, T const & y) {
  return x > y ? x : y;
}

template <typename T>
T const * maximum(T const * px, T const * py) {
  return (*px > * py) ? px : py;
}

char const * maximum(char const * s1, char const * s2) {
  return std::strcmp(s1,s2)>0 ? s1 : s2;
}

template <typename T>
T const & maximum(T const & x, T const & y, T const & z) {
  return maximum(maximum(x,y),z);
}

int main() {
  std::totally_ordered auto r1 = maximum(2,4);
  std::cout << r1 << '\n';

  double a = 2.5, b = 3.2;
  double *pa = &a, *pb = &b;
  std::totally_ordered auto r2 = maximum(pa,pb); // max of pointers
  std::cout << r2 << '\n';

  // Max of C-strings
  auto r3 = maximum("Daniel", "Carlos");
  std::cout << r3 << '\n';

  char const * s1 = "Daniel";
  char const * s2 = "Carlos";
  char const * s3 = "Maria";
  auto r4 = maximum(s1, s2, s3);
  std::cout << r4 << '\n';
}

