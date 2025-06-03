#include "heap.h"

Heap::Heap() {}

void Heap::heapifyUp(int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (data[idx].key >= data[parent].key) break;
        std::swap(data[idx], data[parent]);
        idx = parent;
    }
}

void Heap::heapifyDown(int idx) {
    int n = data.size();
    while (true) {
        int left = 2 * idx + 1, right = 2 * idx + 2, smallest = idx;
        if (left < n && data[left].key < data[smallest].key) smallest = left;
        if (right < n && data[right].key < data[smallest].key) smallest = right;
        if (smallest == idx) break;
        std::swap(data[idx], data[smallest]);
        idx = smallest;
    }
}

int Heap::findIndex(int key) const {
    for (int i = 0; i < (int)data.size(); ++i)
        if (data[i].key == key) return i;
    return -1;
}

void Heap::insert(int key, int value) {
    data.push_back(HeapNode(key, value));
    heapifyUp(data.size() - 1);
}

bool Heap::find(int key, int& value) const {
    int idx = findIndex(key);
    if (idx == -1) return false;
    value = data[idx].value;
    return true;
}

void Heap::remove(int key) {
    int idx = findIndex(key);
    if (idx == -1) return;
    data[idx] = data.back();
    data.pop_back();
    if (idx < (int)data.size()) {
        heapifyUp(idx);
        heapifyDown(idx);
    }
}

void Heap::clear() {
    data.clear();
}