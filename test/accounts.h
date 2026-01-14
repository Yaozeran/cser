#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <string>

#include "../src/cser.h"

class Account 
{
 public:

  Account() = default;
  Account(unsigned long id, std::string name, std::string password, float bal)
    : id_(id), holder_name_(name), password_(password), balance_(bal) {}
  ~Account() noexcept = default;

  template<class cserdes>
  void serdes(cserdes serdes) {
    serdes(id_, holder_name_, password_, balance_);
  }

  std::string ToString() const {
    return " ";
  }
  
 private:
  
  // friend class cser::access;

  unsigned long id_;
  std::string holder_name_;
  std::string password_;
  float balance_;
};

#endif