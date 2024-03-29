#ifndef FIXEDVEC_FIXED_VECTOR2_HPP
#define FIXEDVEC_FIXED_VECTOR2_HPP

#include <memory>
#include <algorithm>

#include <gsl/gsl>

template<std::semiregular T>
class fixed_vector {
public:
  fixed_vector() = default;

  fixed_vector(int n) :
      capacity_{n},
      // NOLINTNEXTLINE
      buffer_{std::make_unique<T[]>(gsl::narrow<std::size_t>(n))} {
    Expects(n > 0);
    Ensures(capacity_ == n);
    Ensures(size_ == 0);
    Ensures(buffer_ != nullptr);
  }

  ~fixed_vector() noexcept = default;

  fixed_vector(fixed_vector const &other);

  fixed_vector &operator=(fixed_vector const &other);

  fixed_vector(fixed_vector<T> &&) noexcept = default;

  fixed_vector &operator=(fixed_vector &&) noexcept = default;

  T &operator[](int i) {
    Expects(i >= 0 and i < size_);
    return buffer_[gsl::narrow<std::size_t>(i)];
  }

  T const &operator[](int i) const {
    Expects(i >= 0 and i < size_);
    return buffer_[gsl::narrow<std::size_t>(i)];
  }

  [[nodiscard]] int size() const { return size_; }

  [[nodiscard]] int capacity() const { return capacity_; }

  template <std::semiregular U>
  friend void serialize(std::ostream &os, fixed_vector<U> const &v);

  template <std::semiregular U>
  friend std::ostream & operator<<(std::ostream & os, fixed_vector<U> const & v);

  void push_back(T const &x);

private:
  int capacity_ = 0;
  int size_ = 0;
  std::unique_ptr<T[]> buffer_{}; // NOLINT
};

template<std::semiregular T>
fixed_vector<T>::fixed_vector(fixed_vector const &other) :
    capacity_{other.capacity_},
    size_{other.size_},
    buffer_{std::make_unique<T[]>(gsl::narrow<std::size_t>(size_))} { // NOLINT
  std::copy_n(other.buffer_.get(), size_, buffer_.get());

  Ensures(capacity_ == other.capacity_);
  Ensures(size_ == other.size_);
  Ensures(buffer_ != nullptr);
}

template<std::semiregular T>
fixed_vector<T> &fixed_vector<T>::operator=(const fixed_vector &other) {
  if (this == &other) { return *this; }
  auto aux = std::make_unique<T[]>(other.capacity_); // NOLINT
  std::copy(other.get().other.size(), aux.get());
  capacity_ = other.capacity_;
  size_ = other.size_;
  buffer_ = std::move(other.buffer_);

  Ensures(capacity_ == other.capacity_);
  Ensures(size_ == other.size_);
  Ensures(buffer_ != nullptr);
}

template<std::semiregular T>
void fixed_vector<T>::push_back(const T &x) {
  Expects(size_ >= 0 and size_ < capacity_);
  buffer_[gsl::narrow<std::size_t>(size_++)] = x;
  Ensures(size_ <= capacity_);
}


template<std::semiregular U>
void serialize(std::ostream &os, fixed_vector<U> const & v) {
  if (v.size_ <= 0) { return; }
  os << v.buffer_[0];
  for (int i = 1; i < v.size_; ++i) {
    os << " , " << v.buffer_[gsl::narrow<std::size_t>(i)];
  }
}

template<std::semiregular U>
std::ostream & operator<<(std::ostream &os, fixed_vector<U> const & v) {
  if (v.size_ <= 0) { return os; }
  os << v.buffer_[0];
  for (int i = 1; i < v.size_; ++i) {
    os << " , " << v.buffer_[gsl::narrow<std::size_t>(i)];
  }
  return os;
}

#endif //FIXEDVEC_FIXED_VECTOR2_HPP
