#pragma once

#include <iostream>
#include <random>
#include <string>
#include <vector>

struct node {
  int value = 0;
  node *next = nullptr;
};

class set {
public:
  node *head = nullptr;

public:
  // F1
  set();
  // F8
  ~set();

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
  bool is_subset(set *other);
  // F10
  bool is_equal(set *other);
  // F11
  set *make_union(set *other);
  // F12
  set *make_intersection(set *other);
  // F13
  set *make_complement(set *other);
  // F14
  set *make_symmetricDifference(set *other);
};
