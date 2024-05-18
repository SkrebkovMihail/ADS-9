// Copyright 2021 NNTU-CS
// bst.h
#ifndef BST_H
#define BST_H

#include <string>


template<typename T>
struct Node {
    T data;
    int count;
    Node* left;
    Node* right;


    Node(const T& value) : data(value), count(1), left(nullptr), right(nullptr) {}
};


template<typename T>
class BST {
private:
    Node<T>* root;


    void destroyTree(Node<T>* node);
    Node<T>* insert(Node<T>* node, const T& value);
    void inOrderTraversal(Node<T>* node, std::ostream& os) const;

public:

    BST();
    ~BST();


    void insert(const T& value);
    void printInOrder(std::ostream& os) const;
};

#include "alg.cpp"

#endif // BST_H
