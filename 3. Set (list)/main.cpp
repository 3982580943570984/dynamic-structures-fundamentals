#include <iostream>

#include "set.hpp"

int main() {

  Set A;

  A.insert(1);
  A.insert(2);
  A.insert(6);
  A.insert(7);

  Set B;

  B.insert(5);
  B.insert(3);
  B.insert(2);
  B.insert(4);
  B.insert(1);

  B.generate(10, 12, 100, 3);
  A.generate(10, 18, 100, 9);

  std::cout << A.to_string() << std::endl;
  std::cout << B.to_string() << std::endl;

  std::cout << B.set_union(A).to_string() << std::endl;

  return 0;
}