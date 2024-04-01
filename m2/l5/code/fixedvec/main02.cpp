#include <iostream>

#include "fixed_vector.hpp"

//template <std::semiregular T>
//using flexible_vector = fixed_vector<T, allocated_storage<T>>;

//template <std::semiregular T>
//using flexible_vector = fixed_vector<T*, local_storage<T*>>;

template <std::semiregular T>
struct storage_trait {
  using type = allocated_storage<T>;
};

template <std::semiregular T>
struct storage_trait<T*> {
  using type = local_storage<T*>;
};

template <std::semiregular T>
using storage_trait_t = storage_trait<T>::type;

template <std::semiregular T>
using flexible_vector = fixed_vector<T, storage_trait_t<T>>;

template <std::semiregular T>
void print(flexible_vector<T> const & v) {
  std::cout << "Printing flexible vector: " << v << '\n';
}

void f1() {
  flexible_vector<int> v1{5};
  flexible_vector<int*> v2{5};
  print(v1);
  print(v2);
}

int main() {
  f1();
}

