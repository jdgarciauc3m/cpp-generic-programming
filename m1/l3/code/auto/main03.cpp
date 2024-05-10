#include <iostream>

int f();

void test1() {
  //X x1 = f();
  auto x1 = f(); // X x1

  //X & x2 = f(); // Error. Cannot bind reference to temporal.
  //auto & x2 = f(); // Error. Cannot bind reference to temporal.

  auto && x3 = f();
}

int & g();

void test2() {
  //X x3 = g();
  auto x3 = g(); // X x3

  //X & x4 = g();
  auto & x4 = g(); // X & x4

  auto && x5 = g();
}
