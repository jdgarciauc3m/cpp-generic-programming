#include <format>
#include <iostream>

template <char const * prefix>
void print_message(std::string_view message) {
  std::cout << std::format("{}: {}\n", prefix, message); // NOLINT
}

char const info[] = "INFO"; // NOLINT

void f1() {
  print_message<info>("Start");

  static char const warn[] = "WARN"; // NOLINT
  print_message<warn>("No linkage");

  //char const error[] = "ERROR"; // NOLINT
  //print_message<error>("local");

  //print_message<"ERROR">("Literal")
}

int main() {
  f1();
}