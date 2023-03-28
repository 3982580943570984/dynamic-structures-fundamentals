#include "./set.hpp"
#include <iostream>

std::int32_t main() {

  auto A = Set{}, B = Set{};

  // F5
  A.generate(10, 12, 100, 3);
  std::cout << "Сгенерированное множество A: " << A.to_string() << std::endl;
  B.generate(10, 18, 100, 9);
  std::cout << "Сгенерированное множество B: " << B.to_string() << std::endl;

  // F6
  std::cout << "Мощность множества A: " << A.cardinality() << std::endl;
  std::cout << "Мощность множества B: " << B.cardinality() << std::endl;

  // F7
  std::cout << "Вывод множества A: " << A.to_string() << std::endl;
  std::cout << "Вывод множества B: " << B.to_string() << std::endl;

  // F9
  std::cout << "A является подмножеством B: " << A.is_subset(B) << std::endl;
  std::cout << "A является подмножеством A: " << A.is_subset(A) << std::endl;

  // F10
  std::cout << "A равняется B: " << A.is_equal(B) << std::endl;
  std::cout << "A равняется A: " << A.is_equal(A) << std::endl;

  // F11
  auto result = A.set_union(B);
  std::cout << "Объединение множества A и B: " << result.to_string()
            << std::endl;

  // F12
  result = A.set_intersection(B);
  std::cout << "Пересечение множества A и B: " << result.to_string()
            << std::endl;

  // F13
  result = A.set_difference(B);
  std::cout << "Разность множества A и B: " << result.to_string() << std::endl;

  result = B.set_difference(A);
  std::cout << "Разность множества B и A: " << result.to_string() << std::endl;

  // F14
  result = A.set_symmetric_difference(B);
  std::cout << "Симметрическая разность A и B: " << result.to_string()
            << std::endl;

  return 0;
}