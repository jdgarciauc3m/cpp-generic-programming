#include <string>
#include <format>
#include "record1.hpp"

void f1() {
  record<int, std::string, double> rec{1969, "Daniel", 1.82}; // NOLINT
  std::cout << std::format("{}\n", rec.first());
  rec.print();
}

void f2() {
  int year = 1969; // NOLINT
  std::string name = "Daniel";
  double height = 1.82; // NOLINT
  record<int, std::string, double> rec{year, name, height};
  rec.print();
  record<int, std::string, double> rec2{};
  rec.print();
}
int main() {
  f1();
  f2();
}
