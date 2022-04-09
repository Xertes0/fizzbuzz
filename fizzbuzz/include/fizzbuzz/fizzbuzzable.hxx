#pragma once

#include <concepts>
#include <type_traits>

namespace fizzbuzz
{

namespace concepts
{

template<class T>
concept fizzbuzzable = std::is_integral<T>::value;

} // namespace fizzbuzz::concepts

} // namespace fizzbuzz
