#include <chrono>
#include <cmath>
#include <format>
#include <functional>
#include <iostream>
#include <random>
#include <utility>
#include <vector>

using coordinates = std::vector<std::tuple<double, double>>;

struct map {
    [[nodiscard]] double distance_to(double x, double y) const;
    coordinates points;
};

double map::distance_to(double x, double y) const {
  double res = 0;
  for (auto [x1, y1] : points) {
    res += std::sqrt(std::pow(x1 - x, 2) + std::pow(y1 - y, 2));
  }
  return res;
}

template <typename F, typename... A>
auto measure(F && fun, A &&... args) {
  using namespace std::chrono;
  auto start    = high_resolution_clock::now();
  double result = std::invoke(std::forward<F>(fun),std::forward<A>(args)...);
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
  map region{make_coordinates(1000)};                              // NOLINT
  auto [dif2, distance] = measure(&map::distance_to, region, 1.5, 1.5);  // NOLINT
  std::cout << std::format("Distance = {:.2}\n", distance);
  std::cout << std::format("Time to compute = {:L}\n", dif2);
}

int main() {
  test();
}
