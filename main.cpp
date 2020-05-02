

#include "Mode.h"

int main() {

    //Variant: 1, 2, 3, 11, 13, 15, 18, 20, 23
    char response = 'y';
    while(response == 'y') {

        std::cout<<"Hello, please choose the mode\n"
                   "1 - Interactive\n"
                   "2 - Demo\n";
        int key;
        std::cin>>key;
        if(key == 1)
            Mode::interactive();
        if(key == 2)
            Mode::demo();

        std::cout<<"If you want to execute another mode press 'y', press 'n', if you don`t\n";
        std::cin>>response;

    }


}