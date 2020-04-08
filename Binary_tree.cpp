//
// Created by Win10Pro on 08.04.2020.
//

#include "Binary_tree.h"

Binary_tree::Binary_tree() {

    this->root = nullptr;

}

std::vector<int> Binary_tree::get_path(Binary_tree::Node *node) {

std::vector <int> path = {};
    while(node != root){
        path.emplace(path.begin(), node->key);
        node = node->father;
    }
    return path;

}

Binary_tree::Node *Binary_tree::get_key(std::vector<int> &path) {

    Node* res = root;
    for(int i = 0; i < path.size(); i++){
        if(path[i])
            res = res->right;
        else
            res = res->left;
    }
    return res;

}

void Binary_tree::insert(int &value) {

    root = insert(root, value, 0);

}

Binary_tree::Node *Binary_tree::insert(Binary_tree::Node *node, int &value, int key) {

    if(node == nullptr)
        return new Node(value, key);
    if(value < node->value){
        node->left = insert(node->left, value, 0);
        node->left->father = node;
    }
    if(value > node->value){
        node->right = insert(node->right, value, 1);
        node->right->father = node;
    }
    if(value == node->value){
        node->count++;
    }
    return node;
}

void Binary_tree::print_all_tree() {

    if(root == nullptr){
        std::cout<<"Tree is empty, nothing to print\n";
        return;
    }
    std::cout<<"This printing mode print value of element and path to it by indexes in arrays of sons\n";
    print_node(root);

}

void Binary_tree::print_node(Binary_tree::Node *node) {

    if(node == nullptr)
        return;
    std::vector <int> path = get_path(node);
    std::cout<<"Element value\t"<<node->value<<"\tPath to it:";
    if(node == root){
        std::cout<<" root - no path\n";
    }
    else {
        for (int i = 0; i < path.size(); i++){
            std::cout<<"\t"<<path[i];
        }
        std::cout<<std::endl;
    }

    print_node(node->left);
    print_node(node->right);

}

Binary_tree *Binary_tree::delete_element(std::vector<int> &path) {

    Node* temp = get_key(path);
    Binary_tree* remainder = new Binary_tree;
    remainder->root = temp;
    if(temp == root){
        root = nullptr;
        return remainder;
    }
    if(temp->key){
        temp->father->right = nullptr;
    } else{
        temp->father->left = nullptr;
    }
    temp->father = nullptr;
    return remainder;

}
