#pragma once

#include "parser_return.hxx"
#include "return_value.hxx"
#include "parser_handler.hxx"

namespace fizzbuzz
{

template<class Number, class Return, class ParserReturn, class... Parsers>
class basic_parser
{
public:
  using number_t = Number;
  using return_t = Return;
  using parser_return_t = ParserReturn;

  template<class Parser>
  using parser_handler = basic_parser_handler<number_t, Parser, parser_return_t>;

  [[nodiscard]]
  static
  constexpr
  return_t
  parse(number_t const& number) noexcept
  {
    parser_return_t parsed[] = {(parser_handler<Parsers>::parse(number))...};
    std::vector<typename return_t::inner_t> hits{};
    hits.reserve(sizeof...(Parsers));

    for(auto const& val : parsed) {
      if(val.hit()) {
        hits.push_back(std::move(val.get()));
      }
    }

    if(hits.size() > 0) {
      return return_t{hits};
    } else {
      return return_t{};
    }
  }

};

//template<class... Parsers>
//using fizz_buzz_parser = basic_fizz_buzz_parser<int, basic_fizz_buzz_return_value<std::string_view>, fizz_buzz_parse_return, Parsers...>;
//using fizz_buzz_parser = basic_fizz_buzz_parser<int, basic_fizz_buzz_return_value<std::string_view>, basic_fizz_buzz_parse_return<std::string_view>, Parsers...>;

} // namespace fizzbuzz
