#include <algorithm>
#include <format>
#include <iostream>
#include <vector>

bool positive(int x) {
  return x > 0;
}

bool negative(int x) {
  return x < 0;
}

struct positive_fobj {
    bool operator()(int x) const { return x > 0; }
};

void count_positives1(std::vector<int> const & v) {
  auto cnt_pos = std::ranges::count_if(v, positive);
  std::cout << std::format("count = {}\n", cnt_pos);
  auto cnt_neg = std::ranges::count_if(v, negative);
  std::cout << std::format("count = {}\n", cnt_neg);
}

void count_positives2(std::vector<int> const & v) {
  auto cnt = std::ranges::count_if(v, positive_fobj{});
  std::cout << std::format("count = {}\n", cnt);
}

void count_positives3(std::vector<int> const & v) {
  auto cnt = std::ranges::count_if(v, [](int x) {
    return x > 0;
  });
  std::cout << std::format("count = {}\n", cnt);
}

struct positive_objptr {
    using fun_ptr = bool (*)(int x);

    positive_objptr(fun_ptr f) : fun_{f} { }

    operator fun_ptr() const { return fun_; }

  private:
    fun_ptr fun_;
};

void count_positives4(std::vector<int> const & v) {
  positive_objptr pos_obj(positive);
  auto cnt = std::ranges::count_if(v, pos_obj);
  std::cout << std::format("count = {}\n", cnt);
}

void test() {
  std::vector vec{-1, 1, 2, 3, 0};
  count_positives1(vec);
  count_positives2(vec);
  count_positives3(vec);
  count_positives4(vec);
}

int main() {
  test();
}
