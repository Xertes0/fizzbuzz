#pragma once

#include "parser_return.hxx"

namespace fizzbuzz
{

namespace standard
{

template<class Number, class ParseReturn>
class basic_parser_3
{
public:
  using number_t = Number;
  using parse_return_t = ParseReturn;

  [[nodiscard]]
  static
  constexpr
  parse_return_t
  parse(number_t const& number) noexcept
  {
    if(number%3 == 0) {
      return parse_return_t{std::string_view{"Fizz"}};
    }

    return parse_return_t{};
  }

};

template<class Number, class ParseReturn>
class basic_parser_5
{
public:
  using number_t = Number;
  using parse_return_t = ParseReturn;

  [[nodiscard]]
  static
  constexpr
  parse_return_t
  parse(number_t const& number) noexcept
  {
    if(number%5 == 0) {
      return parse_return_t{std::string_view{"Buzz"}};
    }

    return parse_return_t{};
  }

};

using parser_3 = basic_parser_3<int, parser_return>;
using parser_5 = basic_parser_5<int, parser_return>;

} // namesapce fizzbuzz::standard

} // namespace fizzbuzz
