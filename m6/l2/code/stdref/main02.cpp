#include <format>
#include <iostream>

void update(int & x) {
  ++x;
}

void print(int x) {
  std::cout << std::format("print: {}\n", x);
}

template <typename F, typename T>
class invocation {
  public:
    invocation(F fun, T value) : fun_{fun}, value_{value} { }

    void call() { fun_(value_); }

  private:
    F fun_;
    T value_;
};

template <typename F, typename T>
class invocation_ref {
  public:
    invocation_ref(F fun, T & value) : fun_{fun}, value_{value} { }

    void call() { fun_(value_); }

  private:
    F fun_;
    T & value_;  // NOLINT
};

template <typename F, typename T>
class invocation_rval {
  public:
    template <typename U>
      requires(std::is_reference_v<U>)
    invocation_rval(F fun, U && value) : fun_{fun}, value_{std::forward<U>(value)} { }

    invocation_rval(F fun, T && value) : fun_{fun}, tmp_{std::move(value)}, value_{tmp_} { }

    void call() { fun_(value_.get()); }

  private:
    F fun_;
    T tmp_{};
    std::reference_wrapper<T> value_;
};

template <typename F, typename T>
invocation_rval(F, T) -> invocation_rval<F, T>;

void test1() {
  int val = 42;  // NOLINT
  invocation f{update, val};
  f.call();
  std::cout << std::format("val = {}\n", val);

  invocation g{print, val};
  g.call();
}

void test2() {
  int val = 42;  // NOLINT
  invocation_ref f{update, val};
  f.call();
  std::cout << std::format("val = {}\n", val);

  invocation_ref g{print, val};
  g.call();

  // invocation_ref h{print, val+1};
  // h.call();
}

void test3() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  int val = 42;  // NOLINT
  invocation_rval f{update, val};
  f.call();
  std::cout << std::format("val = {}\n", val);

  invocation_rval g{print, val};
  g.call();

  invocation_rval h{print, val + 1};
  h.call();
}

int main() {
  test1();
  test2();
  test3();
}
