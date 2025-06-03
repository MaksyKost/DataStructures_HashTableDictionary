#include "dictionary_heap.h"
#include <cstdlib>
#include <ctime>

DictionaryHeap::DictionaryHeap(int size) : size(size) {
    table = new HeapBucket[size];
}

int DictionaryHeap::hash(int key) const {
    return (key % size + size) % size;
}

void DictionaryHeap::insert(int key, int value) {
    int h = hash(key);
    table[h].heap.insert(key, value);
}

bool DictionaryHeap::find(int key, int& value) {
    int h = hash(key);
    return table[h].heap.find(key, value);
}

void DictionaryHeap::remove(int key) {
    int h = hash(key);
    table[h].heap.remove(key);
}

void DictionaryHeap::clear() {
    for (int i = 0; i < size; ++i)
        table[i].heap.clear();
    delete[] table;
    table = new HeapBucket[size];
}

DictionaryHeap::~DictionaryHeap() {
    clear();
}

void DictionaryHeap::fillRandom(int count, int keyMin, int keyMax, int valueMin, int valueMax) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int i = 0; i < count; ++i) {
        int key = keyMin + std::rand() % (keyMax - keyMin + 1);
        int value = valueMin + std::rand() % (valueMax - valueMin + 1);
        insert(key, value);
    }
}