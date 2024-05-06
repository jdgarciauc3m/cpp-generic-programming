#include <bit>
#include <cstdint>
#include <cstring>
#include <format>
#include <iostream>
#include <iterator>

template <typename T, std::size_t N>
struct array_size {
    using type = T[N]; // NOLINT
    static constexpr std::size_t size = sizeof(type);
};

template <typename T>
struct buffer_type {
    using type = std::byte[sizeof(T)]; // NOLINT
};

template <typename T>
using buffer_type_t = typename buffer_type<T>::type;

template <typename T>
struct elements {
    static constexpr int value = 1;
};

template <typename T, std::size_t N>
struct elements<T[N]> { // NOLINT
    static constexpr int value = N;
};

template <typename T>
static constexpr inline int elements_v = elements<T>::value;

template <typename T>
struct elements2 : public std::integral_constant<int, 1> {};

template <typename T, std::size_t N>
struct elements2<T[N]> : public std::integral_constant<int,N> {}; // NOLINT

template <typename T>
static constexpr inline int elements2_v = elements2<T>::value;

template <typename T>
void print_as_buffer(T value) {
  typename buffer_type<T>::type buffer;
  std::memcpy(&buffer, &value, sizeof(T));
  for (auto b : buffer) {
    std::cout << static_cast<int>(b) << ' ';
  }
  std::cout << '\n';
}

template <typename T>
void print_as_buffer2(T value) {
  buffer_type_t<T> buffer;
  std::memcpy(&buffer, &value, sizeof(T));
  for (auto b : buffer) {
    std::cout << static_cast<int>(b) << ' ';
  }
  std::cout << '\n';
}

void test1() {
  std::cout << std::format("*** {} ***\n", __PRETTY_FUNCTION__ );
  std::cout << array_size<int, 4>::size << '\n';
  std::cout << sizeof(std::string)*4 << '\n';
  std::cout << array_size<std::string, 4>::size << '\n';
}

void test2() {
  std::cout << std::format("*** {} ***\n", __PRETTY_FUNCTION__ );
  using max_type = std::integral_constant<int,100>; // NOLINT
  max_type max;
  static_assert(std::is_same_v<int, max_type::value_type>);
  static_assert(std::is_same_v<max_type, max_type::type>);
  std::cout << std::format("max value {}\n", max_type::value);
  std::cout << std::format("max value {}\n", static_cast<int>(max));
  std::cout << std::format("max value {}\n", max());
  std::cout << std::format("max value {}\n", static_cast<int>(max_type{}));
  std::cout << std::format("max value {}\n", max_type{}());
}

void test3() {
  std::cout << std::format("*** {} ***\n", __PRETTY_FUNCTION__ );
  int value = 42;  // NOLINT
  print_as_buffer(value);
  print_as_buffer2(value);
}

void test4() {
  std::cout << std::format("*** {} ***\n", __PRETTY_FUNCTION__ );
  std::cout << std::format("int -> {}\n",elements<int>::value);
  std::cout << std::format("int[4] -> {}\n",elements<int[4]>::value); // NOLINT

  std::cout << std::format("int -> {}\n",elements_v<int>);
  std::cout << std::format("int[4] -> {}\n",elements_v<int[4]>); // NOLINT

  std::cout << std::format("int -> {}\n",elements2<int>::value);
  std::cout << std::format("int[4] -> {}\n",elements2<int[4]>::value); // NOLINT

  std::cout << std::format("int -> {}\n",elements2_v<int>);
  std::cout << std::format("int[4] -> {}\n",elements2_v<int[4]>); // NOLINT
}

static constexpr inline int size_limit = 128;

template <typename T>
struct is_large_type : public std::bool_constant<(sizeof(T) > size_limit)> {};

template <typename T>
static constexpr inline bool is_large_type_v = is_large_type<T>::value;

void test5() {
  std::cout << std::format("*** {} ***\n", __PRETTY_FUNCTION__ );
  std::cout << std::format("int -> {}\n",is_large_type<int>::value);
  std::cout << std::format("int[100] -> {}\n",is_large_type<int[100]>::value); // NOLINT
  std::cout << std::format("int -> {}\n",is_large_type_v<int>);
  std::cout << std::format("int[100] -> {}\n",is_large_type_v<int[100]>); // NOLINT
}

int main() {
  test1();
  test2();
  test3();
  test4();
  test5();
}
