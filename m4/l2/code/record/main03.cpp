#include <string>
#include <format>
#include "record3.hpp"

int main() {
  record<int, std::string, double> rec{1969, "Daniel", 1.82}; // NOLINT
  std::cout << std::format("{}: {} ({})\n", myget<0>(rec), myget<1>(rec), myget<2>(rec));
  rec.print();
}


