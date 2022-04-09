#pragma once

#include "fizzbuzzable.hxx"
#include "return_value.hxx"
#include "standard_parsers.hxx"
#include "parser.hxx"

namespace fizzbuzz
{

template<concepts::fizzbuzzable Number, class ReturnValue, class... Parsers>
class basic_fizzbuzz
{
public:

  using number_t = Number;
  using return_t = ReturnValue;
  using parser_t = basic_parser<int, return_t, basic_parser_return<typename return_t::inner_t>, Parsers...>;

  [[nodiscard]]
  explicit
  constexpr
  basic_fizzbuzz() noexcept {}

  [[nodiscard]]
  constexpr
  return_t
  operator()(number_t const& num) noexcept
  {
    return parser_t::parse(num);
  }

};

using fizzbuzz = basic_fizzbuzz<int, return_value, standard::parser_3, standard::parser_5>;

} // namespace fizzbuzz
