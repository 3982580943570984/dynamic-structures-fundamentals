#pragma once

#include <iostream>
#include <random>
#include <string>

struct node_ {
  int value = 0;
  node_ *next = nullptr;
};

// F1
node_ *createEmptySet();
// F2
bool isEmpty(node_ *head);
// F3
bool isContained(node_ *head, int value);
// F4
node_ *append(node_ *head, int value);
// F5
node_ *createSet(int amount, int min, int max, bool type = false);
// F6
int cardinality(node_ *head);
// F7
std::string toString(node_ *head, char separator);
// F8
node_ *deleteSet(node_ *head);
// F9
bool isSubset(node_ *subset, node_ *set);
// F10
bool isEqual(node_ *first, node_ *second);
// F11
node_ *makeUnion(node_ *first, node_ *second);
// F12
node_ *makeIntersection(node_ *first, node_ *second);
// F13
node_ *makeComplement(node_ *first, node_ *second);
// F14
node_ *makeSymmetricDifference(node_ *first, node_ *second);