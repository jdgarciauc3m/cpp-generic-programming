#include <string>
#include <format>
#include "record2.hpp"

int main() {
  record<int, std::string, double> rec{1969, "Daniel", 1.82}; // NOLINT
  std::cout << std::format("{}: {} ({})\n", get<0>(rec), get<1>(rec), get<2>(rec));
  rec.print();
}

