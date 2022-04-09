#pragma once

#include <concepts>
#include <type_traits>

namespace fizzbuzz
{

template<class T>
concept fizz_buzzable = std::is_integral<T>::value;

} // namespace fizzbuzz
