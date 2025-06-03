#ifndef DICTIONARY_HEAP_H
#define DICTIONARY_HEAP_H
#include "heap.h"
#include "dictionary.h"

struct HeapBucket {
    Heap heap;
};

class DictionaryHeap : public Dictionary {
private:
    HeapBucket* table;
    int size;
    int hash(int key) const;
public:
    explicit DictionaryHeap(int size = 10);
    ~DictionaryHeap() override;
    void insert(int key, int value) override;
    bool find(int key, int& value) override;
    void remove(int key) override;
    void clear() override;
    void fillRandom(int count, int keyMin, int keyMax, int valueMin, int valueMax);
    int getSize() const { return size; }
    const HeapBucket& getBucket(int idx) const { return table[idx]; }
};

#endif