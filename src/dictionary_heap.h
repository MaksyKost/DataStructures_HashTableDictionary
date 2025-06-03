#ifndef DICTIONARY_HEAP_H
#define DICTIONARY_HEAP_H
#include "heap.h"

struct HeapBucket {
    Heap heap;
};

class DictionaryHeap {
private:
    HeapBucket* table;
    int size;
    int hash(int key) const;
public:
    DictionaryHeap(int size);
    ~DictionaryHeap();
    void insert(int key, int value);
    bool find(int key, int& value);
    void remove(int key);
    void clear();
    void fillRandom(int count, int keyMin, int keyMax, int valueMin, int valueMax);
    int getSize() const { return size; }
    const HeapBucket& getBucket(int idx) const { return table[idx]; }
};

#endif