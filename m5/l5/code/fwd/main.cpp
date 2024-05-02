#include <format>
#include <iostream>

class value {
  public:
    explicit value(int init) : x{init} { std::cout << "init\n"; }

    value(value const & other) : x{other.x} { std::cout << "copy cons\n"; }

    value(value && other) noexcept : x{other.x} { std::cout << "move cons\n"; }

    value & operator=(value const & other) {
      if (this != &other) { x = other.x; }
      std::cout << "copy assignment\n";
      return *this;
    }

    value & operator=(value && other) noexcept {
      if (this != &other) { x = other.x; }
      std::cout << "copy assignment\n";
      return *this;
    }

    ~value() { std::cout << "destructor\n"; }

    [[nodiscard]] int get() const { return x; }

    void print() const { std::cout << std::format("value {}\n", x); }

  private:
    int x = 0;
};

void print(value & x) {
  std::cout << std::format("print({}) by ref\n", x.get());
}

void print(value const & x) {
  std::cout << std::format("print({}) by const ref\n", x.get());
}

void print(value && x) { // NOLINT
  std::cout << std::format("print({}) by r-value ref\n", x.get());
}

void log_value(value & x) {
  std::cout << "log: ";
  print(x);
}

void log_value(value const & x) {
  std::cout << "log: ";
  print(x);
}

void log_value(value && x) {
  std::cout << "log: ";
  print(std::move(x));
}


void test1() {
  std::cout << "*** test1() ***\n";
  constexpr int init = 42;
  value val{init};
  print(val);
  value const cval{init};
  print(cval);
  print(value{init});
}

void test2() {
  std::cout << "*** test2() ***\n";
  constexpr int init = 42;
  value val{init};
  log_value(val);
  value const cval{init};
  log_value(cval);
  log_value(value{init});
}

template <typename T>
void log_val(T && x) { // NOLINT
  std::cout << "log: ";
  print(std::forward<T>(x));
}

void test3() {
  std::cout << "*** test2() ***\n";
  constexpr int init = 42;
  value val{init};
  log_val(val);
  value const cval{init};
  log_val(cval);
  log_val(value{init});
}

int main() {
  test1();
  test2();
  test3();
}
