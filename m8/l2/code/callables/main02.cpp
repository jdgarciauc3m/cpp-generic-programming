#include <chrono>
#include <cmath>
#include <format>
#include <functional>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

using coordinates = std::vector<std::tuple<double, double>>;

double compute(coordinates const & c1, coordinates const & c2) {
  double res = 0;
  for (auto [x1, y1] : c1) {
    for (auto [x2, y2] : c2) {
      res += std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
    }
  }
  return res;
}

template <typename F, typename... A>
auto measure(F && fun, A && ... args) {
  using namespace std::chrono;
  auto start    = high_resolution_clock::now();
  //double result = std::forward<F>(fun)(std::forward<A>(args)...);
  double result = std::forward<F>(fun)(std::forward<A>(args)...);
  auto end      = high_resolution_clock::now();
  return std::tuple{duration_cast<microseconds>(end - start), result};
}

auto make_coordinates(std::size_t max) {
  std::vector<std::tuple<double, double>> res;
  res.reserve(max);
  std::random_device rd;
  std::uniform_real_distribution<double> gen{0.0, 1000.0};  // NOLINT
  for (std::size_t i = 0; i < max; ++i) { res.emplace_back(gen(rd), gen(rd)); }
  return res;
}

void test() {
  auto c1               = make_coordinates(1000);  // NOLINT
  auto c2               = make_coordinates(200);   // NOLINT
  auto ptr = std::make_unique<std::string>("computing...");
  auto fun = [&, ptr_text = std::move(ptr)] {
    std::cout << *ptr_text << '\n';
    return compute(c1,c2);
  };
  auto [dif2, distance] = measure(fun);
  std::cout << std::format("Distance = {:.2}\n", distance);
  std::cout << std::format("Time to compute = {:L}\n", dif2);
}

int main() {
  test();
}
