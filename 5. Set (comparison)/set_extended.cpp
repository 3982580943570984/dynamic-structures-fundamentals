#include "./set_extended.hpp"

// F1
node_ *createEmptySet() { return nullptr; }

// F2
bool isEmpty(node_ *head) { return (head == nullptr); }

// F3
bool isContained(node_ *head, int value) {
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
node_ *append(node_ *head, int value) {
  if (!isContained(head, value))
    return new node_{value, head};
  return head;
}

// F5
node_ *createSet(int amount, int min, int max, bool type) {
  if (max - min < amount || min > max)
    return nullptr;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max);

  node_ *list = createEmptySet();
  std::int32_t count = 0;
  while (count < amount) {
    std::int32_t value = distr(gen);
    type ? value -= value % 3 : value -= value % 9;
    node_ *comp = list;
    list = append(list, value);
    if (comp != list)
      ++count;
  }
  return list;
}

// F6
int cardinality(node_ *head) {
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
std::string toString(node_ *head, char separator) {
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
node_ *deleteSet(node_ *head) {
  while (head != nullptr) {
    delete head;
    head = head->next;
  }
  return head;
}

// F9
bool isSubset(node_ *subset, node_ *set) {
  // std::vector<std::int32_t> sortedSet;
  // node_ *iter = set;
  // while (iter != nullptr) {
  //   sortedSet.push_back(iter->value);
  //   iter = iter->next;
  // }
  // std::sort(sortedSet.begin(), sortedSet.end());

  auto iter = subset;
  while (iter != nullptr) {
    if (!isContained(set, iter->value))
      return false;
    iter = iter->next;
  }

  return true;
}

// F10
bool isEqual(node_ *first, node_ *second) {
  if (cardinality(first) == cardinality(second) && isSubset(first, second))
    return true;
  return false;
}

// F11
node_ *makeUnion(node_ *first, node_ *second) {
  node_ *output = createEmptySet();
  if (!isEmpty(first)) {
    node_ *iter = first;
    while (iter != nullptr) {
      output = append(output, iter->value);
      iter = iter->next;
    }
  }

  if (!isEmpty(second)) {
    node_ *iter = second;
    while (iter != nullptr) {
      output = append(output, iter->value);
      iter = iter->next;
    }
  }

  return output;
}

// F12
node_ *makeIntersection(node_ *first, node_ *second) {
  node_ *output = createEmptySet();

  // std::vector<std::int32_t> sortedSecond;
  // node_ *iter = second;
  // while (iter != nullptr) {
  //   sortedSecond.push_back(iter->value);
  //   iter = iter->next;
  // }
  // std::sort(sortedSecond.begin(), sortedSecond.end());

  auto iter = second;
  while (iter != nullptr) {
    if (isContained(first, iter->value))
      output = append(output, iter->value);
    iter = iter->next;
  }

  return output;
}

// F13
node_ *makeComplement(node_ *first, node_ *second) {
  node_ *output = createEmptySet();

  // std::vector<std::int32_t> sortedSecond;
  // node_ *iter = second;
  // while (iter != nullptr) {
  //   sortedSecond.push_back(iter->value);
  //   iter = iter->next;
  // }
  // std::sort(sortedSecond.begin(), sortedSecond.end());

  auto iter = second;
  while (iter != nullptr) {
    if (!isContained(first, iter->value))
      output = append(output, iter->value);
    iter = iter->next;
  }

  return output;
}

// F14
node_ *makeSymmetricDifference(node_ *first, node_ *second) {
  return makeComplement(makeUnion(first, second),
                        makeIntersection(first, second));
}