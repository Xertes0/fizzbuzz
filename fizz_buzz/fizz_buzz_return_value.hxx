#pragma once

#include <algorithm>
#include <optional>

namespace fizzbuzz
{

template<class Inner>
class basic_fizz_buzz_return_value
{
public:
  using inner_t = Inner;

  [[nodiscard]]
  explicit
  constexpr
  basic_fizz_buzz_return_value(std::nullopt_t = std::nullopt) noexcept :
    value_{std::nullopt} {}

  [[nodiscard]]
  explicit
  constexpr
  basic_fizz_buzz_return_value(inner_t val) noexcept :
    value_{std::move(val)} {}

  [[nodiscard]]
  constexpr
  operator
  bool()
  {
    return value_.has_value();
  }

  [[nodiscard]]
  constexpr
  operator
  inner_t()
  {
    return value_.value();
  }

  [[nodiscard]]
  constexpr
  inner_t
  get_or_default() noexcept
  {
    if(value_.has_value()) {
      return value_.value();
    } else {
      return inner_t{};
    }
  }

private:
  std::optional<inner_t> const value_;
};

using fizz_buzz_return_value = basic_fizz_buzz_return_value<std::string_view>;

} // namespace fizzbuzz
