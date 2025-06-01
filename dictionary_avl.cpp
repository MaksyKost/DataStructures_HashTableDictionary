#include <iostream>
#include "avl_tree.h"
#include "dictionary_avl.h"

DictionaryAVL::DictionaryAVL(int size) : size(size) {
    table = new Bucket[size]; 
}

int DictionaryAVL::hash(int key) const {
    return (key % size + size) % size;
}

void DictionaryAVL::insert(int key, int value) {
    int h = hash(key);
    table[h].tree.insert(key, value);
}

bool DictionaryAVL::find(int key, int &value) {
    int h = hash(key);
    return table[h].tree.find(key, value);
}

void DictionaryAVL::remove(int key) {
    int h = hash(key);
    table[h].tree.remove(key);
}

void DictionaryAVL::clear() {
    for (int i = 0; i < size; i++) {
        table[i].tree.clear();
    }
    delete[] table;
    table = new Bucket[size];
}

DictionaryAVL::~DictionaryAVL() {
    clear();
}