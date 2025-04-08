  #include <iostream>
  #include <format>

  #include "numbers.hpp"

  int main() {
    fixed_vector<int> vec{200}; // NOLINT
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.print(std::cout);
    std::cout << std::format("\ncomputation = {}\n", compute(vec));
  };
