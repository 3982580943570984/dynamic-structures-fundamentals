#include "./set.hpp"
#include <iostream>

/*
24.	Множество А – множество чисел, кратных 9. Множество В – множество чисел,
кратных 3.
*/

std::int32_t main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(6, 9);

  node *A = createSet(distr(gen), 10, 100, false);
  node *B = createSet(distr(gen), 10, 100, true);

  std::cout << "Множество A: " << toString(A, ',') << std::endl;
  std::cout << "Множество B: " << toString(B, ',') << std::endl;
  std::cout << std::endl;

  std::cout << "F9: " << std::endl;
  std::cout << "A является подмножеством B: " << isSubset(A, B) << std::endl;
  std::cout << "A является подмножеством A: " << isSubset(A, A) << std::endl;
  std::cout << std::endl;

  std::cout << "F10: " << std::endl;
  std::cout << "A равняется B: " << isEqual(A, B) << std::endl;
  std::cout << "A равняется A: " << isEqual(A, A) << std::endl;
  std::cout << std::endl;

  std::cout << "F11: " << std::endl;
  std::cout << "Объединение A и B: " << toString(makeUnion(A, B), ',')
            << std::endl;
  std::cout << std::endl;

  std::cout << "F12: " << std::endl;
  std::cout << "Пересечение A и B: " << toString(makeIntersection(A, B), ',')
            << std::endl;
  std::cout << std::endl;

  std::cout << "F13: " << std::endl;
  std::cout << "Разность A и B: " << toString(makeComplement(A, B), ',')
            << std::endl;
  std::cout << "Разность B и A: " << toString(makeComplement(B, A), ',')
            << std::endl;
  std::cout << std::endl;

  std::cout << "F14: " << std::endl;
  std::cout << "Симметрическая разность A и B: "
            << toString(makeSymmetricDifference(B, A), ',') << std::endl;
  std::cout << std::endl;

  return 0;
}
