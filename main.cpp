#include <iostream>
#include "src/heap.h"

int main() {
    Heap heap;

    // Вставка элементов
    heap.insert(5, 100);
    heap.insert(2, 200);
    heap.insert(8, 300);
    heap.insert(1, 400);

    std::cout << "Heap after insertions:\n";
    for (const auto& node : heap.getData()) {
        std::cout << "key: " << node.key << ", value: " << node.value << std::endl;
    }

    // find
    int value;
    if (heap.find(2, value))
        std::cout << "Found key 2, value = " << value << std::endl;
    else
        std::cout << "Key 2 not found\n";

    // remove
    heap.remove(2);
    std::cout << "Heap after removing key 2:\n";
    for (const auto& node : heap.getData()) {
        std::cout << "key: " << node.key << ", value: " << node.value << std::endl;
    }

    heap.clear();
    std::cout << "Heap after clear, size = " << heap.getData().size() << std::endl;

    return 0;
}
