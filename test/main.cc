#include "accounts.h"

#include "../src/cser.h"

int main() {
  Account sample1 = {1, "Alex Wang", "123489765", 0.0};
   
  std::stringstream storage;

  cser::byte_serializer ser(storage);
  cser::byte_deserializer des(storage);

  // std::string str{"hello world"};
  // int i(10), j;
  // ser(i, str);
  // std::cout << storage.str().size() << std::endl;

  // storage.seekg(0);

  // std::string str2{" "};
  // des(j, str2);
  // std::cout << j << std::endl;
  // std::cout << str2 << std::endl;
  
  ser(sample1);
  std::cout << "Data serialized. Buffer size: " << storage.str().size() << " bytes." << std::endl;

  std::cout << "\n" << std::endl;
  
  Account sample2 {};

  des(sample2);

  std::cout << "Data Deserialized: \n" << sample2.ToString() << std::endl;

  return 0;
}