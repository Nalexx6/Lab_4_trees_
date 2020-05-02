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
    Node* root;
public:


    Tree();

    //Auxiliary

    std::vector <int> get_path(Node* node);
    Node* get_key(std::vector <int> &path);

    //Insert
    void insert(std::vector <int> &path, int &value);

    //Printing


    void print_all_tree();
    void print_node(Node* node);

    //Delete

    Tree* delete_element(std::vector <int> &path);





};


#endif //LAB_4_TREES__TREE_H
