#include <iostream>

void print(auto x) {
  std::cout << "value = " << x << '\n';
}

void print(auto * p) {
  std::cout << "value = " << *p << '\n';
}

void print(auto x, auto y) {
  print(x);
  print(y);
}

void print(char const * s) {
  std::cout << "string = \"" << s << "\"\n";
}

int main() {
  int x = 42;
  print(x);

  int * px = &x;
  print(px);

  using namespace std::literals;
  print("Daniel"s);

  print("Daniel");

  std::cout << "\nprint(42, \"Daniel\")\n";
  print(42, "Daniel");
}


