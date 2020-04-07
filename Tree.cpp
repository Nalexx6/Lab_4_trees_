//
// Created by Win10Pro on 31.03.2020.
//

#include "Tree.h"



Tree::Tree() {

//        this->tree_limit = tree_limit;
//        this->key_counter = 0;
        this->root = nullptr;
//        root = new Node(key_counter, root_value);
//        key_counter++;

}

std::vector<int> Tree::get_path(Node* node) {

    std::vector <int> path = {};
    while(node != root){
        path.emplace(path.begin(), node->key);
        node = node->father;
    }
    return path;


}

Tree::Node* Tree::get_key(std::vector<int> &path) {

    Node* res = root;
    for(int i = 0; i < path.size(); i++){
        res = res->sons[path[i]];
    }
    return res;

}

void Tree::insert(std::vector<int> &path, int &value) {

    if(root == nullptr){
        unsigned key = 0;
        root = new Node(key, value);
        elements.push_back(root);
        return;

    }
    Node* temp = get_key(path);
    unsigned size = temp->sons.size();
    Node* add = new Node(size, value);
    temp->sons.push_back(add);
    add->father = temp;
    elements.push_back(add);

}

void Tree::print_all_tree() {

    std::cout<<"This printing mode print value of element and path to it by indexes in arrays of sons\n";
    print_node(root);

}

void Tree::print_node(Tree::Node *node) {

    std::vector <int> path = get_path(node);
    std::cout<<"Element\t"<<node->value<<"\tPath to it:";
    if(node == root){
        std::cout<<" root - no path\n";
    }
    else {
        for (int i = 0; i < path.size(); i++){
            std::cout<<"\t"<<path[i];
        }
        std::cout<<std::endl;
    }
    for(int j = 0; j < node->sons.size(); j++){
        print_node(node->sons[j]);
    }

}
