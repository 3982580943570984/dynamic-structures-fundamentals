#include "set_class.hpp"

// F1
set_class::set_class() {}

// F8
set_class::~set_class() {
  auto iter = head;
  while (iter != nullptr) {
    head = iter->next;
    delete iter;
    iter = head;
  }
};

// F2
bool set_class::empty() { return head == nullptr; };

// F3
bool set_class::contains(int value) {
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
bool set_class::insert(int value) {
  if (!contains(value)) {
    head = new node{value, head};
    return true;
  }
  return false;
};

// F5
void set_class::generate(int amount, int min, int max, int mod) {
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
int set_class::cardinality() {
  int count = 0;
  auto iter = head;
  while (iter != nullptr) {
    ++count;
    iter = iter->next;
  }
  return count;
};

// F7
std::string set_class::to_string(char separator) {
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
bool set_class::is_subset(set_class *other) {
  // std::vector<int> sorted;

  // auto iter = other->head;
  // while (iter != nullptr) {
  //   sorted.push_back(iter->value);
  //   iter = iter->next;
  // }

  // std::sort(sorted.begin(), sorted.end());

  auto iter = other->head;
  while (iter != nullptr) {
    if (!contains(iter->value))
      return false;
    iter = iter->next;
  }

  return true;
};

// F10
bool set_class::is_equal(set_class *other) {
  if (cardinality() == other->cardinality() && is_subset(other))
    return true;
  return false;
};

// F11
set_class *set_class::make_union(set_class *other) {
  auto output = new set_class{};

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
set_class *set_class::make_intersection(set_class *other) {
  auto output = new set_class{};

  // std::vector<int> sorted;

  // auto iter = other->head;
  // while (iter != nullptr) {
  //   sorted.push_back(iter->value);
  //   iter = iter->next;
  // }

  // std::sort(sorted.begin(), sorted.end());

  auto iter = other->head;
  while (iter != nullptr) {
    if (contains(iter->value))
      output->insert(iter->value);
    iter = iter->next;
  }

  return output;
};

// F13
set_class *set_class::make_complement(set_class *other) {
  auto output = new set_class{};

  // std::vector<int> sorted;

  // auto iter = other->head;
  // while (iter != nullptr) {
  //   sorted.push_back(iter->value);
  //   iter = iter->next;
  // }

  // std::sort(sorted.begin(), sorted.end());

  auto iter = other->head;
  while (iter != nullptr) {
    if (!contains(iter->value))
      output->insert(iter->value);
    iter = iter->next;
  }

  return output;
};

// F14
set_class *set_class::make_symmetricDifference(set_class *other) {
  // auto _union = make_union(other);
  // auto _intersection = make_intersection(other);
  // auto _difference = _union->make_complement(_intersection);

  // delete _union;
  // delete _intersection;

  return make_union(other)->make_complement(make_intersection(other));
};