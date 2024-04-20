#ifndef RECORD_RECORD3_HPP
#define RECORD_RECORD3_HPP

#include <iostream>

template<typename ... T>
class record;

template<>
class record<> {
};

template<typename T, typename ... U>
class record<T, U...> {
public:
  record() = default;

  // NOLINTBEGIN(modernize-pass-by-value)
  record(T const &first, U const &... rest) :
      first_{first}, rest_{rest...} {}
  // NOLINTEND(modernize-pass-by-value)

  [[nodiscard]] T const &first() const { return first_; }

  [[nodiscard]] record<U...> const &rest() const { return rest_; }

  void print() const;

private:
  T first_;
  record<U...> rest_;
};

template<typename T, typename ... U>
void record<T, U...>::print() const {
  std::cout << first_;
  if constexpr (sizeof...(U) > 0) {
    std::cout << " , ";
    rest_.print();
  } else {
    std::cout << '\n';
  }
}

template<int I, typename ... T>
auto myget(record<T...> const &rec) {
  if constexpr (I > 0) {
    return myget<I - 1>(rec.rest());
  } else {
    return rec.first();
  }
}

#endif //RECORD_RECORD3_HPP
