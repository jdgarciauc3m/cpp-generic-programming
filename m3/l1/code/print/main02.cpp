#include <iostream>
#include <string>
#include <memory>

template<typename T>
concept pointer = requires(T ptr) {
  *ptr;
  { ptr == ptr } -> std::same_as<bool>;
  { ptr != ptr } -> std::same_as<bool>;
  { ptr == nullptr } -> std::same_as<bool>;
  { ptr != nullptr } -> std::same_as<bool>;
};

void print(pointer auto const &ptr) {
  std::cout << "Pointer: " << ptr << ". ";
  if (ptr == nullptr) {
    std::cout << "Value: null\n";
  }
  else {
    std::cout << "Value: " << *ptr << '\n';
  }
}

void f1() {
  std::cout << "*** f1() ***\n";
  int x = 42; // NOLINT
  print(&x);

  auto ptr = std::make_unique<std::string>("Hello");
  print(ptr);

  std::unique_ptr<std::string> empty;
  print(empty);
}

int main() {
  f1();
}

