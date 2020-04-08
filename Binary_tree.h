//
// Created by Win10Pro on 08.04.2020.
//

#ifndef LAB_4_TREES__BINARY_TREE_H
#define LAB_4_TREES__BINARY_TREE_H

#include <iostream>
#include <vector>


class Binary_tree {

private:

    class Node{

    public:
        int value;
        Node* left;
        Node* right;
        Node* father;
        int key;
        int count;

        Node(int& value, int& key){
            this->value = value;
            this->key = key;
            this->right = nullptr;
            this->left = nullptr;
            this->father = nullptr;
            count = 1;
        }
    };

public:

    Node* root;
    Binary_tree();

    //Auxiliary

    std::vector <int> get_path(Node* node);
    Node* get_key(std::vector <int> &path);

    //Insert

    void insert(int& value);
    Node* insert(Node* node, int& value, int key);

    //Printing

    void print_all_tree();
    void print_node(Node* node);

    //Delete

    Binary_tree* delete_element(std::vector <int> &path);






};


#endif //LAB_4_TREES__BINARY_TREE_H
