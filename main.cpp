#include <iostream>
#include "src/dictionary_avl.h"

int main() {
    DictionaryAVL dict(5);

    
    dict.insert(10, 100);
    dict.insert(15, 150);
    dict.insert(20, 200);
    dict.insert(25, 250);
    dict.insert(30, 300);

    int value;
    if (dict.find(10, value))
        std::cout << "Key 10 found, value = " << value << std::endl;
    else
        std::cout << "Key 10 not found" << std::endl;

    if (dict.find(15, value))
        std::cout << "Key 15 found, value = " << value << std::endl;
    else
        std::cout << "Key 15 not found" << std::endl;

    if (dict.find(99, value))
        std::cout << "Key 99 found, value = " << value << std::endl;
    else
        std::cout << "Key 99 not found" << std::endl;

    dict.remove(15);
    if (dict.find(15, value))
        std::cout << "Key 15 found after removal, value = " << value << std::endl;
    else
        std::cout << "Key 15 not found after removal" << std::endl;

    dict.clear();
    if (dict.find(10, value))
        std::cout << "Key 10 found after clear, value = " << value << std::endl;
    else
        std::cout << "Key 10 not found after clear" << std::endl;

    return 0;
}
