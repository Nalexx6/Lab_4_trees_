//
// Created by Win10Pro on 08.04.2020.
//

#ifndef LAB_4_TREES__BINARY_TREE_H
#define LAB_4_TREES__BINARY_TREE_H

#include <iostream>
#include <vector>
#include <string>

class Binary_tree {

private:

    class Node{

    public:
        int value;
        Node* left;
        Node* right;
        Node* father;
        bool li, ri;
        int key;
        int count;

        Node(int& value, int& key){
            this->value = value;
            this->key = key;
            this->right = nullptr;
            this->left = nullptr;
            this->father = nullptr;
            this->li = true;
            this->ri = true;
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

    void print_all_tree(bool threaded);
    void print_node(Node* node, bool threaded);

    //Delete

    Binary_tree* delete_element(std::vector <int> &path);

    //Threading

    void thread_tree();
    void thread_node(Node* node);
    void unthread_tree();
    void unthread_node(Node* node);

};


#endif //LAB_4_TREES__BINARY_TREE_H
