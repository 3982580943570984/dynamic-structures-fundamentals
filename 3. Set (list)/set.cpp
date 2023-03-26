#include <algorithm>
#include <iterator>
#include <random>

#include "set.hpp"

Set::Set() {}

Set::~Set() {}

bool Set::empty() { return list.empty(); }

bool Set::contains(int value) { return std::ranges::contains(list, value); }

bool Set::insert(int value) {
  if (contains(value))
    return false;

  auto iter = std::lower_bound(list.begin(), list.end(), value);
  list.insert(iter, value);
  return true;
}

void Set::generate(int amount, int min, int max, int mod) {
  if (max - min < amount || min > max)
    return;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max);

  list.clear();

  while (cardinality() < amount) {
    auto value = distr(gen);
    value -= value % mod;
    insert(value);
  }
}

int Set::cardinality() { return list.size(); }

std::string Set::to_string(char separator) {
  std::string output;

  for (const auto &e : list)
    output += std::to_string(e) + separator;

  if (!output.empty())
    output.pop_back();

  return output;
}

bool Set::is_subset(Set other) {
  return std::ranges::includes(list, other.list);
}

bool Set::is_equal(Set other) { return list == other.list; }

Set Set::set_union(Set other) {
  Set output;
  std::ranges::set_union(list, other.list, std::back_inserter(output.list));
  return output;
}

Set Set::set_intersection(Set other) {
  Set output;
  std::ranges::set_intersection(list, other.list,
                                std::back_inserter(output.list));
  return output;
}

Set Set::set_difference(Set other) {
  Set output;
  std::ranges::set_difference(list, other.list,
                              std::back_inserter(output.list));
  return output;
}

Set Set::set_symmetric_difference(Set other) {
  Set output;
  std::ranges::set_symmetric_difference(list, other.list,
                                        std::back_inserter(output.list));
  return output;
}
