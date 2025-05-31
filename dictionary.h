#ifndef DICTIONARY_H
#define DICTIONARY_H

class Dictionary {
public:
    virtual void insert(int key, int value) = 0;
    virtual void remove(int key) = 0;
    virtual bool find(int key, int& value) = 0;
    virtual void clear() = 0;
    virtual ~Dictionary() {};
};

#endif