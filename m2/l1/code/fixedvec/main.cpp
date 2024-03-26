#include <iostream>

#include "fixed_vector.hpp"

#include <stacktrace>

template <std::regular T>
void print_vector(fixed_vector<T> const & v) {
  std::cout << "  capacity = " << v.capacity() << '\n';
  std::cout << "  size = " << v.size() << '\n';
  for (int i=0; i<v.size(); ++i) {
    std::cout << "  v[" << i << "] = " << v[i] << '\n';
  }
}

int main() {
  std::set_terminate([]() {
    std::cerr << "Terminate called\n";
  });

  fixed_vector<double> v{10};
  print_vector(v);

  std::cout << "\npush_back(1)\npush_back(2)\n";
  v.push_back(1);
  v.push_back(2);
  print_vector(v);

}
