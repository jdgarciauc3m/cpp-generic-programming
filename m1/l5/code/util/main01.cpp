#include <iostream>
#include <format>

class value {
public:
  value(std::string_view id, double x) : name{id}, val{x}  {}
  double const * operator&() const { return &val; }
private:
  std::string name;
  double val;
};

template <typename T>
void print_address(T && object) { // NOLINT
  void const * ptr = &object;
  std::cout << std::format("address = {}\n", ptr);
}

template <typename T>
void print_better_address(T && object) { // NOLINT
  void const * ptr = std::addressof(object);
  std::cout << std::format("address = {}\n", ptr);
}

void test1() {
  int max = 100; // NOLINT
  print_address(max);

  value val{"price", 7.35}; // NOLINT
  print_address(val);

  print_address(5); // NOLINT
}

void test2() {
  int max = 100; // NOLINT
  print_better_address(max);

  value val{"price", 7.35}; // NOLINT
  print_better_address(val);
}

void test3() {
  value v{"price", 2.5}; // NOLINT
  void const * pobj = std::addressof(v);
  void const * pval = &v;
  std::cout << std::format("{}\n{}\n", pobj, pval);

}

int main() {
  test1();
  test2();
}
