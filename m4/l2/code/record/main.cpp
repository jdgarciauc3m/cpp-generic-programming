#include <iostream>
#include <format>

#include "record.hpp"
#include <tuple>

int main() {
  record<std::string, double> rec1{"Daniel", 1.5}; // NOLINT
  std::cout << std::format("a = {}\n",get<0>(rec1));
  get<0>(rec1) = "Bjarne";
  std::cout << std::format("a = {}\n",get<0>(rec1));
  std::cout << std::format("a = {}\n",get<0>(rec1));

  auto rec2{rec1};
  std::cout << std::format("a = {}\n\n",get<0>(rec1));

  auto rec3{std::move(rec2)}; // NOLINT
  std::cout << std::format("a = {}\n",get<0>(rec1));
  std::cout << std::format("c = {}\n\n",get<0>(rec3));

  record<std::string,double> rec4 {get<0>(rec1), get<1>(rec1)};
  std::cout << std::format("a = {}\n",get<0>(rec1));
  std::cout << std::format("d = {}\n\n",get<0>(rec4));

  record<std::string, long double> rec5 {rec4};

  auto rec6 = make_record("Daniel", 42); // NOLINT
  std::cout << std::format("rec6: {}, {}\n\n", get<0>(rec6), get<1>(rec6));
}
