#include <iostream>
#include "./set.h"

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(6, 9);

    // F5
    node* head = createSet(distr(gen), 0, 100);
    std::cout << "Created set A: " << toString(head, ',') << std::endl;

    // F6
    std::cout << "Set cardinality A:" << cardinality(head) << std::endl;

    // F7
    std::cout << "Output set A: " << toString(head, ',') << std::endl;

    // F8
    std::cout << "Delete set A: " << std::endl;
    head = deleteSet(head);

    std::cout << "Set cardinality A:" << cardinality(head) << std::endl;
    std::cout << "Output set A: " << toString(head, ',') << std::endl;

    return 0;
}
