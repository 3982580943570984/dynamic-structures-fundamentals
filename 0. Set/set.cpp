#include "./set.hpp"

node *createEmptySet() { return nullptr; }

bool isEmpty(node *head) { return (head == nullptr); }

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

node *append(node *head, int value) {
  if (!isContained(head, value))
    return new node{value, head};
  return head;
}

node *createSet(int amount, int min, int max) {
  if (min > max)
    return nullptr;

  if (max - min < amount)
    return nullptr;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(min, max);

  node *list = createEmptySet();
  for (int i = 0; i < amount; i++)
    list = append(list, distr(gen));
  return list;
}

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

node *deleteSet(node *head) {
  while (head != nullptr) {
    delete head;
    head = head->next;
  }
  return head;
}
