#include <cstring>
#include <format>
#include <gsl/gsl>
#include <iostream>
#include <memory>

template <typename T>
class container {
  public:
    container(int sz)
      requires(std::is_default_constructible_v<T>)
      : size_{sz}, buffer_{std::make_unique<T[]>(gsl::narrow<std::size_t>(size_))} { }  // NOLINT

    container(container const & c)
      requires(std::is_copy_constructible_v<T>);

    container(container &&) = default;

    container & operator=(container const & c);
    container & operator=(container &&) = default;

    ~container() = default;

    [[nodiscard]] int size() const { return size_; }

  private:
    int size_;
    std::unique_ptr<T[]> buffer_;  // NOLINT
};

template <typename T>
container<T>::container(container const & c)
  requires(std::is_copy_constructible_v<T>)
  : size_{c.size_},                                                                    // NOLINT
    buffer_{std::make_unique_for_overwrite<T[]>(gsl::narrow<std::size_t>(c.size_))} {  // NOLINT
  static_assert(std::is_copy_constructible_v<T>, "Cannot copy");
  if constexpr (std::is_trivially_copyable_v<T>) {
    std::cout << "log: memcpy()\n";
    std::memcpy(buffer_.get(), c.buffer_.get(),
                gsl::narrow<std::size_t>(size_) * sizeof(T));  // Optimization
  } else {
    std::cout << "log: uninit_copy()\n";
    std::ranges::uninitialized_copy_n(c.buffer_.get(), c.size_, buffer_.get(),
                                      buffer_.get() + size_);
  }
}

template <typename T>
container<T> & container<T>::operator=(container<T> const & c) {
  if (this == &c) { return *this; }
  auto aux = std::make_unique<T[]>(c.size_);  // NOLINT
  if constexpr (std::is_trivially_copyable_v<T>) {
    std::memcpy(buffer_, c.buffer_, size_ * sizeof(T));  // Optimization
  } else {
    uninitialized_copy(c.begin(), c.end(), buffer_);  // Normal case
  }
  buffer_ = std::move(aux);
  size_   = c.size_;
}

template <typename T>
void test() {
  std::cout << std::format("{}\n", __PRETTY_FUNCTION__);
  container<T> v{20};  // NOLINT
  container w{v};      // NOLINT
  std::cout << std::format("v -> {} elements\n", v.size());
  std::cout << std::format("w -> {} elements\n", w.size());
}

struct nodef_value {
    nodef_value(int x) :val{x} {}
    int val;
};

struct nocopy_value { // NOLINT
    nocopy_value() = default;
    nocopy_value(nocopy_value const &) = delete;
    int val = 0;
};

int main() {
  test<int>();
  test<std::string>();
  //test<nodef_value>();
  //test<nocopy_value>();
}
