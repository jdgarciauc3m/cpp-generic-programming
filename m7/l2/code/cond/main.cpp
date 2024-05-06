#include <format>
#include <iostream>
#include <memory>
#include <vector>

template <typename T>
class local_object {
  public:
    local_object() = default;

    local_object(T init) : value_{std::move(init)} { }

    T & operator*() { return value_; }
    T const & operator*() const { return value_; }

    T * operator->() { return &value_; }
    T const * operator->() const { return &value_; }

  private:
    T value_;
};

template <typename T>
class dynamic_object {
  public:
    dynamic_object() : ptr_{std::make_unique<T>()} { }

    dynamic_object(T init) : ptr_{std::make_unique<T>(init)} { }

    T & operator*() { return *ptr_; }
    T const & operator*() const { return *ptr_; }

    T * operator->() { return ptr_.get(); }
    T const * operator->() const { return ptr_.get(); }

  private:
    std::unique_ptr<T> ptr_;
};

static constexpr inline int size_limit = 128;

template <typename T>
concept large_object = sizeof(T) > size_limit;

template <typename T>
concept small_object = sizeof(T) <= size_limit;

/*
template <typename T>
using optimized_object_t = std::conditional_t<
                           (sizeof(T)>size_limit),
      dynamic_object<T>, local_object<T>>;
*/

template <typename T, bool cond = (sizeof(T)>size_limit)>
struct optimized_object {
    using type = dynamic_object<T>;
};

template <typename T>
struct optimized_object<T,false> {
    using type = local_object<T>;
};

template <typename T>
using optimized_object_t = optimized_object<T>::type;

void test_local() {
  std::cout << std::format("*** {}\n", __PRETTY_FUNCTION__);
  local_object<std::string> var{"Daniel"};  // NOLINT
  std::cout << *var << '\n';
  std::vector<local_object<std::string>> vec;
  for (auto x : {1, 3, 5, 7}) { vec.emplace_back(std::to_string(x)); }
  for (auto x : vec) { std::cout << *x << ' '; }
}

void test_dynamic() {
  std::cout << std::format("*** {}\n", __PRETTY_FUNCTION__);
  dynamic_object<std::string> var{"Daniel"};  // NOLINT
  std::cout << *var << '\n';
  std::vector<dynamic_object<std::string>> vec;
  for (auto x : {1, 3, 5, 7}) { vec.emplace_back(std::to_string(x)); }
  for (auto & x : vec) { std::cout << *x << ' '; }
}

void test_optimized_small() {
  std::cout << std::format("*** {}\n", __PRETTY_FUNCTION__);
  optimized_object_t<std::string> var{"Daniel"};  // NOLINT
  std::cout << *var << '\n';
  std::vector<optimized_object_t<std::string>> vec;
  for (auto x : {1, 3, 5, 7}) { vec.emplace_back(std::to_string(x)); }
  for (auto const & x : vec) { std::cout << *x << ' '; }
}

struct record {
    record() = default;
    record(std::string_view id) : name{id} {}
    std::string name;
    std::array<std::byte, 256> buffer{};  // NOLINT
};

void test_optimized_large() {
  std::cout << std::format("*** {}\n", __PRETTY_FUNCTION__);
  record r{"Daniel"};  // NOLINT
  std::cout << "size -> " << sizeof(r) << '\n';
  optimized_object_t<record> var;  // NOLINT
  *var = record{"Daniel"};
  std::cout << var->name << '\n';
   std::vector<optimized_object_t<record>> vec;
   for (auto x : {1,3,5,7}) {
     vec.push_back(record{std::to_string(x)}); //NOLINT
   }
   for (auto const & x : vec) {
     std::cout << x->name << ' ';
   }
}

int main() {
  test_local();
  test_dynamic();
  test_optimized_small();
  test_optimized_large();
}
