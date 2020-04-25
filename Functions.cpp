//
// Created by Win10Pro on 31.03.2020.
//

#include "Functions.h"

void Functions::binary_tree_interactive() {

    Binary_tree* tree = new Binary_tree;
    char response = 'y';
    while(response == 'y') {

        std::cout<<"Please choose what you want to do with your tree\n"
                   "1 - Add new element\n"
                   "2 - Print all data from tree\n"
                   "3 - Delete element\n"
                   "4 - Thread tree and print all data from tree,\n"
                   "(after that we will unthread our tree to continue doing something with it)\n";
        int key;
        std::cin>>key;
        if(key == 1){
            int value;
            std::cout<<"Enter value of new element\n";
            std::cin>>value;
            tree->insert(value);

        }
        if(key == 2){
            tree->print_all_tree(false);
        }
        if(key == 3){
            std::cout<<"Enter the path to the element which you want to delete\n"
                       "Enter -1 if you want to end path\n";
            int key = 0;
            std::vector <int> path ={};
            while(key != -1){
                std::cin>>key;
                if(key != -1)
                    path.push_back(key);
            }
            Binary_tree* remainder = tree->delete_element(path);
            std::cout<<"There is remanding tree after deleting\n";
            remainder->print_all_tree(false);
            delete remainder;
        }
        if(key == 4){
            tree->thread_tree();
            tree->print_all_tree(true);
            tree->unthread_tree();

        }

        std::cout<<"If you want to do anything else with your tree, press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }
    delete tree;

}

void Functions::tree_interactive() {

    Tree* tree = new Tree;
    char response = 'y';
    while(response == 'y') {

        std::cout<<"Please choose what you want to do with your tree\n"
                   "1 - Add new element\n"
                   "2 - Print all data from tree\n"
                   "3 - Delete element\n";
        int key;
        std::cin>>key;
        if(key == 1){
            int value;
            std::cout<<"Enter value of new element\n";
            std::cin>>value;
            std::cout<<"Now enter the path to the father of your new element\n"
                       "Enter -1 if you want to end path\n";
            int key = 0;
            std::vector <int> path ={};
            while(key != -1){
                std::cin>>key;
                if(key != -1)
                    path.push_back(key);
            }
            tree->insert(path, value);

        }
        if(key == 2){
            tree->print_all_tree();
        }
        if(key == 3){
            std::cout<<"Enter the path to the element which you want to delete\n"
                       "Enter -1 if you want to end path\n";
            int key = 0;
            std::vector <int> path ={};
            while(key != -1){
                std::cin>>key;
                if(key != -1)
                    path.push_back(key);
            }
            Tree* remainder = tree->delete_element(path);
            std::cout<<"There is remanding tree after deleting\n";
            remainder->print_all_tree();
            delete remainder;
        }

        std::cout<<"If you want to do anything else with your tree, press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }
    delete tree;

}

void Functions::binary_tree_demo() {

    Binary_tree* tree = new Binary_tree;
    int v_1 = 20, v_2 = 10, v_3 = 5, v_4 = 15, v_5 = 17;
    std::string breakpoint;
    std::cout<<"Firstly, we will add 5 elements to our binary tree,\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    tree->insert(v_1);
    tree->insert(v_2);
    tree->insert(v_3);
    tree->insert(v_4);
    tree->insert(v_5);

    std::cout<<"Now we will print all data from our tree,\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    tree->print_all_tree(false);
    std::cout<<"Now we will delete element with path 0, 1 and print remainder tree\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    std::vector <int> path = {0, 1};
    Binary_tree* remainder = tree->delete_element(path);
    remainder->print_all_tree(false);

    std::cout<<"Now we will print all data from our tree,\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    tree->print_all_tree(false);

    std::cout<<"Now we will thread our tree and print all data,\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    tree->thread_tree();
    tree->print_all_tree(true);
    tree->unthread_tree();

    std::cout<<"This is the end of demo for this type of tree\n";

}

void Functions::tree_demo() {

    Tree* tree = new Tree;
    int v_1 = 20, v_2 = 10, v_3 = 5, v_4 = 15, v_5 = 17;
    std::vector <int> path_1 = {}, path_2 = {}, path_3 = {}, path_4 = {0}, path_5 = {0};
    std::string breakpoint;
    std::cout<<"Firstly, we will add 5 elements to our binary tree,\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    tree->insert(path_1, v_1);
    tree->insert(path_2, v_2);
    tree->insert(path_3, v_3);
    tree->insert(path_4, v_4);
    tree->insert(path_5, v_5);

    std::cout<<"Now we will print all data from our tree,\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    tree->print_all_tree();
    std::cout<<"Now we will delete element with path 0 and print remainder tree \n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    std::vector <int> path = {0};
    Tree* remainder = tree->delete_element(path);
    remainder->print_all_tree();

    std::cout<<"Now we will print all data from our tree,\n"
               "cin anything to continue\n";
    std::cin>>breakpoint;
    tree->print_all_tree();

    std::cout<<"This is the end of demo for this type of tree\n";
}

void Functions::expression_interactive() {

    char response = 'y';
    while(response == 'y') {
        std::cout<<"Please enter the CORRECT expression\n";
        std::string expr;
        getline(std::cin>>std::ws, expr);
//        std::cout<<"Please choose the mode\n"
//                   "1 - Counting of expression\n"
//                   "2 - Derivation of expresion\n";
//        int key;
//        std::cin>>key;
//        if(key == 1)
//        if(key == 2)
//            Mode::demo();
        std::cout<<expr<<"\n";
        Expression* expression = new Expression(expr);
        expression->count();
        std::cout<<"If you want to execute another mode press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }

}
