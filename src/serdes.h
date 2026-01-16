#ifndef SERDES_H
#define SERDES_H

#include <cstdlib>
#include <array>
#include <string>

#include "serializer.h"
#include "deserializer.h"
#include "helper.h"

namespace cser
{

template<typename t>
inline typename std::enable_if<std::is_arithmetic<t>::value, void>::type
serialize(byte_serializer& ser, const t& v) {
  ser.write(std::addressof(v), sizeof(v));
}

template<typename t>
inline typename std::enable_if<std::is_arithmetic<t>::value, void>::type
deserialize(byte_deserializer& des, t& v) {
  des.read(std::addressof(v), sizeof(v));
}

template<class t>
void serialize(byte_serializer& ser, const binary_data<t>& bd) {
  ser.write(bd.data_, static_cast<std::streamsize>(bd.size_));
}

template<class t>
void deserialize(byte_deserializer& des, binary_data<t>& bd) {
  des.read(bd.data_, static_cast<std::streamsize>(bd.size_));
}

template<class t>
void serialize(byte_serializer& ser, const size_tag<t>& tag) {
  ser(tag.size_);
}

template<class t>
void deserialize(byte_deserializer& des, size_tag<t>& tag) {
  des(tag.size_);
}

template<class serializer, class t, size_t n>
inline typename std::enable_if<
  is_serializable<binary_data<t>, serializer>::value && 
  std::is_arithmetic<t>::value, void>::type 
serialize(serializer &ser, const std::array<t, n> &arr) {
  ser( make_binary_data(arr.data(), n * sizeof(t)) );
}

template<class deserializer, class t, size_t n>
inline typename std::enable_if<
  is_deserializable<binary_data<t>, deserializer>::value && 
  std::is_arithmetic<t>::value, void>::type
deserialize(deserializer &des, std::array<t, n> &arr) {
  des( make_binary_data(arr.data(), n * sizeof(t)) );
}

template<class serializer, class char_t, class traits, class alloc>
inline typename std::enable_if<is_serializable<binary_data<char_t>, serializer>::value, void>::type
serialize(serializer &ser, const std::basic_string<char_t, traits, alloc> &str) {
  ser( make_size_tag(str.size()) );
  ser( make_binary_data(const_cast<char_t*>(str.data()), str.size() * sizeof(char_t)) );
}

template<class deserializer, class char_t, class traits, class alloc>
inline typename std::enable_if<is_deserializable<binary_data<char_t>, deserializer>::value, void>::type
deserialize(deserializer &des, std::basic_string<char_t, traits, alloc> &str) {
  des( make_size_tag(str.size()) );
  des( make_binary_data(const_cast<char_t*>(str.data()), str.size() * sizeof(char_t)) );
}

} // namespace cser

#endif /* SERIALIZE_H */