#include <array>
#include <iostream>
#include <format>

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)
template <typename T>
void print(T const vec[], int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << vec[i] << ' ';  // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
  }
  std::cout << '\n';
}

// NOLINTEND(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)

template <typename T, std::size_t N>
void print(std::array<T, N> const & vec) {
  for (auto x : vec) { std::cout << x << ' '; }
  std::cout << '\n';
}

template <typename T, std::size_t N, std::size_t... I>
void print_helper(std::array<T, N> const & vec,
                  [[maybe_unused]] std::index_sequence<I...> seq) {
  ((std::cout << (I==0?"":" , ") << std::get<I>(vec)),...);
}

template <typename T, std::size_t N>
void print2(std::array<T, N> const & vec) {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  print_helper(vec, std::make_index_sequence<N>{});
}

// NOLINTBEGIN(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)
// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
void f1() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  int vec1[5]{1, 2, 3, 4, 5};
  print(vec1, 5);  // NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)

  int vec2[]{1, 2, 3, 4, 5};
  print(vec2, 5);  // NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay)

  // int vec3[5] {vec1};
  // int vec4[5] = vec1;
  // vec3 = vec1;
}

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
// NOLINTEND(cppcoreguidelines-avoid-c-arrays,modernize-avoid-c-arrays)

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
void f2() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  std::array<int, 5> vec1{1, 2, 3, 4, 5};
  print(vec1);

  std::array vec2 = std::to_array<double>({1, 2, 3, 4, 5});
  print(vec2);

  std::array vec3{1, 2, 3, 4, 5};
  print(vec3);

  std::array vec4{vec1};
  print(vec4);
  std::get<2>(vec3) = 99;
  vec4              = vec3;
  print2(vec4);
}



void f3() {
  std::cout << __PRETTY_FUNCTION__ << '\n';
  std::array vec{1, 2, 3, 4, 5};
  auto sz1 = vec.size();
  std::cout << std::format("sz1 = {}\n", sz1);
  constexpr auto sz2 = vec.size();
  std::cout << std::format("sz2 = {}\n", sz2);
  auto & vec2 = vec;
  auto sz3 = vec2.size();
  //constexpr auto sz4 = vec2.size();
  constexpr auto sz = std::tuple_size_v<std::decay_t<decltype(vec2)>>;
  using basetype = std::tuple_element_t<0,decltype(vec)>;
  basetype value = vec[0];
  std::cout << std::format("vec[0] = {}\n",value);
  std::array<std::string, sz> names;
  for(std::size_t i=0; auto x : vec) {
    names[i++] = std::to_string(x); // NOLINT
  }
  for (auto const &s : names) {
    std::cout << s << '\n';
  }
}

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)


int main() {
  f1();
  f2();
  f3();
}
