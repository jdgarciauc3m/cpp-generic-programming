#include <iostream>
#include <fstream>
#include <cstdint>
#include <format>

class file_logger {
public:
  file_logger(std::string const & name) : file_{name} {}

  void log(std::string_view message) {
    file_ << message << '\n';
  }

private:
  std::ofstream file_;
};

enum class log_level : std::uint8_t { info, warn, error, fatal };
std::string to_string(log_level level) {
  using enum log_level;
  switch (level) {
    case info: return "info";
    case warn: return "warn";
    case error: return "error";
    case fatal: return "fatal";
    default: return "unknown";
  }
}

class level_file_logger {
public:
  level_file_logger(std::string const & name) : file_{name} {}

  void log(std::string_view message) {
    file_ << message << '\n';
  }

  void log(log_level level, std::string_view message) {
    file_ << std::format("{}: {}\n", to_string(level), message);
  }
private:
  std::ofstream file_;
};

template <typename L>
concept basic_logger = requires(L l){
  l.log("");
};

template <typename L>
concept extended_logger = requires(L l) {
  l.log("");
  l.log(log_level{}, "");
};

void print_warning(basic_logger auto & l, std::string_view message)
{
  l.log(message);
}

void print_warning(extended_logger auto & l, std::string_view message)
{
  l.log(log_level::warn, "Start of warning");
  l.log(message);
  l.log(log_level::warn, "End of warning");
}


void f() {
  file_logger log_file{"log.txt"};
  print_warning(log_file, "Running");
  print_warning(log_file, "Stopping");

  level_file_logger level_file{"level.txt"};
  print_warning(level_file, "Running");
  print_warning(level_file, "Stopping");
}

int main() {
  f();
}

