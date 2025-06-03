#ifndef HEAP_H
#define HEAP_H
#include <vector>

struct HeapNode {
    int key;
    int value;
    HeapNode(int k = 0, int v = 0) : key(k), value(v) {}
};

class Heap {
private:
    std::vector<HeapNode> data;
    void heapifyUp(int idx);
    void heapifyDown(int idx);
    int findIndex(int key) const;
public:
    Heap();
    void insert(int key, int value);
    bool find(int key, int& value) const;
    void remove(int key);
    void clear();
    const std::vector<HeapNode>& getData() const { return data; }
};

#endif