// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
    std::ifstream file(filename);
    BST<std::string> tree;
    std::string word;

    if (file) {
        while (!file.eof()) {
            word.erase();
            while (1) {
                char symbol = file.get();
                if (symbol > 96 && symbol < 123) {
                    word += symbol;
                } else if (symbol > 64 && symbol < 91) {
                    symbol += 32;
                    word += symbol;
                } else {
                    break;
                }
            }
            if (!word.empty()) {
                tree.addNode(word);
            } else {
                continue;
            }
        }
        file.close();
    } else {
        std::cout << "File was not read correctly." << std::endl;
    }
    return tree;
}
