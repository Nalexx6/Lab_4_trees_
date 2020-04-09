//
// Created by Win10Pro on 31.03.2020.
//

#include "Mode.h"

void Mode::interactive() {

    char response = 'y';
    while(response == 'y') {

        std::cout<<"Hello, please choose the data structure\n"
                   "1 - Tree(any quantity of sons provided)\n"
                   "2 - Binary tree\n";
        int key;
        std::cin>>key;
        if(key == 1)
            Functions::tree_interactive();
        if(key == 2)
            Functions::binary_tree_interactive();

        std::cout<<"If you want to execute interactive for another type of tree press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }

}

void Mode::demo() {

    char response = 'y';
    while(response == 'y') {

        std::cout<<"Hello, please choose the data structure\n"
                   "1 - Tree(any quantity of sons provided)\n"
                   "2 - Binary tree\n";
        int key;
        std::cin>>key;
        if(key == 1)
            Functions::tree_demo();
        if(key == 2)
            Functions::binary_tree_demo();

        std::cout<<"If you want to execute demo for another type of tree press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }

}
