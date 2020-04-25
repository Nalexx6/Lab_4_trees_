//
// Created by Win10Pro on 24.04.2020.
//

#ifndef LAB_4_TREES__EXPR_TREE_H
#define LAB_4_TREES__EXPR_TREE_H

#include <iostream>
#include <vector>

class Expr_tree {

private:

public:

    class Node{

    public:

        std::string value;
        Node* left;
        Node* right;
        Node* father;
        int key;

        Node(std::string value, int key){
            this->value = value;
            this->key = key;
            this->right = nullptr;
            this->left = nullptr;
            this->father = nullptr;
        }
    };


    Node* root;
    Expr_tree();

    std::vector <int> get_path(Node* node);
    Node* get_key(std::vector <int> &path);

    void print_all_tree();
    void print_node(Node* node);

};


#endif //LAB_4_TREES__EXPR_TREE_H
