#ifndef RECORD_RECORD_HPP
#define RECORD_RECORD_HPP

template<typename ... Ts>
class record;

template<typename T, typename ... U>
class record<T, U...> {
public:
  constexpr record() = default;

  template<typename T2, typename ... U2>
  requires (sizeof...(U) == sizeof...(U2))
  explicit record(T2 &&first, U2 &&... rest) :
      first_{std::forward<T>(first)}, rest_{std::forward<U>(rest)...}  // NOLINT
  {
  }

  template<typename T2, typename ... U2>
  requires (sizeof...(U) == sizeof...(U2))
  explicit record(record<T2,U2...> const & other) :
      first_{other.first()}, rest_{other.rest()} {}

  auto &first() { return first_; }

  [[nodiscard]] auto const &first() const { return first_; }

  auto &rest() { return rest_; }

  [[nodiscard]] auto const &rest() const { return rest_; }

private:
  T first_{};
  record<U...> rest_{};
};

template<>
class record<> {
};

template<int I>
struct get_helper {
  template<typename T, typename ... U>
  static auto impl(record<T, U...> const &rec) {
    return get_helper<I - 1>::impl(rec.rest());
  }

  template<typename T, typename ... U>
  static auto &impl(record<T, U...> &rec) {
    return get_helper<I - 1>::impl(rec.rest());
  }
};

template<>
struct get_helper<0> {
  template<typename T, typename ... U>
  static T impl(record<T, U...> const &rec) {
    return rec.first();
  }

  template<typename T, typename ... U>
  static auto &impl(record<T, U...> &rec) {
    return rec.first();
  }
};

template<int I, typename ... T>
auto get(record<T...> const &rec) {
  return get_helper<I>::impl(rec);
}

template<int I, typename ... T>
auto &get(record<T...> &rec) {
  return get_helper<I>::impl(rec);
}

template <typename ... U>
auto make_record(U && ... values) {
  return record<std::decay_t<U>...>(std::forward<U>(values)...);
}

#endif //RECORD_RECORD_HPP
