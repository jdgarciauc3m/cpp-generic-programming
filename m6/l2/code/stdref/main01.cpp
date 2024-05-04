#include <iostream>
#include <format>

void update(int &x) {
  ++x;
}

void print(int x) {
  std::cout << std::format("print: {}\n", x);
}

template<typename F, typename T>
void call(F fun, T arg) {
  std::cout << "log: Calling function\n";
  fun(arg);
  std::cout << "log: Function executed\n";
}

template<typename F, typename T>
void  callref(F fun, T & arg) {
  std::cout << "log: Calling function\n";
  fun(arg);
  std::cout << "log: Function executed\n";
}

template<typename F, typename T>
void callrval(F fun, T && arg) {
  std::cout << "log: Calling function\n";
  fun(std::forward<T>(arg));
  std::cout << "log: Function executed\n";
}


void test1() {
  std::cout << __func__ << '\n';
  int val = 42; // NOLINT
  call(update, val);
  std::cout << std::format("val = {}\n", val);
}

void test2() {
  std::cout << __func__ << '\n';
  int val = 42; // NOLINT
  callref(update, val);
  std::cout << std::format("val = {}\n", val);
  callref(print, val);

  //callref(update, val+1);
  //callref(print, val+1);
}

void test3() {
  std::cout << __func__ << '\n';
  int val = 42; // NOLINT
  callrval(update, val);
  std::cout << std::format("val = {}\n", val);

//  callrval(update, val+1);
//  std::cout << std::format("val = {}\n", val);
  callrval(print, val+1);
}

void test4() {
  std::cout << __func__ << '\n';
  int val = 42; // NOLINT
  call(update, std::ref(val));
  std::cout << std::format("val = {}\n", val);
  call(print, val);

  call(print, val+1);

}

int main() {
  test1();
  test2();
  test3();
  test4();
}
