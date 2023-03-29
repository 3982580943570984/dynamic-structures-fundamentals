#include <algorithm>
#include <iterator>
#include <random>

#include "set_list.hpp"

set_list::set_list() {}

set_list::~set_list() {}

bool set_list::empty() { return m_list.empty(); }

bool set_list::contains(int value) {
  return std::binary_search(m_list.begin(), m_list.end(), value);
}

bool set_list::insert(int value) {
  if (contains(value))
    return false;

  auto iter = std::lower_bound(m_list.begin(), m_list.end(), value);
  m_list.insert(iter, value);
  return true;
}

void set_list::generate(int amount, int min, int max, int mod) {
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

int set_list::cardinality() { return m_list.size(); }

std::string set_list::to_string(char separator) {
  std::string output;

  for (const auto &e : m_list)
    output += std::to_string(e) + separator;

  if (!output.empty())
    output.pop_back();

  return output;
}

bool set_list::is_subset(set_list other) {
  for (const auto &e : other.m_list)
    if (!contains(e))
      return false;
  return true;
}

bool set_list::is_equal(set_list other) { return m_list == other.m_list; }

set_list set_list::set_union(set_list other) {
  set_list output;

  for (const auto &e : m_list)
    output.insert(e);

  for (const auto &e : other.m_list)
    output.insert(e);

  return output;
}

set_list set_list::set_intersection(set_list other) {
  set_list output;

  for (const auto &e : other.m_list)
    if (contains(e))
      output.insert(e);

  return output;
}

set_list set_list::set_difference(set_list other) {
  set_list output;

  for (const auto &e : other.m_list)
    if (!contains(e))
      output.insert(e);

  return output;
}

set_list set_list::set_symmetric_difference(set_list other) {
  return set_intersection(other).set_difference(set_union(other));
}
