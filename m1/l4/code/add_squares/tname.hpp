#ifndef ADD_SQUARES_TNAME_HPP
#define ADD_SQUARES_TNAME_HPP

#include <cxxabi.h>
#include <memory>

template<class T>
std::string type_name() {
  typedef typename std::remove_reference<T>::type TR;
  std::unique_ptr<char, void (*)(void *)> own
      (
          abi::__cxa_demangle(typeid(TR).name(), nullptr,
                              nullptr, nullptr),
          std::free
      );
  std::string r = own != nullptr ? own.get() : typeid(TR).name();
  if (std::is_const<TR>::value)
    r += " const";
  if (std::is_volatile<TR>::value)
    r += " volatile";
  if (std::is_lvalue_reference<T>::value)
    r += "&";
  else if (std::is_rvalue_reference<T>::value)
    r += "&&";
  return r;
}


#endif //ADD_SQUARES_TNAME_HPP
