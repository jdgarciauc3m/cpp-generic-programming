#ifndef RECORD_RECORD1_HPP
#define RECORD_RECORD1_HPP

#include <iostream>

template<typename ... T>
class record;

template <>
class record<> {};

template <typename T, typename ... U>
class record<T,U...> {
public:
  record() = default;

  // NOLINTBEGIN(modernize-pass-by-value)
  record(T const & first, U const & ... rest) :
      first_{first}, rest_{rest...} {}
  // NOLINTEND(modernize-pass-by-value)

  [[nodiscard]] T const & first() const { return first_; }
  [[nodiscard]] record<U...> const & rest() const { return rest_; }

  void print() const;

private:
  T first_{};
  record<U...> rest_{};
};

template <typename T, typename ... U>
void record<T,U...>::print() const {
  std::cout << first_;
  if constexpr(sizeof...(U) > 0) {
    std::cout << " , ";
    rest_.print();
  }
  else {
    std::cout << '\n';
  }
}

#endif //RECORD_RECORD1_HPP
