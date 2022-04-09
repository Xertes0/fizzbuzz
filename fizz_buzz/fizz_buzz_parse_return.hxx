#pragma once

#include <algorithm>
#include <optional>
#include <string_view>

namespace fizzbuzz
{

template<class Return>
class basic_fizz_buzz_parse_return
{
public:
  using return_t = Return;
  using nullopt_t = std::nullopt_t;

  [[nodiscard]]
  explicit
  constexpr
  basic_fizz_buzz_parse_return(std::nullopt_t = std::nullopt) noexcept :
    value_{std::nullopt} {}

  [[nodiscard]]
  explicit
  constexpr
  basic_fizz_buzz_parse_return(return_t ret) noexcept :
    value_{std::move(ret)} {}

  [[nodiscard]]
  constexpr
  bool
  hit() const noexcept
  {
    return value_.has_value();
  }

  [[nodiscard]]
  constexpr
  return_t const&
  get() const noexcept
  {
    return value_.value();
  }

private:
  std::optional<Return> value_;
};

using fizz_buzz_parse_return = basic_fizz_buzz_parse_return<std::string_view>;

} // namespace fizzbuzz
