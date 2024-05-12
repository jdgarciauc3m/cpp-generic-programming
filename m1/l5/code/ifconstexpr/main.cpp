#include <iostream>

template <typename T>
void print(T const & value) {
  if  (std::is_array_v<T>) {
    for (auto x : value) {
      std::cout << x << ' ';
    }
  }
  else {
    std::cout << value; // NOLINT
  }
  std::cout << '\n';
}

int main() {
  double vec[] {1.0, 1.5, 2.0}; // NOLINT
  print(vec);
  //print(vec[0]);
}
