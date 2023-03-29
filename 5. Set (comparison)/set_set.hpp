#include <random>
#include <set>
#include <string>

class set_set {
public:
  std::set<int> m_set;

  // F1
  set_set();
  // F8
  ~set_set();

  // F2
  bool empty();
  // F3
  bool contains(int value);
  // F4
  bool insert(int value);
  // F5
  void generate(int amount, int min, int max, int mod = 3);
  // F6
  int cardinality();
  // F7
  std::string to_string(char separator = ' ');
  // F9
  bool is_subset(set_set other);
  // F10
  bool is_equal(set_set other);
  // F11
  set_set set_union(set_set other);
  // F12
  set_set set_intersection(set_set other);
  // F13
  set_set set_difference(set_set other);
  // F14
  set_set set_symmetric_difference(set_set other);
};