#ifndef FIXEDVEC_FIXED_VECTOR_HPP
#define FIXEDVEC_FIXED_VECTOR_HPP

#include <memory>
#include <gsl/gsl>

template<std::semiregular T>
class allocated_storage {
public:
  explicit allocated_storage(int n) : capacity_{n}, buffer_{std::make_unique<T[]>(gsl::narrow<std::size_t>(n))} {
    Expects(n > 0);
  }

  [[nodiscard]] int capacity() const { return capacity_; }

  T operator[](int i) const {
    auto idx = gsl::narrow<std::size_t>(i);
    Expects(idx < capacity_);
    return buffer_[idx];
  }

  T &operator[](int i) {
    auto idx = gsl::narrow<std::size_t>(i);
    Expects(idx < capacity_);
    return buffer_[idx];
  }

private:
  int capacity_;
  std::unique_ptr<T[]> buffer_;
};

template<std::semiregular T, std::size_t max_size = 32>
class local_storage {
public:
  local_storage() : buffer_{} {}

  [[nodiscard]] int capacity() const { return max_size; }

  T operator[](int i) const {
    auto idx = gsl::narrow<std::size_t>(i);
    Expects(idx < max_size);
    return buffer_[idx];
  }

  T &operator[](int i) {
    auto idx = gsl::narrow<std::size_t>(i);
    Expects(idx < max_size);
    return buffer_[idx];
  }

private:
  T buffer_[max_size];
};

template<std::semiregular T = double, typename S = local_storage<T,32>>
class fixed_vector {
public:
  explicit fixed_vector(int n) : storage_{n} {}

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

template<std::semiregular T, std::size_t max_size>
class fixed_vector<T, local_storage<T,max_size>> {
public:
  explicit fixed_vector(int n) {
    Expects(n>=0 and n<storage_.capacity());
  }

  T operator[](int i) const { return storage_[i]; }

  T &operator[](int i) { return storage_[i]; }

  [[nodiscard]] int capacity() const { return storage_.capacity(); }

  [[nodiscard]] int size() const { return size_; }

  void push_back(T x) {
    Expects(size() < capacity());
    storage_[size_++] = x;
  }

  friend std::ostream &operator<<(std::ostream &os, fixed_vector const &v) {
    os << "fixed_vector specialized for local storage:\n";
    os << "  current size: " << v.size_ << '\n';
    os << "  max size: " << max_size << '\n';
    if (v.size_ <= 0) { return os; }
    os << v.storage_[0];
    for (int i = 1; i < v.size_; ++i) {
      os << " , " << v.storage_[i];
    }
    return os;
  }

private:
  int size_ = 0;
  local_storage<T,max_size> storage_;
};

#endif //FIXEDVEC_FIXED_VECTOR_HPP
