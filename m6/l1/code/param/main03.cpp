#include <algorithm>
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

    product operator++() { id_++; return *this; }

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

template <typename T>
void update(T & x) {
  ++x;
}

template <std::ranges::range R>
void update(R & rng) {
  std::ranges::transform(rng, std::begin(rng), [](auto x) { return ++x; });
}


void test1() {
  // update(42); // NOLINT
  int id = 42; // NOLINT
  update(id);
  //int const id2 = id+1;
  //update(id2);

  {
    product prod{id, "book"};
    update(prod);
    //update(std::move(prod)); // NOLINT
  }
  //{ update(make_default_product()); }
  //{ update(product{id, "book"}); }
  int v[]{1, 2, 3};  // NOLINT
  update(v);      // NOLINT
  //int const v2[]{4,5, 6}; // NOLINT
  //update(v2);
  std::span s{v};
  update(s);
  std::array w{1, 2, 3};
  update(w);
  //update(std::array{1, 2, 3});
  //update("C++");
  //update(std::span("C++"));
  //update(std::string_view{"C++"});

}

int main() {
  test1();
}


