//
// Created by Win10Pro on 31.03.2020.
//

#ifndef LAB_4_TREES__TREE_H
#define LAB_4_TREES__TREE_H

#include <iostream>
#include <vector>


class Tree {

    class Node{
    public:
        int value;
        unsigned key;
        Node* father;
        //Node* sons;
        std::vector <Node*> sons;


        Node(unsigned& key, int& value){
            this->value = value;
            this->key = key;
            sons = {};
        }

    };
//    static int tree_limit;
//    unsigned key_counter;
    Node* root;
public:

    std::vector<Node*> elements;

    Tree();

    //Add elements

    std::vector <int> get_path(Node* node);
    Node* get_key(std::vector <int> &path);
    void insert(std::vector <int> &path, int &value);

    void print_all_tree();
    void print_node(Node* node);






};


#endif //LAB_4_TREES__TREE_H
