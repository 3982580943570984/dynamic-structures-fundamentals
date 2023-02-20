#include "./set.hpp"
#include <iostream>

std::int32_t main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distr(6, 9);

  node *head1 = createEmptySet();
  node *head2 = createEmptySet();
  std::cout << isSubset(head1, head2) << std::endl;
  std::cout << makeIntersection(head1, head2) << std::endl;

  //   node *head1 = createEmptySet();
  //   head1 = append(head1, 0);
  //   head1 = append(head1, 1);
  //   head1 = append(head1, 2);
  //   head1 = append(head1, 3);
  //   node *head2 = createEmptySet();
  //   head2 = append(head2, 0);
  //   head2 = append(head2, 1);
  //   head2 = append(head2, 2);

  //   std::cout << "head1: " << toString(head1, ',') << std::endl;
  //   std::cout << "head2: " << toString(head2, ',') << std::endl;
  //   std::cout << "is head1 subset head2: " << isSubset(head1, head2) <<
  //   std::endl; std::cout << "is head1 equal head2: " << isEqual(head1, head2)
  //   << std::endl;

  //   auto head3 = makeUnion(head1, head2);
  //   std::cout << "head3: " << toString(head3, ',') << std::endl;
  //   auto head4 = makeIntersection(head1, head2);
  //   std::cout << "head4: " << toString(head4, ',') << std::endl;
  //   auto head5 = makeComplement(head1, head2);
  //   std::cout << "head5: " << toString(head5, ',') << std::endl;

  //   head1 = createEmptySet();
  //   head1 = append(head1, 0);
  //   head1 = append(head1, 1);
  //   head1 = append(head1, 2);
  //   head1 = append(head1, 3);
  //   head2 = createEmptySet();
  //   head2 = append(head2, 0);
  //   head2 = append(head2, 1);
  //   head2 = append(head2, 2);
  //   head2 = append(head2, 5);

  //   auto head6 = makeSymmetricDifference(head1, head2);
  //   std::cout << "head6: " << toString(head6, ',') << std::endl;

  return 0;
}
