#ifndef FIXEDVEC_FIXED_VECTOR_IMP_HPP
#define FIXEDVEC_FIXED_VECTOR_IMP_HPP

#include <memory>
#include <iostream>
#include <gsl/gsl>

template<typename T>
class fixed_vector {
  public:
    fixed_vector(std::size_t nelems);

    void push_back(T const &x);

    T operator[](std::size_t i) const {
      Expects(i < capacity_);
      return buffer_[i];
    }

    void print(std::ostream &out) const;

    [[nodiscard]] std::size_t size() const { return size_; }

  private:
    std::unique_ptr<T[]> buffer_; // NOLINT
    std::size_t capacity_;
    std::size_t size_{0};
};

template<typename T>
fixed_vector<T>::fixed_vector(std::size_t nelems)
  : buffer_{std::make_unique_for_overwrite<T[]>(nelems)}, // NOLINT
    capacity_{nelems} {}

template<typename T>
void fixed_vector<T>::push_back(T const &x) {
  Expects(size_ < capacity_);
  buffer_[size_++] = x;
}

template<typename T>
void fixed_vector<T>::print(std::ostream &out) const {
  if (size_ == 0) {
    return;
  }
  out << buffer_[0];
  for (std::size_t i = 1; i < size_; ++i) {
    out << ", " << buffer_[i];
  }
  out << '\n';
}

#endif  // FIXEDVEC_FIXED_VECTOR_IMP_HPP
