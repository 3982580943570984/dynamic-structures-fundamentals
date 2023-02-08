#include <iostream>
#include "./set.cpp"

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(6, 9);

    // F5
    node* head = createSet(distr(gen), 0, 100);
    std::cout << "Создано множество А: " << toString(head, ',') << std::endl;

    // F6
    std::cout << "Мощность множества A:" << cardinality(head) << std::endl;

    // F7
    std::cout << "Вывод множество А: " << toString(head, ',') << std::endl;

    // F8
    std::cout << "Удаление множества A: " << std::endl;
    head = deleteSet(head);

    std::cout << "Мощность множества A:" << cardinality(head) << std::endl;
    std::cout << "Вывод множество А: " << toString(head, ',') << std::endl;

    return 0;
}