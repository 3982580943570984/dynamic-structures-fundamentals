#pragma once

#include <iostream>
#include <random>
#include <string>
#include <vector>

struct node {
  int value = 0;
  node *next = nullptr;
};

class set_class {
public:
  node *head = nullptr;

  // F1
  set_class();
  // F8
  ~set_class();

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
  bool is_subset(set_class *other);
  // F10
  bool is_equal(set_class *other);
  // F11
  set_class *make_union(set_class *other);
  // F12
  set_class *make_intersection(set_class *other);
  // F13
  set_class *make_complement(set_class *other);
  // F14
  set_class *make_symmetricDifference(set_class *other);
};
