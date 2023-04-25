#pragma once

#include <string>
#include <unordered_set>

class set_unordered_multiset {
public:
  std::unordered_multiset<int32_t> m_unordered_multiset;

  // F1
  set_unordered_multiset();
  // F8
  ~set_unordered_multiset();

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
  bool is_subset(set_unordered_multiset other);
  // F10
  bool is_equal(set_unordered_multiset other);
  // F11
  set_unordered_multiset set_union(set_unordered_multiset other);
  // F12
  set_unordered_multiset set_intersection(set_unordered_multiset other);
  // F13
  set_unordered_multiset set_difference(set_unordered_multiset other);
  // F14
  set_unordered_multiset set_symmetric_difference(set_unordered_multiset other);
};