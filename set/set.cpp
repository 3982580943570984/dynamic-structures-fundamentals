#include <string>
#include <random>

struct node {
    int value = 0;
    node* next = nullptr;
};

/**
 * Sum numbers in a vector.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
node* createEmptySet() {
    return nullptr;
}

/**
 * Sum numbers in a vector.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
bool isEmpty(node* head) {
    return (head == nullptr);
}

/**
 * Sum numbers in a vector.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
bool isContained(node* head, int value) {
    if (!isEmpty(head)) {
        while (head != nullptr) {
            if (head->value == value)
                return true;
            head = head->next;
        }
    }
    return false;
}

/**
 * Sum numbers in a vector.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
node* append(node* head, int value) {
    if (!isContained(head, value))
        return new node{ value, head };
    return head;
}

node* createSet(int amount, int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);

    node* list = createEmptySet();
    for (int i = 0; i < amount; i++)
        list = append(list, distr(gen));
    return list;
}

/**
 * Sum numbers in a vector.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
int cardinality(node* head) {
    if (int count = 0; !isEmpty(head)) {
        while (head != nullptr) {
            head = head->next;
            ++count;
        }
        return count;
    }
    return 0;
}

/**
 * Sum numbers in a vector.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
std::string toString(node* head, char separator) {
    if (!isEmpty(head)) {
        std::string output;
        while (head != nullptr) {
            head->next == nullptr
                ? output += std::to_string(head->value)
                : output += std::to_string(head->value) + separator;
            head = head->next;
        }
        return output;
    }
    return "";
}

/**
 * Sum numbers in a vector.
 *
 * @param values Container whose values are summed.
 * @return sum of `values`, or 0.0 if `values` is empty.
 */
node* deleteSet(node* head) {
    while (head != nullptr) {
        delete head;
        head = head->next;
    }
    return head;
}