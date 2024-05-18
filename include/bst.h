// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>

template <typename T>
class BST {
 private:
    struct Node {
        T word;
        int count;
        Node* left, * right;
    };
    Node* root = nullptr;
    Node* addNodeTree(Node*, const T&);
    int searchNodeTree(Node*, const T&);
    int getDepthTree(Node*);
 public:
    void addNode(const T&);
    int search(const T&);
    int depth();
};


template<class T>
typename BST<T>::Node* BST<T>::addNodeTree(Node* root, const T& word_) {
    if (root == nullptr) {
        root = new Node;
        root->word = word_;
        root->count = 1;
        root->left = root->right = nullptr;
    } else if (root->word > word_) {
        root->left = addNodeTree(root->left, word_);
    } else if (root->word < word_) {
        root->right = addNodeTree(root->right, word_);
    } else {
        root->count++;
    }
    return root;
}

template<class T>
void BST<T>::addNode(const T& word_) {
    root = addNodeTree(root, word_);
}

template<class T>
int BST<T>::searchNodeTree(Node* root, const T& word_) {
    if (root == nullptr) {
        return 0;
    } else if (root->word > word_) {
        return searchNodeTree(root->left, word_);
    } else if (root->word < word_) {
        return searchNodeTree(root->right, word_);
    } else {
        return root->count;
    }
    return 0;
}

template<class T>
int BST<T>::search(const T& word_) {
    return searchNodeTree(root, word_);
}

template<class T>
int BST<T>::getDepthTree(Node* root) {
    if (root == nullptr)
        return 0;
    int leftDepth = getDepthTree(root->left);
    int rightDepth = getDepthTree(root->right);
    if (leftDepth > rightDepth)
        return leftDepth + 1;
    else
        return rightDepth + 1;
}

template<class T>
int BST<T>::depth() {
    return getDepthTree(root) - 1;
}
#endif  // INCLUDE_BST_H_
