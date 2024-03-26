#include <iostream>

void print(auto x) {
  std::cout << "value = " << x << '\n';
}

void print(auto * p) {
  std::cout << "address = " << static_cast<void*>(p);
  std::cout << ". value = " << *p << '\n';
}

int main() {
  int x = 42;
  print(x);

  int * px = &x;
  print(px);

  using namespace std::literals;
  print("Daniel"s);

  // print("Daniel"); // Error cannot cast char const * to void *
}
