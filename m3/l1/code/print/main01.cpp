#include <iostream>

template <typename T>
requires (not std::is_pointer_v<T>)
void print(T value) {
  std::cout << "Value: " << value << '\n';
}

template <typename T>
requires std::is_pointer_v<T>
void print(T ptr) {
  std::cout << "Pointer: " << static_cast<void*>(ptr) << ". Value: " << *ptr << '\n';
}

void print2(auto ptr)
requires std::is_pointer_v<decltype(ptr)>
{
  std::cout << "Pointer: " << static_cast<void*>(ptr) << ". Value: " << *ptr << '\n';
}

void f1() {
  std::cout << "*** f1() ***\n";
  int x = 42; // NOLINT
  print(x);
  print(&x);
  print2(&x);
}

int main() {
  f1();
}
