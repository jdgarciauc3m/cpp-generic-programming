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

void f1() {
// NOLINTBEGIN
  fixed_vector<double> vec{10};
  print_vector(vec);

  std::cout << "\npush_back(1)\npush_back(2)\n";
  vec.push_back(1);
  vec.push_back(2);
  print_vector(vec);
  auto vec2 = vec;

  fixed_vector<std::string> names{5};
  names.push_back("Daniel");
  names.push_back("Maria");
  print_vector(names);
// NOLINTEND
}

void f2() {
// NOLINTBEGIN
  //fixed_vector<std::unique_ptr<std::string>> vec{10};
// NOLINTEND
}

void f3() {
  // NOLINTBEGIN
  fixed_vector<double> marks{10};
  marks.push_back(1.5);
  marks.push_back(2.5);
  marks.push_back(3.5);
  marks.serialize(std::cout);

  using entry = std::tuple<std::string, double>;
  fixed_vector<entry> students{4};
  students.push_back({"John", 5});
  //students.serialize(std::cout);
  // NOLINTEND
}

int main() {
  f1();
  f2();
  f3();
}
