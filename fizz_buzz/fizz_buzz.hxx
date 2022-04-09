#pragma once

#include "fizz_buzzable.hxx"
#include "fizz_buzz_return_value.hxx"
#include "fizz_buzz_standard_parsers.hxx"
#include "fizz_buzz_parse.hxx"

namespace fizzbuzz
{

template<fizz_buzzable Number, class ReturnValue, class... Parsers>
class basic_fizz_buzz
{
public:

  using number_t = Number;
  using return_t = ReturnValue;
  using parser_t = basic_fizz_buzz_parser<int, return_t, basic_fizz_buzz_parse_return<typename return_t::inner_t>, Parsers...>;

  [[nodiscard]]
  explicit
  constexpr
  basic_fizz_buzz() noexcept {}

  [[nodiscard]]
  constexpr
  return_t
  operator()(number_t const& num) noexcept
  {
    return parser_t::parse(num);
  }

};

using fizz_buzz = basic_fizz_buzz<int, fizz_buzz_return_value, standard::parser_3, standard::parser_5>;

} // namespace fizzbuzz
