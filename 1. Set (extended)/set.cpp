#include "./set.hpp"

// F1
node *createEmptySet() { return nullptr; }

// F2
bool isEmpty(node *head) { return (head == nullptr); }

// F3
bool isContained(node *head, int value) {
  if (!isEmpty(head)) {
    while (head != nullptr) {
      if (head->value == value)
        return true;
      head = head->next;
    }
  }
  return false;
}

// F4
node *append(node *head, int value) {
  if (!isContained(head, value))
    return new node{value, head};
  return head;
}

// F5
node *createSet(int amount, int min, int max, bool type) {
  if (max - min < amount || min > max)
    return nullptr;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max);

  node *list = createEmptySet();
  std::int32_t count = 0;
  while (count < amount) {
    std::int32_t value = distr(gen);
    type ? value -= value % 3 : value -= value % 9;
    node *comp = list;
    list = append(list, value);
    if (comp != list)
      ++count;
  }
  return list;
}

// F6
int cardinality(node *head) {
  if (int count = 0; !isEmpty(head)) {
    while (head != nullptr) {
      head = head->next;
      ++count;
    }
    return count;
  }
  return 0;
}

// F7
std::string toString(node *head, char separator) {
  if (!isEmpty(head)) {
    std::string output;
    while (head != nullptr) {
      head->next == nullptr ? output += std::to_string(head->value)
                            : output += std::to_string(head->value) + separator;
      head = head->next;
    }
    return output;
  }
  return "";
}

// F8
node *deleteSet(node *head) {
  while (head != nullptr) {
    delete head;
    head = head->next;
  }
  return head;
}

// F9
bool isSubset(node *subset, node *set) {
  std::vector<std::int32_t> sortedSet;
  node *iter = set;
  while (iter != nullptr) {
    sortedSet.push_back(iter->value);
    iter = iter->next;
  }
  std::sort(sortedSet.begin(), sortedSet.end());

  iter = subset;
  while (iter != nullptr) {
    if (!std::binary_search(sortedSet.cbegin(), sortedSet.cend(), iter->value))
      return false;
    iter = iter->next;
  }

  return true;
}

// F10
bool isEqual(node *first, node *second) {
  if (cardinality(first) == cardinality(second) && isSubset(first, second))
    return true;
  return false;
}

// F11
node *makeUnion(node *first, node *second) {
  node *output = createEmptySet();
  if (!isEmpty(first)) {
    node *iter = first;
    while (iter != nullptr) {
      output = append(output, iter->value);
      iter = iter->next;
    }
  }

  if (!isEmpty(second)) {
    node *iter = second;
    while (iter != nullptr) {
      output = append(output, iter->value);
      iter = iter->next;
    }
  }

  return output;
}

// F12
node *makeIntersection(node *first, node *second) {
  node *output = createEmptySet();

  std::vector<std::int32_t> sortedSecond;
  node *iter = second;
  while (iter != nullptr) {
    sortedSecond.push_back(iter->value);
    iter = iter->next;
  }
  std::sort(sortedSecond.begin(), sortedSecond.end());

  iter = first;
  while (iter != nullptr) {
    if (std::binary_search(sortedSecond.cbegin(), sortedSecond.cend(),
                           iter->value))
      output = append(output, iter->value);
    iter = iter->next;
  }

  return output;
}

// F13
node *makeComplement(node *first, node *second) {
  node *output = createEmptySet();

  std::vector<std::int32_t> sortedSecond;
  node *iter = second;
  while (iter != nullptr) {
    sortedSecond.push_back(iter->value);
    iter = iter->next;
  }
  std::sort(sortedSecond.begin(), sortedSecond.end());

  iter = first;
  while (iter != nullptr) {
    if (!std::binary_search(sortedSecond.cbegin(), sortedSecond.cend(),
                            iter->value))
      output = append(output, iter->value);
    iter = iter->next;
  }

  return output;
}

// F14
node *makeSymmetricDifference(node *first, node *second) {
  return makeComplement(makeUnion(first, second),
                        makeIntersection(first, second));
}