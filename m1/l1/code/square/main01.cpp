#include <iostream>

int square(int x) {
  return x*x;
}

long square(long x) {
  return x*x;
}

int main() {
  std::cout << square(2) << '\n';
  std::cout << square(2L) << '\n';
}
