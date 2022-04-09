#pragma once

#include "fizz_buzz_parse_return.hxx"
#include "fizz_buzz_return_value.hxx"

namespace fizzbuzz
{

template<class Number, class Parser, class ParserReturn>
class basic_fizz_buzz_parse_handler
{
public:
  using number_t = Number;
  using parser_t = Parser;
  using parser_return_t = ParserReturn;

  [[nodiscard]]
  static
  constexpr
  parser_return_t
  //basic_fizz_buzz_parse_return<std::string_view>
  parse(number_t const& number) noexcept
  {
    return parser_t::parse(number);
  }
};

template<class Number, class Return, class ParserReturn, class... Parsers>
class basic_fizz_buzz_parser
{
public:
  using number_t = Number;
  using return_t = Return;
  using parser_return_t = ParserReturn;

  template<class Parser>
  using fizz_buzz_parse_handler = basic_fizz_buzz_parse_handler<number_t, Parser, parser_return_t>;

  [[nodiscard]]
  static
  constexpr
  return_t
  parse(number_t const& number) noexcept
  {
    parser_return_t parsed[] = {(fizz_buzz_parse_handler<Parsers>::parse(number))...};
    for(auto const val : parsed) {
      if(val.hit()) {
        return return_t{val.get()};
      }
    }

    return return_t{};
  }

};

//template<class... Parsers>
//using fizz_buzz_parser = basic_fizz_buzz_parser<int, basic_fizz_buzz_return_value<std::string_view>, fizz_buzz_parse_return, Parsers...>;
//using fizz_buzz_parser = basic_fizz_buzz_parser<int, basic_fizz_buzz_return_value<std::string_view>, basic_fizz_buzz_parse_return<std::string_view>, Parsers...>;

} // namespace fizzbuzz
