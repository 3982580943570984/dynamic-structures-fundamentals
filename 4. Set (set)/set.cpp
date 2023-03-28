#include "set.hpp"

#include <iostream>

Set::Set() {}

Set::~Set() {}

bool Set::empty() { return m_set.empty(); }

bool Set::contains(int value) { return m_set.contains(value); }

bool Set::insert(int value) { return m_set.insert(value).second; }

void Set::generate(int amount, int min, int max, int mod) {
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

int Set::cardinality() { return m_set.size(); }

std::string Set::to_string(char separator) {
  std::string output;

  for (const auto &e : m_set)
    output += std::to_string(e) + separator;

  if (!output.empty())
    output.pop_back();

  return output;
}

bool Set::is_subset(Set other) {
  for (const auto &e : other.m_set)
    if (!m_set.contains(e))
      return false;
  return true;
}

bool Set::is_equal(Set other) { return m_set == other.m_set; }

Set Set::set_union(Set other) {
  Set output;

  for (const auto &e : m_set)
    output.insert(e);

  for (const auto &e : other.m_set)
    output.insert(e);

  return output;
}

Set Set::set_intersection(Set other) {
  Set output;

  for (const auto &e : other.m_set)
    if (m_set.contains(e))
      output.insert(e);

  return output;
}

Set Set::set_difference(Set other) {
  Set output;

  for (const auto &e : other.m_set)
    if (!m_set.contains(e))
      output.insert(e);

  return output;
}

Set Set::set_symmetric_difference(Set other) {
  return set_intersection(other).set_difference(set_union(other));
}
