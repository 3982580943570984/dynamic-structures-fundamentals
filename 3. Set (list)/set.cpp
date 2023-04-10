#include <algorithm>
#include <iterator>
#include <random>

#include "set.hpp"

Set::Set() {}

Set::~Set() {}

bool Set::empty() { return m_list.empty(); }

bool Set::contains(int value) {
  return std::binary_search(m_list.begin(), m_list.end(), value);
}

bool Set::insert(int value) {
  if (contains(value))
    return false;

  auto iter = std::lower_bound(m_list.begin(), m_list.end(), value);
  m_list.insert(iter, value);
  return true;
}

void Set::generate(int amount, int min, int max, int mod) {
  if (max - min < amount || min > max)
    return;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max);

  m_list.clear();

  while (cardinality() < amount) {
    auto value = distr(gen);
    value -= value % mod;
    insert(value);
  }
}

int Set::cardinality() { return m_list.size(); }

std::string Set::to_string(char separator) {
  std::string output;

  for (const auto &e : m_list)
    output += std::to_string(e) + separator;

  if (!output.empty())
    output.pop_back();

  return output;
}

bool Set::is_subset(Set other) {
  for (const auto &e : other.m_list)
    if (!contains(e))
      return false;
  return true;
}

bool Set::is_equal(Set other) { return m_list == other.m_list; }

Set Set::set_union(Set other) {
  Set output;

  for (const auto &e : m_list)
    output.insert(e);

  for (const auto &e : other.m_list)
    output.insert(e);

  return output;
}

Set Set::set_intersection(Set other) {
  Set output;

  for (const auto &e : other.m_list)
    if (contains(e))
      output.insert(e);

  return output;
}

Set Set::set_difference(Set other) {
  Set output;

  for (const auto &e : other.m_list)
    if (!contains(e))
      output.insert(e);

  return output;
}

Set Set::set_symmetric_difference(Set other) {
  return set_intersection(other).set_difference(set_union(other));
}
