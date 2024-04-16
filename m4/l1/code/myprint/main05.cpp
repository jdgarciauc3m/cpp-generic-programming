#include <iostream>

template <typename T, typename... Args>
void my_print(std::string_view str, T first, Args... args) {
  auto pos = str.find("{}");
  std::cout << str.substr(0, pos);
  if (pos == std::string_view::npos) { throw std::invalid_argument("Extra argument"); }
  std::cout << first;
  if constexpr (sizeof...(Args) > 0) {
    my_print(str.substr(pos + 2), args...);
  } else {
    if ( str.find("{}", pos+2) != std::string_view::npos) {
      throw std::invalid_argument("Missing argument");
    }
    std::cout << str.substr(pos + 2);
  }
}

int main() try {
  my_print("Name {}. Birth year = {}. Height ={}.\n", "Daniel", 1969, 1.82);  // NOLINT
  //my_print("Name {}. Birth year = {}. Height ={}.\n", "Daniel", 1969, 1.82, 4);  // NOLINT
  my_print("Name {}. Birth year = {}. Height ={}.\n", "Daniel", 1969);  // NOLINT
} catch (std::exception & exc) { std::cerr << exc.what() << '\n'; }
