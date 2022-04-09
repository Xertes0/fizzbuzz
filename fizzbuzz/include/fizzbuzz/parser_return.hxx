#pragma once

#include <algorithm>
#include <optional>
#include <string_view>

namespace fizzbuzz
{

template<class Return>
class basic_parser_return
{
public:
  using return_t = Return;
  using nullopt_t = std::nullopt_t;

  [[nodiscard]]
  explicit
  constexpr
  basic_parser_return(std::nullopt_t = std::nullopt) noexcept :
    value_{std::nullopt} {}

  [[nodiscard]]
  explicit
  constexpr
  basic_parser_return(return_t ret) noexcept :
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

using parser_return = basic_parser_return<std::string_view>;

} // namespace fizzbuzz
