#pragma once

#include <algorithm>
#include <optional>
#include <vector>

namespace fizzbuzz
{

template<class Inner>
class basic_return_value
{
public:
  using inner_t = Inner;

  [[nodiscard]]
  explicit
  constexpr
  basic_return_value(std::nullopt_t = std::nullopt) noexcept :
    value_{std::nullopt} {}

  [[nodiscard]]
  explicit
  constexpr
  basic_return_value(std::vector<inner_t> val) noexcept :
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
  std::vector<inner_t> const&
  get() noexcept
  {
    return value_.value();
  }

private:
  std::optional<std::vector<inner_t>> const value_;
};

using return_value = basic_return_value<std::string_view>;

} // namespace fizzbuzz
