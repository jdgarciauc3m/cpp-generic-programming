#include <iostream>
#include <complex>
#include <map>
#include <vector>

template <typename T>
void print_size(T x) {
  std::cout << "size = " << sizeof(x) << "\n";
}

void f1() {
  print_size(42);
  print_size(1.2);

  std::complex<double> z{1.0, 2.5};
  print_size(z);

  std::vector<std::map<std::string, int>> v;
  print_size(v);
}

template <typename T, typename U>
void print_pair(std::pair<T,U> const & p) {
  std::cout << "<" << p.first << " , " << p.second << ">\n";
}

void f2() {
  std::pair<int,std::string> p{1969, "Daniel"};
  print_pair(p);

  auto q = std::make_pair(1950, "Bjarne");
  print_pair(q);

  std::pair r{1955, "James"}; // Error in C++14. Missing template argument
  print_pair(r);
}

int main() {
  f1();
  f2();
}
