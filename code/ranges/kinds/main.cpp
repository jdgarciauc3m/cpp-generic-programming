#include <algorithm>
#include <iostream>
#include <ranges>
#include <algorithm>
#include <vector>
#include <print>

namespace {
  void print1(std::vector<double> const & vec) {
    auto it = std::ranges::find_if(vec, [](auto x) { return x < 0; });
    auto sr = std::ranges::subrange(vec.begin(), it);
    auto sum = std::ranges::fold_left(sr, 0.0, std::plus{});
    std::println("{}: {}", __func__, sum);
  }

  template <typename I>
  struct negative_end {
    I it_end;
    bool operator==(I it) const {
      return it == it_end or *it<0;;
    }
  };

  void print2(std::vector<double> const & vec) {
    double sum = 0.0;
    negative_end const end_sentinnel{vec.end()};
    for (auto it =  vec.begin(); it != end_sentinnel; ++it) {
      sum += *it;
    }
    std::println("{}: {}", __func__, sum);
  }

  void print3(std::vector<double> const & vec) {
    double sum = 0.0;
    for (auto x : std::ranges::subrange{vec.begin(), negative_end{vec.end()}}) {
      sum += x;
    }
    std::println("{}: {}", __func__, sum);
  }

  void print4(std::vector<double> const & vec) {
    double sum = std::ranges::fold_left(
      std::ranges::subrange {vec.begin(), negative_end{vec.end()}},
      0.0, std::plus{});
    std::println("{}: {}", __func__, sum);
  }

  void print_counted1(std::vector<double> const & vec, std::size_t nelem) {
    double sum = 0.0;
    auto counted = std::ranges::subrange{vec.begin(), negative_end{vec.end()},nelem};
    for (auto x : counted) {
      sum += x;
    }
    std::println("{}: {}", __func__, sum);
    std::println("  size: {}", counted.size());
    std::println("  distance(rng): {}", std::ranges::distance(counted));
    std::println("  distance(it1,it2): {}", std::ranges::distance(counted.begin(), counted.end()));
  }

  void print_counted2(std::vector<double> const & vec, std::ptrdiff_t nelem) {
    double sum = 0.0;
    for (auto x: std::views::counted(vec.begin(), nelem)) {
      sum += x;
    }
    std::println("{}: {}", __func__, sum);
  }

  void print_take1(std::vector<double> const & vec, std::ptrdiff_t nelem) {
    double sum = 0.0;
    for (auto x: std::views::take(vec, nelem)) {
      sum += x;
    }
    std::println("{}: {}", __func__, sum);
  }

  void print_take2(std::vector<double> const & vec, std::ptrdiff_t nelem) {
    double sum = 0.0;
    for (auto x: vec | std::views::take(nelem)) {
      sum += x;
    }
    std::println("{}: {}", __func__, sum);
  }
}

int main() {
  std::vector<double>  const v{1, 2, 3, -1, 5};
  print1(v);
  print2(v);
  print3(v);
  print4(v);
  print_counted1(v, 2);
  print_counted2(v, 2);
  print_counted2(v, 4);
  print_take1(v, 2);
  print_take1(v, 100);
  print_take2(v, 2);
  print_take2(v, 100);
}
