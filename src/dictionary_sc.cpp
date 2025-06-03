#include "dictionary_sc.h"
#include <algorithm>   // std::fill_n

DictionarySC::DictionarySC(int capacity) : capacity(capacity)
{
    table = new Node*[capacity];
    std::fill_n(table, capacity, nullptr);
}

DictionarySC::~DictionarySC() {
    clear();
    delete[] table;
}

void DictionarySC::insert(int key, int value) {
    int idx = hash(key);
    Node* cur = table[idx];

    // czy istnieje już węzeł z tym kluczem?
    for (; cur; cur = cur->next) {
        if (cur->key == key) {
            cur->value = value;  // nadpisz wartość
            return;
        }
    }

    // jeśli nie, dołóż nowy na początek listy
    table[idx] = new Node(key, value, table[idx]);
}

void DictionarySC::remove(int key) {
    int idx = hash(key);
    Node* cur = table[idx];
    Node* prev = nullptr;

    while (cur) {
        if (cur->key == key) {
            // wypięcie z listy
            if (prev) prev->next = cur->next;
            else      table[idx] = cur->next;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

bool DictionarySC::find(int key, int &value) {
    int idx = hash(key);
    for (Node* cur = table[idx]; cur; cur = cur->next) {
        if (cur->key == key) {
            value = cur->value;
            return true;
        }
    }
    return false;
}

void DictionarySC::clear() {
    for (int i = 0; i < capacity; ++i) {
        Node* cur = table[i];
        while (cur) {
            Node* next = cur->next;
            delete cur;
            cur = next;
        }
        table[i] = nullptr;
    }
}