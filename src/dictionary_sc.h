#ifndef DICTIONARY_SC_H
#define DICTIONARY_SC_H

#include "dictionary.h"

// węzeł listy pojedynczo wiązanej
struct Node {
    int key;
    int value;
    Node* next;
    Node(int k, int v, Node* n = nullptr) : key(k), value(v), next(n) {}
};

class DictionarySC : public Dictionary {
private:
    Node** table;      // tablica kubełków (wskaźników na Node)
    int capacity;   // liczba kubełków

    // funkcja mieszająca: h(k) = |k| % capacity
    int hash(int key) const {
        int x = key >= 0 ? key : -key;
        return x % capacity;
    }

public:
    // konstruktor tworzy tablicę o zadanej pojemności
    explicit DictionarySC(int capacity = 10);
    // destruktor czyści wszystkie węzły i zwalnia tablicę
    ~DictionarySC() override;

    // wstawia lub nadpisuje parę <key,value>
    void insert(int key, int value) override;
    // usuwa wpis o danym kluczu (jeśli istnieje)
    void remove(int key) override;
    // szuka klucza; jeśli znajdzie, zapisuje value i zwraca true
    bool find(int key, int &value) override;
    // czyści całą strukturę
    void clear() override;
};

#endif // DICTIONARY_SC_H