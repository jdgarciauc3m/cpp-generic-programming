#include <iostream>
#include <gsl/gsl>
#include <format>

template <int value>
concept positive = value > 0;

template<std::semiregular T, int N> requires positive<N>
class fixed_vector {
public:
  fixed_vector() = default;

  [[nodiscard]] int size() const { return size_; }

  T &operator[](int i) {
    Expects(i >= 0 and i < size_);
    return buffer_[gsl::narrow<std::size_t>(i)]; // NOLINT
  }

  T operator[](int i) const requires (sizeof(T) <= 2 * sizeof(void *)) {
    Expects(i >= 0 and i < size_);
    std::cout << "value semantics\n";
    return buffer_[gsl::narrow<std::size_t>(i)]; // NOLINT
  }

  T const &operator[](int i) const requires (sizeof(T) > 2 * sizeof(void *)) {
    Expects(i >= 0 and i < size_);
    std::cout << "reference semantics\n";
    return buffer_[gsl::narrow<std::size_t>(i)]; // NOLINT
  }

  void push_back(T const &value) {
    Expects(size_ <= N);
    buffer_[gsl::narrow<std::size_t>(size_++)] = value; // NOLINT
  }

private:
  std::array<T, std::size_t(N)> buffer_{};
  int size_ = 0;
};

template<typename T, int N>
void print(fixed_vector<T, N> const &vec) {
  std::cout << "*** print *** -> ";
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << " , ";
  }
  std::cout << '\n';
}

int main() {
  fixed_vector<double, 20> numbers; // NOLINT
  numbers.push_back(1.0);
  std::cout << std::format("numbers[0] = {}\n", numbers[0]);
  print(numbers);

  fixed_vector<std::string, 10> names; // NOLINT
  names.push_back("Daniel");
  std::cout << std::format("names[0] = {}\n", names[0]);
  print(names);

}
