#include <array>
#include <chrono>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

#include <fcntl.h>
#include <io.h>

#include "set_class.hpp"
#include "set_extended.hpp"
#include "set_list.hpp"
#include "set_set.hpp"

inline void make_input(std::uint32_t &N) {
  std::wcout << L"Введите количество элементов множества (N >= 1000): ";
  while (!(std::cin >> N) || N < 1000 ||
         N > std::numeric_limits<std::uint32_t>::max()) {
    std::wcout
        << L"Некорректный ввод. Пожалуйста, введите количество элементов "
           L"множества(N >= 1000): ";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
}

template <typename R, typename T, typename... Args>
inline auto measure_from_obj(T &obj, R (T::*func)(Args...), Args &&...args) {
  auto start = std::chrono::high_resolution_clock::now();
  (obj.*func)(std::forward<Args>(args)...);
  auto end = std::chrono::high_resolution_clock::now();
  return std::wstring{
      std::to_wstring(
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
              .count()) +
      L" ns"};
}

template <typename R, typename T, typename... Args>
inline auto measure_time2(T &obj, R (T::*func)(Args...), Args &...args) {
  auto start = std::chrono::high_resolution_clock::now();
  (obj.*func)(std::forward<Args>(args)...);
  auto end = std::chrono::high_resolution_clock::now();
  return std::wstring{
      std::to_wstring(
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
              .count()) +
      L" ns"};
}

template <typename Func, typename... Args>
inline auto measure_from_ptr(Func &func, Args &&...args) {
  auto start = std::chrono::high_resolution_clock::now();
  std::forward<Func>(func)(std::forward<Args>(args)...);
  auto end = std::chrono::high_resolution_clock::now();
  return std::wstring{
      std::to_wstring(
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
              .count()) +
      L" ns"};
}

int main() {
  _setmode(_fileno(stdout), _O_U16TEXT);

  std::uint32_t N{0};
  make_input(N);

  node_ *A_extended = nullptr, *B_extended = nullptr;
  auto A_class = set_class(), B_class = set_class();
  auto A_list = set_list(), B_list = set_list();
  auto A_set = set_set(), B_set = set_set();

  A_extended = createSet(N, 10, N * 10, true);
  B_extended = createSet(N, 10, N * 10, true);

  B_class.generate(N, 10, N * 10, true);
  B_list.generate(N, 10, N * 10, true);
  B_set.generate(N, 10, N * 10, true);

  constexpr int column_size = 5;
  std::array<std::wstring, column_size> headers{
      {L"", L"Односв. список", L"Класс Список", L"Класс List", L"Класс Set"}};

  std::array<std::array<std::wstring, column_size>, 11> data = {
      {{{L"Генерация",
         measure_from_ptr(createSet, static_cast<int>(N), static_cast<int>(10),
                          static_cast<int>(N * 10), static_cast<int>(true)),
         measure_from_obj(A_class, &set_class::generate, static_cast<int>(N),
                          static_cast<int>(10), static_cast<int>(N * 10),
                          static_cast<int>(true)),
         measure_from_obj(A_list, &set_list::generate, static_cast<int>(N),
                          static_cast<int>(10), static_cast<int>(N * 10),
                          static_cast<int>(true)),
         measure_from_obj(A_set, &set_set::generate, static_cast<int>(N),
                          static_cast<int>(10), static_cast<int>(N * 10),
                          static_cast<int>(true))}},

       {{L"Мощность", measure_from_ptr(cardinality, A_extended),
         measure_from_obj(A_class, &set_class::cardinality),
         measure_from_obj(A_list, &set_list::cardinality),
         measure_from_obj(A_set, &set_set::cardinality)}},

       {{L"A ⊆ A", measure_from_ptr(isSubset, A_extended, A_extended),
         measure_from_obj(A_class, &set_class::is_subset, &A_class),
         measure_time2(A_list, &set_list::is_subset, A_list),
         measure_time2(A_set, &set_set::is_subset, A_set)}},

       {{L"B ⊆ A", measure_from_ptr(isSubset, A_extended, B_extended),
         measure_from_obj(B_class, &set_class::is_subset, &A_class),
         measure_time2(B_list, &set_list::is_subset, A_list),
         measure_time2(B_set, &set_set::is_subset, A_set)}},

       {{L"A == B", measure_from_ptr(isEqual, A_extended, B_extended),
         measure_from_obj(A_class, &set_class::is_equal, &B_class),
         measure_time2(A_list, &set_list::is_equal, B_list),
         measure_time2(A_set, &set_set::is_equal, B_set)}},

       {{L"В == А", measure_from_ptr(isEqual, B_extended, A_extended),
         measure_from_obj(B_class, &set_class::is_equal, &A_class),
         measure_time2(B_list, &set_list::is_equal, A_list),
         measure_time2(B_set, &set_set::is_equal, A_set)}},

       {{L"A ∪ B", measure_from_ptr(makeUnion, A_extended, B_extended),
         measure_from_obj(A_class, &set_class::make_union, &B_class),
         measure_time2(A_list, &set_list::set_union, B_list),
         measure_time2(A_set, &set_set::set_union, B_set)}},

       {{L"A ∩ B", measure_from_ptr(makeIntersection, A_extended, B_extended),
         measure_from_obj(A_class, &set_class::make_intersection, &B_class),
         measure_time2(A_list, &set_list::set_intersection, B_list),
         measure_time2(A_set, &set_set::set_intersection, B_set)}},

       {{L"А ∖ В", measure_from_ptr(makeComplement, A_extended, B_extended),
         measure_from_obj(A_class, &set_class::make_complement, &B_class),
         measure_time2(A_list, &set_list::set_difference, B_list),
         measure_time2(A_set, &set_set::set_difference, B_set)}},

       {{L"В ∖ А", measure_from_ptr(makeComplement, B_extended, A_extended),
         measure_from_obj(B_class, &set_class::make_complement, &A_class),
         measure_time2(B_list, &set_list::set_difference, A_list),
         measure_time2(B_set, &set_set::set_difference, A_set)}},

       {{L"A ⊖ B",
         measure_from_ptr(makeSymmetricDifference, A_extended, B_extended),
         measure_from_obj(A_class, &set_class::make_symmetricDifference,
                          &B_class),
         measure_time2(A_list, &set_list::set_symmetric_difference, B_list),
         measure_time2(A_set, &set_set::set_symmetric_difference, B_set)}}}};

  std::wcout << cardinality(A_extended) << std::endl;

  constexpr int name_wid = 20;
  constexpr int column_wid = 20;

  auto print_line = [](std::array<std::wstring, column_size> const &tbl) {
    auto const &[Name, Column1, Column2, Column3, Column4] = tbl;

    std::wcout.width(name_wid);
    std::wcout << (L"| " + Name) << '|';

    std::wcout.width(column_wid);
    std::wcout << (L' ' + Column1) << '|';

    std::wcout.width(column_wid);
    std::wcout << (L' ' + Column2) << '|';

    std::wcout.width(column_wid);
    std::wcout << (L' ' + Column3) << '|';

    std::wcout.width(column_wid);
    std::wcout << (L' ' + Column4) << '|';

    std::wcout << '\n';
  };

  constexpr int total_wid = name_wid + column_wid * 4 + column_size;

  auto print_break = [&] {
    std::wcout.width(total_wid);
    std::wcout.fill('-');
    std::wcout << '-' << '\n';
    std::wcout.fill(' ');
  };

  std::wcout.setf(std::ios::left, std::ios::adjustfield);
  print_break();
  print_line(headers);
  print_break();
  for (const auto &entry : data)
    print_line(entry);
  print_break();

  deleteSet(A_extended);
  deleteSet(B_extended);

  return 0;
}