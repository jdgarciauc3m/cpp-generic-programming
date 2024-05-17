#include <iostream>
#include "fixed_vector.hpp"

void f(fixed_vector<double,32> const & vec) { // NOLINT
  vec.print(std::cout);
  std::cout << '\n';
  vec.print(std::cerr);
  std::cerr << '\n';
  vec.print(std::wcout);
  std::wcout << '\n';
}

void f2() { // NOLINT
  fixed_vector<double,32> vec; // NOLINT
  for (int i=0;i<10; ++i) { // NOLINT
    vec.push_back(double(i)+0.5); // NOLINT
  }
  fixed_vector<double,32> vec2{vec}; // NOLINT
  vec2.print(std::cout);
  std::cout << '\n';
  fixed_vector vec3 = vec;
  vec3.print(std::cout);
  std::cout << '\n';
  fixed_vector<int, 12> vec4 = vec; // NOLINT
  std::cout << "vec4: ";
  vec4.print(std::cout);
  std::cout << '\n';
//  fixed_vector<std::string, 12> vec5 = vec; // NOLINT
//  std::cout << "vec5: ";
//  vec5.print(std::cout);
//  std::cout << '\n';
  vec4 = fixed_vector<int,20>{}; // NOLINT
  std::cout << "vec4: ";
  vec4.print(std::cout);
  std::cout << '\n';
}

template <typename T, int N>
void print(fixed_vector<T,N> const & vec) {
  vec.template print<std::ostream>(std::cout);
}

int main() {
  fixed_vector<double,32> vec; // NOLINT
  for (int i=0;i<10; ++i) { // NOLINT
    vec.push_back(double(i));
  }
  f(vec);
  f2();
}
