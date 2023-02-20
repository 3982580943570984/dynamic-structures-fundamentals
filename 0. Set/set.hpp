#pragma once

#include <iostream>
#include <random>
#include <string>

struct node {
  int value = 0;
  node *next = nullptr;
};

node *createEmptySet();
bool isEmpty(node *head);
bool isContained(node *head, int value);
node *append(node *head, int value);
node *createSet(int amount, int min, int max);
int cardinality(node *head);
std::string toString(node *head, char separator);
node *deleteSet(node *head);