#ifndef AVL_TREE_H
#define AVL_TREE_H

struct AVLNode {
    int key;
    int value;
    int height;
    AVLNode* left;
    AVLNode* right;
    AVLNode(int a, int b);
};

class AVLTree {
private:
    AVLNode* root;
    
    AVLNode* insert(AVLNode *node, int key, int value);
    AVLNode* remove(AVLNode *node, int key);
    bool find(AVLNode *node, int key, int& value) const;
    int height(AVLNode* node);
    int balanceFactor(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* y);
    AVLNode* rotateRight(AVLNode* x);
    AVLNode* minValueNode(AVLNode* node);
    AVLNode* balance(AVLNode* node);

public:
    AVLTree();
    ~AVLTree();
    void insert(int key, int value);
    void remove(int key);
    bool find(int key, int &value) const;
    void clear();
};

#endif