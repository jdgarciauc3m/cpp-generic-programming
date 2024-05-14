#include <cxxabi.h>
#include <iostream>
#include <memory>

template <class T>
std::string type_name() {
  using TR = std::remove_reference_t<T>;
  std::unique_ptr<char, void (*)(void *)> own(
      abi::__cxa_demangle(typeid(TR).name(), nullptr, nullptr, nullptr), std::free);
  std::string r = own != nullptr ? own.get() : typeid(TR).name();
  if (std::is_const_v<TR>) { r += " const"; }
  if (std::is_volatile_v<TR>) { r += " volatile"; }
  if (std::is_lvalue_reference_v<T>) {
    r += "&";
  } else if (std::is_rvalue_reference_v<T>) {
    r += "&&";
  }
  return r;
}

template <typename T>
auto maximum1(T x, T y) {
  std::cout << "maximum1<" << type_name<T>() << ">\n";
  return x > y ? x : y;
}

template <typename T>
auto maximum2(T & x, T & y) {
  std::cout << "maximum2<" << type_name<T>() << ">\n";
  return x > y ? x : y;
}

long add(long x, long y) {
  return x + y;
}

long sub(long x, long y) {
  return x - y;
}

void f1() {
  std::cout << "=== f1() ===\n";

  int v[10]{
    1,
    2,
  };
  int w[5]{
    10,
    11,
  };
  auto r1 = maximum1(v, w);
  std::cout << "r[0] = " << r1[0] << '\n';

  auto & s = v;
  auto r2  = maximum1(v, s);
  std::cout << "r[0] = " << r2[0] << '\n';

  int const t[10]{20, 21};
  // auto r3 = maximum1(v,t);

  int * const u = v;
  auto r4       = maximum1(v, u);
  std::cout << "r[0] = " << r4[0] << '\n';
}

void f1r() {
  std::cout << "=== f1r() ===\n";
  int v[10]{
    1,
    2,
  };
  int w[10]{
    10,
    11,
  };
  int u[5]{20, 21};

  // auto r0 = maximum2(v,u); // T=int[10] or int[5]

  auto r1 = maximum2(v, w);
  // std::cout << "r[0] = " << r1[0] << '\n';

  auto & s = v;
  auto r2  = maximum2(v, s);
  std::cout << "r[0] = " << r2[0] << '\n';

  int const t[10]{20, 21};
  // auto r3 = maximum1(v,t);

  // int * const u = v;
  // auto r4 = maximum2(v,u); // T=int[10] or int* const
  // std::cout << "r[0] = " << r4[0] << '\n';
}

void f2() {
  std::cout << "=== f2() ===\n";

  auto r1 = maximum1(add, sub);
  std::cout << r1 << '\n';

  auto & fun1 = add;
  auto * fun2 = add;
  auto r2     = maximum1(fun1, fun2);
}

void f2r() {
  std::cout << "=== f2r() ===\n";

  auto r1 = maximum2(add, sub);
  std::cout << r1 << '\n';

  auto & fun1 = add;
  auto * fun2 = sub;
  // auto r2 = maximum2(fun1, fun2); // function ref and pointer to function ref
}

void f3() {
  std::cout << "=== f3() ===\n";

  int x = 5; // NOLINT
  int y = 8; // NOLINT

  int & rx = x;
  auto r1  = maximum1(rx, y);
  std::cout << "r = " << r1 << '\n';

  int && rrz = x + y;
  auto r2    = maximum1(x, rrz);
  std::cout << "r = " << r2 << '\n';

  int volatile vx = x;
  int const cy    = y;
  auto r3         = maximum1(x, cy);
  std::cout << "r = " << r3 << '\n';

  int const & rcx = x;
  auto r4         = maximum1(rcx, y);
  std::cout << "r = " << r4 << '\n';

  int const && rrx = (x + y);
  auto r5          = maximum1(x, rrx);
  std::cout << "r = " << r5 << '\n';
}

void f3r() {
  std::cout << "=== f3r() ===\n";

  int x   = 5;
  int y   = 8;
  auto r0 = maximum2(x, y);
  std::cout << "r = " << r0 << '\n';

  int & rx = x;
  auto r1  = maximum2(rx, y);
  std::cout << "r = " << r1 << '\n';

  int && rrz = x + y;
  auto r2    = maximum2(x, rrz);
  std::cout << "r = " << r2 << '\n';

  int volatile vx = x;
  int const cy    = y;
  // auto r3 = maximum2(x, cy);
  // std::cout << "r = " << r3 << '\n';

  int const & rcx = x;
  // auto r4 = maximum2(rcx,y);
  // std::cout << "r = " << r4 << '\n';

  int const && rrx = (x + y);
  // auto r5 = maximum2(x, rrx);
  // std::cout << "r = " << r5 << '\n';
}

int main() {
  f1();
  f2();
  f3();
  f1r();
  f2r();
  f3r();
}
