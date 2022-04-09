#include <fizzbuzz/fizzbuzz.hxx>
#include <iostream>
#include <iterator>

template<class Number, class ParseReturn>
class basic_custom_parser
{
public:
  using number_t = Number;
  using parse_return_t = ParseReturn;

  [[nodiscard]]
  static
  constexpr
  parse_return_t
  parse(number_t const& number)
  {
    if(number%6 == 2) {
      return parse_return_t{std::string_view{"custom_parser_hit"}};
    }

    return parse_return_t{};
  }

};

using custom_parser = basic_custom_parser<int, fizzbuzz::parser_return>;

int
main()
{
  fizzbuzz::standard_fizzbuzz<custom_parser, fizzbuzz::standard::parser_3, fizzbuzz::standard::parser_5> fz{};

  int in;
  std::cin >> in;

  fz(in, std::ostream_iterator<std::string_view>(std::cout, " "));
  std::cout << '\n';

  return 0;
}
