#ifndef FIXEDVEC_STORAGE_FIXED_VECTOR_HPP
#define FIXEDVEC_STORAGE_FIXED_VECTOR_HPP

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
    Expects(i >= 0 and i < capacity_);
    return buffer_[gsl::narrow<std::size_t>(i)];
  }

  T &operator[](int i) {
    Expects(i >= 0 and i < capacity_);
    return buffer_[gsl::narrow<std::size_t>(i)];
  }

private:
  int capacity_;
  std::unique_ptr<T[]> buffer_;
};

template<std::semiregular T>
class local_storage {
public:
  local_storage() = default;

  [[nodiscard]] int capacity() const { return max_size; }

  T operator[](int i) const {
    Expects(i >= 0 and i < max_size);
    return buffer_[gsl::narrow<std::size_t>(i)];
  }

  T &operator[](int i) {
    Expects(i >= 0 and i < max_size);
    return buffer_[gsl::narrow<std::size_t>(i)];
  }

private:
  static constexpr int max_size = 32;
  std::array<T, max_size> buffer_;
};

template<std::semiregular T, typename S>
class fixed_vector {
public:
  explicit fixed_vector(int n) : storage_{n} {}

  T operator[](int i) const { return storage_[i]; }

  T &operator[](int i) { return storage_[i]; }

  [[nodiscard]] int capacity() const { return storage_.capacity(); }

  [[nodiscard]] int size() const { return size_; }

  void push_back(T x);

  template <std::semiregular T2, typename S2>
  friend std::ostream &operator<<(std::ostream &os, fixed_vector<T2,S2> const &v);

private:
  int size_ = 0;
  S storage_;
};

template <std::semiregular T, typename S>
void fixed_vector<T,S>::push_back(T x) {
  Expects(size() < capacity());
  storage_[size_++] = x;
}

template <std::semiregular T, typename S>
std::ostream &operator<<(std::ostream &os, fixed_vector<T,S> const &v) {
  if (v.size_ <= 0) { return os; }
  os << v.storage_[0];
  for (int i = 1; i < v.size_; ++i) {
    os << " , " << v.storage_[i];
  }
  return os;
}


template<std::semiregular T>
class fixed_vector<T, local_storage<T>> {
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
    os << "fixed_vector specialized for local storage: ";
    if (v.size_ <= 0) { return os; }
    os << v.storage_[0];
    for (int i = 1; i < v.size_; ++i) {
      os << " , " << v.storage_[i];
    }
    return os;
  }

private:
  int size_ = 0;
  local_storage<T> storage_;
};

#endif //FIXEDVEC_STORAGE_FIXED_VECTOR_HPP
