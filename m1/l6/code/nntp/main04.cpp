#include <cstdint>
#include <format>
#include <iostream>

enum class log_level : std::uint8_t {
  info,
  warn,
  error
};

template <log_level level>
consteval std::string_view to_string() {
  switch (level) {
    case log_level::info: return "info";
    case log_level::warn: return "warning!";
    case log_level::error: return "ERROR!!!";
  }
}


template <log_level level>
void log(std::string_view message) {
  std::cout << std::format("{}: {}\n", to_string<level>(), message);
}

void f1() {
  using enum log_level;
  log<info>("Starting function");
  log<warn>("Function is deprecated");
  log<error>("Stop using this function");
  log<info>("Finishing function");
}

int main() {
  f1();
}
