#include <algorithm>
#include <iterator>
#include <random>

#include "set_deque.hpp"

set_deque::set_deque() {}

set_deque::~set_deque() {}

bool set_deque::empty() { return m_deque.empty(); }

bool set_deque::contains(int value) {
  for (const auto &e : this->m_deque)
    if (e == value)
      return true;
  return false;
}

bool set_deque::insert(int value) {
  if (contains(value))
    return false;

  m_deque.push_front(value);
  return true;
}

void set_deque::generate(int amount, int min, int max, int mod) {
  if (max - min < amount || min > max)
    return;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max);

  m_deque.clear();

  while (cardinality() < amount) {
    auto value = distr(gen);
    value -= value % mod;
    insert(value);
  }
}

int set_deque::cardinality() { return m_deque.size(); }

std::string set_deque::to_string(char separator) {
  std::string output;

  for (const auto &e : m_deque)
    output += std::to_string(e) + separator;

  if (!output.empty())
    output.pop_back();

  return output;
}

bool set_deque::is_subset(set_deque other) {
  for (const auto &e : other.m_deque)
    if (!contains(e))
      return false;
  return true;
}

bool set_deque::is_equal(set_deque other) { return m_deque == other.m_deque; }

set_deque set_deque::set_union(set_deque other) {
  set_deque output;

  for (const auto &e : m_deque)
    output.insert(e);

  for (const auto &e : other.m_deque)
    output.insert(e);

  return output;
}

set_deque set_deque::set_intersection(set_deque other) {
  set_deque output;

  for (const auto &e : other.m_deque)
    if (contains(e))
      output.insert(e);

  return output;
}

set_deque set_deque::set_difference(set_deque other) {
  set_deque output;

  for (const auto &e : other.m_deque)
    if (!contains(e))
      output.insert(e);

  return output;
}

set_deque set_deque::set_symmetric_difference(set_deque other) {
  return set_intersection(other).set_difference(set_union(other));
}
