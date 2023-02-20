#pragma once

#include <iostream>
#include <random>
#include <string>

struct node {
  int value = 0;
  node *next = nullptr;
};

// F1
node *createEmptySet();
// F2
bool isEmpty(node *head);
// F3
bool isContained(node *head, int value);
// F4
node *append(node *head, int value);
// F5
node *createSet(int amount, int min, int max);
// F6
int cardinality(node *head);
// F7
std::string toString(node *head, char separator);
// F8
node *deleteSet(node *head);
// F9
bool isSubset(node *subset, node *set);
// F10
bool isEqual(node *first, node *second);
// F11
node *makeUnion(node *first, node *second);
// F12
node *makeIntersection(node *first, node *second);
// F13
node *makeComplement(node *first, node *second);
// F14
node *makeSymmetricDifference(node *first, node *second);