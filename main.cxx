#include "fizz_buzz/fizz_buzz.hxx"

#include <iostream>

int
main()
{
  fizzbuzz::fizz_buzz fz{};

  int in;
  std::cin >> in;
  std::cout << in << ": " << fz(in).get_or_default() << '\n';

  return 0;
}
