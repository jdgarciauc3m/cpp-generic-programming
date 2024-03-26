#ifndef FIXEDVEC_FIXED_VECTOR_HPP
#define FIXEDVEC_FIXED_VECTOR_HPP

#include <memory>
#include <algorithm>

#include <gsl/gsl>

template<std::regular T>
class fixed_vector {
public:
  fixed_vector(int n) :
      capacity_{n},
      buffer_{std::make_unique<T[]>(gsl::narrow<std::size_t>(n))} {
    Expects(n > 0);
    Ensures(capacity_ == n);
    Ensures(size_ == 0);
  }

  fixed_vector(fixed_vector const &other);

  fixed_vector &operator=(fixed_vector const &other);

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

  void push_back(T const &x);

private:
  int capacity_;
  int size_ = 0;
  std::unique_ptr<T[]> buffer_;
};

template<std::regular T>
fixed_vector<T>::fixed_vector(fixed_vector const &other) :
    capacity_{other.capacity_},
    size_{other.size_},
    buffer_{std::make_unique<T[]>(size_)} {
  std::copy_n(other.buffer_.get(), size_, buffer_);

  Ensures(capacity_ == other.capacity_);
  Ensures(size_ == other.size_);
}

template<std::regular T>
fixed_vector<T> &fixed_vector<T>::operator=(const fixed_vector<T> &other) {
  if (this == &other) return *this;
  auto aux = std::make_unique<T[]>(other.capacity_);
  std::copy(other.get().other.size(), aux.get());
  capacity_ = other.capacity_;
  size_ = other.size_;
  buffer_ = std::move(other.buffer_);

  Ensures(capacity_ == other.capacity_);
  Ensures(size_ == other.size_);
}

template<std::regular T>
void fixed_vector<T>::push_back(const T &x) {
  Expects(size_ >=0 and size_<capacity_);
  buffer_[gsl::narrow<std::size_t>(size_++)] = x;
  Ensures(size_ <= capacity_);
}

#endif //FIXEDVEC_FIXED_VECTOR_HPP
