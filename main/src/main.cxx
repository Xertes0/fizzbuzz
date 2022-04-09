#include <fizzbuzz/fizzbuzz.hxx>
#include <iostream>

int
main()
{
  fizzbuzz::fizzbuzz fz{};

  int in;
  std::cin >> in;
  std::cout << in << ": " << fz(in).get_or_default() << '\n';

  return 0;
}
