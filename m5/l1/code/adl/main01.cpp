#include <cstdint>
#include <format>
#include <iostream>

namespace logging {
  template <typename T>
  void log(T x) {
    std::cout << "LOG: " << x << '\n';
  }
}

namespace graphics {
  enum class color : std::int8_t { red, green, blue };
  std::string to_string(color c) {
    switch (c) {
      case color::red: return "red";
      case color::green: return "green";
      case color::blue: return "blue";
      default: return "unknown";
    }
  }
  void log(color c) {
    std::cout << std::format("COLOR: {}\n", to_string(c));
  }
}

void log(int x) {
  std::cout << std::format("INT: {}\n", x);
}

int main() {
  // Built in: No ADL
  log(42); // NOLINT

  // ADL: graphics
  log(graphics::color::red);

}
