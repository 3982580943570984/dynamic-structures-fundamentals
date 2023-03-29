#pragma once

#include <list>
#include <string>

class set_list {
public:
  std::list<int32_t> m_list;

  // F1
  set_list();
  // F8
  ~set_list();

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
  bool is_subset(set_list other);
  // F10
  bool is_equal(set_list other);
  // F11
  set_list set_union(set_list other);
  // F12
  set_list set_intersection(set_list other);
  // F13
  set_list set_difference(set_list other);
  // F14
  set_list set_symmetric_difference(set_list other);
};