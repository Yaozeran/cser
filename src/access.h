#ifndef ACCESS_H
#define ACCESS_H

#include <type_traits>


namespace cser
{

class access
{

template<class cserdes, class T>
inline static auto member_serdes(cserdes &serdes, T cls) -> decltype(cls.serdes(serdes)) {
  return cls.serdes(serdes);
}
  
};

} // namespace cser

#endif