#ifndef ACCESS_H
#define ACCESS_H

#include <type_traits>

namespace cser
{

class access
{
 public:
 
  template<class cserdes, class t>
  inline static auto member_serdes(cserdes &serdes, t cls) -> decltype(cls.serdes(serdes)) {
    return cls.serdes(serdes);
  }
  
};

} // namespace cser

#endif