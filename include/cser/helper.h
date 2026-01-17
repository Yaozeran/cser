#ifndef HELPER_H
#define HELPER_H

#include <cstdint>
#include <utility>

namespace cser
{

template<class t>
struct binary_data {
  /* cannot implicitly convert const ptr to void* , use pt */
  using pt = typename std::conditional<
    std::is_const<typename std::remove_pointer<typename std::remove_reference<t>::type>::type>::value,
    const void*, void*>::type;
  pt data_;
  uint64_t size_;
  binary_data(t&& d, uint64_t s) : data_(std::forward<t>(d)), size_(s) {}
};

template<class t>
inline binary_data<t> make_binary_data(t&& data, size_t size) {
  return {std::forward<t>(data), size};
}

template<typename t>
class size_tag 
{
 using ty = typename std::conditional<std::is_lvalue_reference<t>::value, t, typename std::decay<t>::type>::type;
 public:
  ty size_;
  size_tag(t&& sz) : size_(std::forward<t>(sz)) {}
 private:
  size_tag& operator=(const size_tag&) = delete;
};

template<class t>
inline size_tag<t> make_size_tag(t sz) {
  return {std::forward<t>(sz)};
}

} // namespace cser


#endif /* HELPER_H */