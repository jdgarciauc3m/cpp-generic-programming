#include <format>
#include <iostream>
#include <map>
#include <ranges>

class product {
  public:
    product(int id, std::string name) : id_{id}, name_{std::move(name)} {
      std::cout << "Init cons\n";
    }

    product(product const & other)
      : id_{other.id_}, name_{other.name_}, model_prices_{other.model_prices_} {
      std::cout << "Copy cons\n";
    }

    product(product && other) noexcept
      : id_{other.id_}, name_{std::move(other.name_)},
        model_prices_{std::move(other.model_prices_)} {
      std::cout << "Move cons\n";
    }

    ~product() { std::cout << "Destructor\n"; }

    product & operator=(product const &)     = default;
    product & operator=(product &&) noexcept = default;

    friend std::ostream & operator<<(std::ostream & out, product const & prod) {
      return out << std::format("id = {}, name = {}", prod.id_, prod.name_);
    }

  private:
    int id_;
    std::string name_;
    std::map<std::string, double> model_prices_;
};

product make_default_product() {
  return {42, "Quijote"};  // NOLINT
}

template <std::ranges::range R>
void log_value(R rng) {
  std::cout << "[ ";
  for (auto && x : rng) { std::cout << x << ", "; }
  std::cout << " ]\n";
}

template <typename T>
void log_value(T x) {
  std::cout << "log: " << x << '\n';
}

void test1() {
  constexpr int id = 42;
  log_value(id);
  {
    product prod{id, "book"};
    log_value(prod);
    log_value(std::move(prod));
  }
  { log_value(make_default_product()); }
  { log_value(product{id, "book"}); }
  int v[]{1, 2, 3};  // NOLINT
  log_value(v);      // NOLINT
  std::array w{1, 2, 3};
  log_value(w);
  log_value(std::array{1, 2, 3});
  log_value("C++");
  log_value(std::string_view{"C++"});
}

int main() {
  test1();
}
