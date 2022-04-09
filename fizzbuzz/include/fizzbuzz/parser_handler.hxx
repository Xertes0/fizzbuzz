#pragma once

namespace fizzbuzz
{

template<class Number, class Parser, class ParserReturn>
class basic_parser_handler
{
public:
  using number_t = Number;
  using parser_t = Parser;
  using parser_return_t = ParserReturn;

  [[nodiscard]]
  static
  constexpr
  parser_return_t
  parse(number_t const& number) noexcept
  {
    return parser_t::parse(number);
  }
};

} // namespace fizzbuzz
