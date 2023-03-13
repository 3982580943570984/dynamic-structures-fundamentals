#include "set.hpp"

// F1
set::set(){};

// F8
set::~set() {
  auto iter = head;
  while (iter != nullptr) {
    head = iter->next;
    delete iter;
    iter = head;
  }
};

// F2
bool set::empty() { return head == nullptr; };

// F3
bool set::contains(int value) {
  if (!empty()) {
    auto iter = head;
    while (iter != nullptr) {
      if (iter->value == value)
        return true;
      iter = iter->next;
    }
  }
  return false;
};

// F4
bool set::insert(int value) {
  if (!contains(value)) {
    head = new node{value, head};
    return true;
  }
  return false;
};

// F5
void set::generate(int amount, int min, int max, int mod) {
  if (max - min < amount || min > max)
    return;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max);

  auto iter = head;
  while (iter != nullptr) {
    head = iter->next;
    delete iter;
    iter = head;
  }

  auto count = 0;
  while (count < amount) {
    auto value = distr(gen);
    value -= value % mod;
    if (insert(value))
      ++count;
  }
};

// F6
int set::cardinality() {
  int count = 0;
  auto iter = head;
  while (iter != nullptr) {
    ++count;
    iter = iter->next;
  }
  return count;
};

// F7
std::string set::to_string(char separator) {
  std::string output;

  auto iter = head;
  while (iter != nullptr) {
    output += std::to_string(iter->value) + separator;
    iter = iter->next;
  }

  if (!output.empty())
    output.pop_back();

  return output;
};

// F9
bool set::is_subset(set *other) {
  std::vector<int> sorted;

  auto iter = other->head;
  while (iter != nullptr) {
    sorted.push_back(iter->value);
    iter = iter->next;
  }

  std::sort(sorted.begin(), sorted.end());

  iter = head;
  while (iter != nullptr) {
    if (!std::binary_search(sorted.cbegin(), sorted.cend(), iter->value))
      return false;
    iter = iter->next;
  }

  return true;
};

// F10
bool set::is_equal(set *other) {
  if (cardinality() == other->cardinality() && is_subset(other))
    return true;
  return false;
};

// F11
set *set::make_union(set *other) {
  auto output = new set{};

  auto iter = this->head;
  while (iter != nullptr) {
    output->insert(iter->value);
    iter = iter->next;
  }

  iter = other->head;
  while (iter != nullptr) {
    output->insert(iter->value);
    iter = iter->next;
  }

  return output;
};

// F12
set *set::make_intersection(set *other) {
  auto output = new set{};

  std::vector<int> sorted;

  auto iter = other->head;
  while (iter != nullptr) {
    sorted.push_back(iter->value);
    iter = iter->next;
  }

  std::sort(sorted.begin(), sorted.end());

  iter = head;
  while (iter != nullptr) {
    if (std::binary_search(sorted.cbegin(), sorted.cend(), iter->value))
      output->insert(iter->value);
    iter = iter->next;
  }

  return output;
};

// F13
set *set::make_complement(set *other) {
  auto output = new set{};

  std::vector<int> sorted;

  auto iter = other->head;
  while (iter != nullptr) {
    sorted.push_back(iter->value);
    iter = iter->next;
  }

  std::sort(sorted.begin(), sorted.end());

  iter = head;
  while (iter != nullptr) {
    if (!std::binary_search(sorted.cbegin(), sorted.cend(), iter->value))
      output->insert(iter->value);
    iter = iter->next;
  }

  return output;
};

// F14
set *set::make_symmetricDifference(set *other) {
  auto _union = make_union(other);
  auto _intersection = make_intersection(other);
  auto _difference = _union->make_complement(_intersection);

  delete _union;
  delete _intersection;

  return _difference;
};