#include <iostream>
#include <memory>
#include <gsl/gsl>
#include <format>

template <typename T>
struct size_printer {
  static void print() {
    std::cout << std::format("{}\n", sizeof(T));
  }
};

template <typename C>
concept container = requires {
  typename size_printer<C>;
};

template <container C>
void f([[maybe_unused]] C cont) {
  size_printer<C>::print();
}

void g() {
  long var = 3;
  f(var);
}


template<std::semiregular T>
class allocated_storage {
public:
  using element_type = T;

  explicit allocated_storage(int n) :
      capacity_{n},
      buffer_{std::make_unique<T[]>(gsl::narrow<std::size_t>(n))} // NOLINT
  {
    Expects(n > 0);
  }

  [[nodiscard]] int capacity() const { return capacity_; }

  T operator[](int i) const {
    auto idx = gsl::narrow<std::size_t>(i);
    Expects(idx < capacity_);
    return buffer_[idx]; // NOLINT
  }

  T &operator[](int i) {
    auto idx = gsl::narrow<std::size_t>(i);
    Expects(idx < capacity_);
    return buffer_[idx]; // NOLINT
  }

private:
  int capacity_;
  std::unique_ptr<T[]> buffer_; // NOLINT
};

template<std::semiregular T, std::size_t max_size> requires (max_size > 0)
class local_storage {
public:
  using element_type = T;

  local_storage() = default;

  [[nodiscard]] int capacity() const { return max_size; }

  T operator[](int i) const {
    auto idx = gsl::narrow<std::size_t>(i);
    Expects(idx < max_size);
    return buffer_[idx]; // NOLINT
  }

  T &operator[](int i) {
    auto idx = gsl::narrow<std::size_t>(i);
    Expects(idx < max_size);
    return buffer_[idx]; // NOLINT
  }

private:
  std::array<T, max_size> buffer_{};
};

template<typename S>
concept basic_storage =requires(S str) {
  typename S::element_type;
  { str.capacity() } -> std::same_as<int>;
  { str[0] } -> std::convertible_to<typename S::element_type>;
};

template<typename S>
concept sized_storage =
basic_storage<S> and requires(S str) {
  S{0};
};

template<typename S>
concept unsized_storage = basic_storage<S> and requires(S str) {
  S{};
};

template<typename S>
concept storage = sized_storage<S> or unsized_storage<S>;

template<std::semiregular T, storage S> requires (std::same_as<T, typename S::element_type>)
class fixed_vector {
public:
  fixed_vector() requires unsized_storage<S> = default;

  explicit fixed_vector(int n) requires sized_storage<S>: storage_{n} {}

  T operator[](int i) const { return storage_[i]; }

  T &operator[](int i) { return storage_[i]; }

  [[nodiscard]] int capacity() const { return storage_.capacity(); }

  [[nodiscard]] int size() const { return size_; }

  void push_back(T x) {
    Expects(size() < capacity());
    storage_[size_++] = x;
  }

  friend std::ostream &operator<<(std::ostream &os, fixed_vector const &v) {
    if (v.size_ <= 0) { return os; }
    os << v.storage_[0];
    for (int i = 1; i < v.size_; ++i) {
      os << " , " << v.storage_[i];
    }
    return os;
  }

private:
  int size_ = 0;
  S storage_;
};

void f1() {
  constexpr int vecsize = 10;
  fixed_vector<double, local_storage<double, vecsize>> values;
  values.push_back(1.5); // NOLINT
  values.push_back(2.5); // NOLINT
  std::cout << values << '\n';
}

int main() {
  try {
    g();
    f1();
  }
  catch (...) {
    std::cerr << "Unexpected exception\n";
  }
}
