#include "accounts.h"

#include "../src/cser.h"

int main() {
  Account sample1 = {1, "Alex Wang", "123489765", 0.0};
   
  std::stringstream storage;

  cser::byte_ser ser(storage);
  cser::byte_deser deser(storage);
  
  ser(sample1);
  std::cout << "Data serialized. Buffer size: " << storage.str().size() << " bytes." << std::endl;

  std::cout << "\n" << std::endl;

  Account sample2 {};
  deser(sample2);
  std::cout << "Data Deserialized: \n" << sample2.ToString() << std::endl;
}