#include <chrono>
#include <iostream>

#include "set.hpp"

int main() {

  Set A;
  A.generate(10000, 18, 100000, 9);

  Set B;
  B.generate(10000, 12, 100000, 3);

  auto start = std::chrono::high_resolution_clock::now();
  auto res = B.set_symmetric_difference(A);
  auto end = std::chrono::high_resolution_clock::now();

  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
                   .count()
            << std::endl;

  return 0;
}