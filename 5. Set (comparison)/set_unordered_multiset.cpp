#include <algorithm>
#include <iterator>
#include <random>

#include "set_unordered_multiset.hpp"

set_unordered_multiset::set_unordered_multiset() {}

set_unordered_multiset::~set_unordered_multiset() {}

bool set_unordered_multiset::empty() { return m_unordered_multiset.empty(); }

bool set_unordered_multiset::contains(int value) {
  for (const auto &e : this->m_unordered_multiset)
    if (e == value)
      return true;
  return false;
}

bool set_unordered_multiset::insert(int value) {
  if (contains(value))
    return false;

  m_unordered_multiset.insert(value);
  return true;
}

void set_unordered_multiset::generate(int amount, int min, int max, int mod) {
  if (max - min < amount || min > max)
    return;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max);

  m_unordered_multiset.clear();

  while (cardinality() < amount) {
    auto value = distr(gen);
    value -= value % mod;
    insert(value);
  }
}

int set_unordered_multiset::cardinality() {
  return m_unordered_multiset.size();
}

std::string set_unordered_multiset::to_string(char separator) {
  std::string output;

  for (const auto &e : m_unordered_multiset)
    output += std::to_string(e) + separator;

  if (!output.empty())
    output.pop_back();

  return output;
}

bool set_unordered_multiset::is_subset(set_unordered_multiset other) {
  for (const auto &e : other.m_unordered_multiset)
    if (!contains(e))
      return false;
  return true;
}

bool set_unordered_multiset::is_equal(set_unordered_multiset other) {
  return m_unordered_multiset == other.m_unordered_multiset;
}

set_unordered_multiset
set_unordered_multiset::set_union(set_unordered_multiset other) {
  set_unordered_multiset output;

  for (const auto &e : m_unordered_multiset)
    output.insert(e);

  for (const auto &e : other.m_unordered_multiset)
    output.insert(e);

  return output;
}

set_unordered_multiset
set_unordered_multiset::set_intersection(set_unordered_multiset other) {
  set_unordered_multiset output;

  for (const auto &e : other.m_unordered_multiset)
    if (contains(e))
      output.insert(e);

  return output;
}

set_unordered_multiset
set_unordered_multiset::set_difference(set_unordered_multiset other) {
  set_unordered_multiset output;

  for (const auto &e : other.m_unordered_multiset)
    if (!contains(e))
      output.insert(e);

  return output;
}

set_unordered_multiset
set_unordered_multiset::set_symmetric_difference(set_unordered_multiset other) {
  return set_intersection(other).set_difference(set_union(other));
}
