#ifndef DICTIONARY_AVL_H
#define DICTIONARY_AVL_H

#include "dictionary.h"
#include "avl_tree.h"

struct Bucket {
    AVLTree tree;
};

class DictionaryAVL : public Dictionary {
private:
    Bucket *table;
    int size;
    int hash(int key) const;

public:
    DictionaryAVL(int size = 10);
    ~DictionaryAVL();

    const Bucket& getBucket(int index) const { return table[index]; }
    int getSize() const { return size; }
    void insert(int key, int value) override;
    void remove(int key) override;
    bool find(int key, int &value) override;
    void clear() override;
    void fillRandom(int count, int keyMin,int keyMax, int valueMin, int valueMax);
};

#endif