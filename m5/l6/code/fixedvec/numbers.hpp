#ifndef NUMBERS_LIBRARY_HPP
#define NUMBERS_LIBRARY_HPP

#include "fixed_vector.hpp"

template <typename T>
T compute(fixed_vector<T> const & vec) {
  T res{};
  for (std::size_t i=0; i<vec.size(); ++i) {
    res += vec[i];
  }
  return res;
}

#endif //NUMBERS_LIBRARY_HPP
