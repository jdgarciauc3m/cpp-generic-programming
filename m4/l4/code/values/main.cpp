#include <iostream>
#include <vector>

template <typename T>
class list {
public:

  template <typename T1, typename ... U>
  explicit list(T1 x, U ... u) : values_{x,u...} {}

  friend std::ostream & operator<<(std::ostream & os, list const & lst) {
    if (lst.values_.size() == 0) return os << "[]\n";
    os << "[ " << lst.values_[0];
    for (auto i=lst.values_.begin()+1; i!=lst.values_.end(); ++i) {
      std::cout << ", " << *i;
    }
    return std::cout << " ]";
  }

private:
  std::vector<T> values_;
};

template <typename T, typename ... U>
//requires (std::convertible_to<T,U> && ...)
list(T,U...) -> list<std::common_type_t<T,U...>>;

int main() {
  list v1{1, 2L, 3};
  std::cout << v1 << '\n';

  list v2{1.5f, 2.0, 3.5};
  std::cout << v2 << '\n';

  list v3{1,2,3};
  //list v{2LL, 2, 3L};
}
