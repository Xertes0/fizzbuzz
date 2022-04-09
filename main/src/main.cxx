#include <fizzbuzz/fizzbuzz.hxx>
#include <iostream>
#include <iterator>

int
main()
{
  fizzbuzz::fizzbuzz fz{};

  int in;
  std::cin >> in;

  // There are 2 ways to use fizzbuzz
  
  // a) pass an output iterator
  fz(in, std::ostream_iterator<std::string_view>(std::cout, " "));
  std::cout << '\n';

  // b) return vector of values
  auto ret = fz(in);
  if(ret) {
    //std::cout << in << ":";
    for(auto const& val : ret.get()) {
      std::cout << val << ' ';
    }
    std::cout << '\n';
  }

  return 0;
}
