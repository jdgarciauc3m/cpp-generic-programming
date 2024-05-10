#ifndef NUMBERS_IMP_HPP
#define NUMBERS_IMP_HPP

#include "fixed_vector.hpp"

template <typename T>
T compute(fixed_vector<T> const & vec) {
  T res{};
  for (std::size_t i=0; i<vec.size(); ++i) {
    res += vec[i];
  }
  return res;
}

#endif // NUMBERS_IMP_HPP
