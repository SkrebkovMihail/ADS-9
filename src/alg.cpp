// Copyright 2021 NNTU-CS
#include "bst.h"
#include <iostream>
#include <fstream>
#include <cctype>


template<typename T>
BST<T>::BST() : root(nullptr) {}

/
template<typename T>
BST<T>::~BST() {
    destroyTree(root);
}


template<typename T>
void BST<T>::destroyTree(Node<T>* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}


template<typename T>
void BST<T>::insert(const T& value) {
    root = insert(root, value);
}


template<typename T>
Node<T>* BST<T>::insert(Node<T>* node, const T& value) {
    if (node == nullptr) {
        return new Node<T>(value);
    }

    if (value < node->data) {
        node->left = insert(node->left, value);
    } else if (value > node->data) {
        node->right = insert(node->right, value);
    } else {

        node->count++;
    }

    return node;
}


template<typename T>
void BST<T>::inOrderTraversal(Node<T>* node, std::ostream& os) const {
    if (node != nullptr) {
        inOrderTraversal(node->left, os);
        os << node->data << " - " << node->count << std::endl;
        inOrderTraversal(node->right, os);
    }
}


template<typename T>
void BST<T>::printInOrder(std::ostream& os) const {
    inOrderTraversal(root, os);
}


BST<std::string> makeTree(const char* filename) {
    BST<std::string> tree;


    std::ifstream file(filename);


    if (!file) {
        throw std::runtime_error("Error opening file");
    }


    std::string word;
    while (file >> word) {

        for (char& c : word) {
            c = std::tolower(c);
        }

        word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return !std::isalpha(c); }), word.end());

        if (!word.empty()) {
            tree.insert(word);
        }
    }


    file.close();

    return tree;
}