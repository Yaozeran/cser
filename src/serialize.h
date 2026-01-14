#ifndef SERIALIZE_H
#define SERIALIZE_h

#include <cstdlib>
#include <array>
#include <string>

#include "serializer.h"

namespace cser
{

template<class Serializer, class T, size_t N>
inline void ser_read_array(Serializer ser, const std::array<T, N> &arr) {
  ser.read(arr.data(), N * sizeof(T));
}

template<class Serializer, class T, size_t N>
inline void ser_write_array(Serializer ser, const std::array<T, N> &arr) {
  ser.write(arr.data(), N * sizeof(T));
}

template<class Serializer, class CharT, class Traits, class Alloc>
inline void ser_read_string(Serializer ser, std::basic_string<CharT, Traits, Alloc> &str) {
  ser.read(str.size());
  ser.read(str.data(), str.size() * sizeof(CharT));
}

template<class Serializer, class CharT, class Traits, class Alloc>
inline void ser_write_string(Serializer ser, std::basic_string<CharT, Traits, Alloc> &str) {
  ser.write(str.size());
  ser.write(str.data(), str.size() * sizeof(CharT));
}

} // namespace cser

#endif /* SERIALIZE_H */