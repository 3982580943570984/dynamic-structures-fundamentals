#pragma once

#include <deque>
#include <string>

class set_deque {
public:
  std::deque<int32_t> m_deque;

  // F1
  set_deque();
  // F8
  ~set_deque();

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
  bool is_subset(set_deque other);
  // F10
  bool is_equal(set_deque other);
  // F11
  set_deque set_union(set_deque other);
  // F12
  set_deque set_intersection(set_deque other);
  // F13
  set_deque set_difference(set_deque other);
  // F14
  set_deque set_symmetric_difference(set_deque other);
};