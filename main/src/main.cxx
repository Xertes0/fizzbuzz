#include <fizzbuzz/fizzbuzz.hxx>
#include <iostream>

int
main()
{
  fizzbuzz::fizzbuzz fz{};

  int in;
  std::cin >> in;
  auto ret = fz(in);
  if(ret) {
    std::cout << in << ":";
    for(auto const& val : ret.get()) {
      std::cout << " " << val;
    }
    std::cout << '\n';
  }

  return 0;
}
