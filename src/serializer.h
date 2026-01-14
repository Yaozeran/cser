#ifndef ser_H
#define ser_H

#include <sstream>
#include <iostream>

namespace cser
{

/*
 * Base ser 
 */
template<class ser_impl>
class ser
{
 public:
  ser(const ser_impl* derived) : self(derived) {}
  
  template<typename ... Types> 
  inline ser& operator() (Types& ... objs) {
    self->process(objs);
    return *self;
  }

 private:
  ser_impl* self;
  
  template<typename T>
  void process(T obj) {

  }

  #define PROCESS_IF(name) 
};

/*
 * A ser to produce a byte stream from an object
 */
class byte_ser : public ser<byte_ser>
{
 public: 
  template<class stream>
  byte_ser(stream &s) : stream(s) {}
  ~byte_ser() noexcept = default;

  void write(const void* data, std::streamsize size) {
    auto const written_size = stream_.rdbuf()->sputn(reinterpret_cast<const char*>(data), size);
    if(written_size != size) {/* todo */};
  }

 private:
  std::ostream& stream_;
};

} // namespace cser

#endif /* ser_H */