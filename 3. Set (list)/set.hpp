#pragma once

#include <list>
#include <string>

class Set {
public:
  std::list<int32_t> m_list;

  // F1
  Set();
  // F8
  ~Set();

  // F2
  bool empty();
  // F3
  bool contains(int value);
  // F4
  bool insert(int value);
  // F5
  void generate(int amount, int min, int max, int mod = 3);
  // F6
  int cardinality();
  // F7
  std::string to_string(char separator = ' ');
  // F9
  bool is_subset(Set other);
  // F10
  bool is_equal(Set other);
  // F11
  Set set_union(Set other);
  // F12
  Set set_intersection(Set other);
  // F13
  Set set_difference(Set other);
  // F14
  Set set_symmetric_difference(Set other);
};