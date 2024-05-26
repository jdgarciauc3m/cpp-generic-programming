#ifndef FIXEDVEC_FIXED_VECTOR_HPP
#define FIXEDVEC_FIXED_VECTOR_HPP

#include <algorithm>
#include <gsl/gsl>
#include <memory>

template <typename T, typename OS>
concept streamable_to = requires( T const & x, OS & os) {
  { os << x } -> std::same_as<OS &>;
};

// NOLINTBEGIN(cppcoreguidelines-pro-bounds-constant-array-index)

template <std::semiregular T, int N>
  requires(N > 0)
class fixed_vector {
  public:
    template <std::semiregular U, int M> requires (M>0)
    friend class fixed_vector;

    fixed_vector() = default;

    template <std::semiregular U, int M>
      requires(M > 0 and std::convertible_to<U, T>)
    fixed_vector(fixed_vector<U, M> const & other) : size_{other.size_} {
      Expects(other.size_ <= N);
      std::ranges::copy_n(other.buffer_.begin(), other.size_, buffer_.begin());
    }

    template <std::semiregular U, int M>
      requires(M > 0 and std::convertible_to<U, T>)
    fixed_vector<T, N> & operator=(fixed_vector<U, M> const & other) {
      Expects(other.size_ <= N);
      if constexpr (std::is_same_v<T, U> and M == N) {
        if (this == &other) { return *this; }
      }
      size_ = other.size_;
      std::ranges::copy_n(other.buffer_.begin(), other.size_, buffer_.begin());
      return *this;
    }

    T operator[](int i) const { return buffer_[i]; }

    T & operator[](int i) { return buffer_[i]; }

    [[nodiscard]] int size() const { return size_; }

    void push_back(T x) {
      Expects(size() < N);
      buffer_[gsl::narrow<unsigned>(size_++)] = x;
    }

    template <typename OS>
      requires streamable_to<T, OS>
    void print(OS & os) const;

  private:
    int size_ = 0;
    std::array<T, static_cast<std::size_t>(N)> buffer_{};
};

template <std::semiregular T, int N>
  requires(N > 0)
template <typename OS>
  requires streamable_to<T, OS>
void fixed_vector<T, N>::print(OS & os) const {
  if (size_ <= 0) { return; }
  os << buffer_[0];
  for (int i = 1; i < size_; ++i) { os << " , " << buffer_[gsl::narrow<std::size_t>(i)]; }
}

// NOLINTEND(cppcoreguidelines-pro-bounds-constant-array-index)

#endif  // FIXEDVEC_FIXED_VECTOR_HPP
