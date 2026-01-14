#ifndef DESERIALIZER_H
#define DESERIALIZER_H

#include <sstream>
#include <iostream>

namespace cser
{

template<class deser_impl>
class deser
{
 public:
  deser(const deser_impl* derived) : self(derived) {}
  
  template<typename ... types> 
  inline deser& operator() (types& ... objs) {
    self->process(objs);
    return *self;
  }

 private:
  deser_impl* self;
  
  template<typename T>
  void process(T obj) {

  }
};

class byte_deser : public deser<byte_deser>
{
 public:
  template<class stream>
  byte_deser(stream &s) : stream(s) {}
  ~byte_deser() noexcept = default;

  void read(void* data, std::streamsize size) {
    auto const read_size = stream_.rdbuf()->sgetn( reinterpret_cast<char*>( data ), size );
    if(read_size != size) { /* todo */}
  }

 private:
  std::istream& stream_;
};


} // namespace cser

#endif /* DESERIALIZER_H */