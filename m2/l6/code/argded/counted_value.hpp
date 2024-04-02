#ifndef ARGDED_COUNTED_VALUE_HPP
#define ARGDED_COUNTED_VALUE_HPP

#include <concepts>

template <std::semiregular T>
class counted_value {
public:
  explicit counted_value(T x) : value_{x} {}

  T operator*() { count_++; return value_; }

  counted_value<T> & operator=(T x) {
    value_ = x;
    return *this;
  }

  [[nodiscard]] int count() { return count_; }

private:
  T value_;
  int count_ = 0;
};

#endif //ARGDED_COUNTED_VALUE_HPP
