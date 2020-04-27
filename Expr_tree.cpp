//
// Created by Win10Pro on 24.04.2020.
//

#include "Expr_tree.h"

Expr_tree::Expr_tree() {

    this->root = nullptr;

}

std::vector<int> Expr_tree::get_path(Expr_tree::Node *node) {

    std::vector <int> path = {};
    while(node != root){
        path.emplace(path.begin(), node->key);
        node = node->father;
    }
    return path;

}

Expr_tree::Node *Expr_tree::get_key(std::vector<int> &path) {

    Node* res = root;
    for(int i = 0; i < path.size(); i++){
        if(path[i])
            res = res->right;
        else
            res = res->left;
    }
    return res;

}

void Expr_tree::print_all_tree() {

    if(root == nullptr){
        std::cout<<"Tree is empty, nothing to print\n";
        return;
    }
    print_node(root);

}

void Expr_tree::print_node(Expr_tree::Node *node) {

    if(node == nullptr)
        return;
    std::vector <int> path = get_path(node);
    std::cout<<"Element value\t"<<node->value<<"\t";
        std::cout<<"\t";
    std::cout<<"Path to it:";

    if(node == root){
        std::cout<<" root - no path\n";
    }
    else {        for (int i = 0; i < path.size(); i++){
            std::cout<<"\t"<<path[i];
        }
        std::cout<<std::endl;
    }

    print_node(node->left);
    print_node(node->right);

}
