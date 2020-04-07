//
// Created by Win10Pro on 31.03.2020.
//

#include "Functions.h"

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
                       "Enter -1 if you want to end path";
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

        std::cout<<"If you want to execute another mode press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }


}
