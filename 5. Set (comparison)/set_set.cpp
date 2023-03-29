#include "set_set.hpp"

#include <iostream>

set_set::set_set() {}

set_set::~set_set() {}

bool set_set::empty() { return m_set.empty(); }

bool set_set::contains(int value) { return m_set.contains(value); }

bool set_set::insert(int value) { return m_set.insert(value).second; }

void set_set::generate(int amount, int min, int max, int mod) {
  if (max - min < amount || min > max)
    return;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max);

  m_set.clear();

  while (cardinality() < amount) {
    auto value = distr(gen);
    value -= value % mod;
    insert(value);
  }
}

int set_set::cardinality() { return m_set.size(); }

std::string set_set::to_string(char separator) {
  std::string output;

  for (const auto &e : m_set)
    output += std::to_string(e) + separator;

  if (!output.empty())
    output.pop_back();

  return output;
}

bool set_set::is_subset(set_set other) {
  for (const auto &e : other.m_set)
    if (!m_set.contains(e))
      return false;
  return true;
}

bool set_set::is_equal(set_set other) { return m_set == other.m_set; }

set_set set_set::set_union(set_set other) {
  set_set output;

  for (const auto &e : m_set)
    output.insert(e);

  for (const auto &e : other.m_set)
    output.insert(e);

  return output;
}

set_set set_set::set_intersection(set_set other) {
  set_set output;

  for (const auto &e : other.m_set)
    if (m_set.contains(e))
      output.insert(e);

  return output;
}

set_set set_set::set_difference(set_set other) {
  set_set output;

  for (const auto &e : other.m_set)
    if (!m_set.contains(e))
      output.insert(e);

  return output;
}

set_set set_set::set_symmetric_difference(set_set other) {
  return set_intersection(other).set_difference(set_union(other));
}
