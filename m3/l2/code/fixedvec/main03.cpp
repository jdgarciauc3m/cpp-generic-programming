#include <iostream>
#include <format>
#include <memory>

template<typename T>
concept primitive_pointer1 =requires(T ptr) {
  std::is_pointer_v<T>;
};

template<typename T>
concept primitive_pointer2 = requires(T ptr) {
  requires std::is_pointer_v<T>;
};

template<typename T>
concept smart_pointer = requires(T ptr) {
  typename T::pointer;
  typename T::element_type;
  typename T::deleter_type;
  *ptr;
  requires std::same_as<std::remove_reference_t<decltype(*ptr)>,
      typename T::element_type>;
  { ptr.operator->() } noexcept -> std::same_as<typename T::pointer>;
  { static_cast<bool>(ptr) } noexcept -> std::same_as<bool>;
};

template<smart_pointer P>
void test(P &ptr) {
  std::cout << "value " << *ptr << '\n';
}

template<primitive_pointer1 P>
void testp1(P &ptr) {
  std::cout << "Primitive1 " << *ptr << '\n';
}

template<primitive_pointer2 P>
void testp2(P &ptr) {
  std::cout << "Primitive2 " << *ptr << '\n';
}


struct point {
  int x, y;
};

std::ostream &operator<<(std::ostream &out, point const &pos) {
  return out << pos.x << " , " << pos.y;
}

void f() {
  auto var = std::make_unique<point>(42, 35); // NOLINT
  test(var);
}

void g() {
  int x = 42; // NOLINT
  auto *ptr = &x;
  testp1(ptr);
  testp1(x);
  testp2(ptr);
}

int main() {
  f();
  g();
}

