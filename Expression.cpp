//
// Created by Win10Pro on 13.04.2020.
//

#include "Expression.h"

Expression::Expression(std::string &input) {

    this->input = input;

}

std::string Expression::minus_spaces(std::string &expr) {

    std::string answer;

    for(int i = 0; i < expr.length(); i++){
        if (expr[i] != ' ')
            answer += expr[i];
    }

    return answer;

}

std::string Expression::extra_spaces(std::string &expr) {

    std::string answer;

    for(int i = 0; i < expr.length(); i++){
        while(expr[i] == ' ' && expr[i+1] == ' ' ) {
            i++;
        }
        answer += expr[i];
    }

    return answer;

}

double Expression::my_pow(double &base, int &power) {

    double res = 1;
    for(int i = 0; i < power; i++){
        res *= base;
    }
    return res;
}

int Expression::priority(std::string &op) {

    if(op == "log" || op == "sin" || op == "cos" || op == "tan")
        return 5;
    if(op == "^")
        return 4;
    if(op == ")")
        return 3;
    if(op == "(")
        return 2;
    if(op == "*" || op == "/")
        return 1;
    if(op == "+" || op == "-")
        return 0;
    return -1;

}

void Expression::parse() {

    input = minus_spaces(input);
    //temp_part for variables or for functions
    std::string temp_part, sign, sign_p;
    for(int i = 0; i < input.length(); i++){
        sign = input[i];
        if(priority(sign) == -1)
            parsed += input[i];
        else {
//            sign_p = input[i + 1];
            if(sign == "-" && (i == 0 || input[i-1] == '(')){
                parsed += sign;
            }
            else {
                parsed += " " + sign + " ";
            }
        }
    }
    parsed = extra_spaces(parsed);
    temp_part = "";
    for(int i = 0; i < parsed.length(); i++){
        while(parsed[i] != ' ' && i != parsed.length()){
            temp_part += parsed[i];
            i++;
        }
//        std::cout<<temp_part<<"\n";
        blocks.push_back(temp_part);
        temp_part = "";
    }

}

void Expression::transform_to_polish() {

//    for(int i = 0; i < blocks.size(); i++){
//        std::cout<<blocks[i]<<"\n";
//    }
//    std::cout<<"\n";
    int size = blocks.size();
    for(int i = 0; i < size; i++){
        if(priority(blocks[i]) == -1){
            blocks.push_back(blocks[i]);
        } else if(operators.empty() || priority(blocks[i]) == 5 || priority(blocks[i]) == 2){
            operators.push(blocks[i]);
        } else if(priority(blocks[i]) == 3){
            while (priority(operators.top()) != 2){
                blocks.push_back(operators.top());
                operators.pop();
            }
            operators.pop();
            if(!operators.empty()){
                if(priority(operators.top()) == 5){
                    blocks.push_back(operators.top());
                    operators.pop();
                }
            }
        } else {
            if (priority(blocks[i]) > priority(operators.top())) {
                operators.push(blocks[i]);
            } else if(priority(blocks[i]) == priority(operators.top())){
                blocks.push_back(operators.top());
                operators.pop();
                operators.push(blocks[i]);
            } else if(priority(blocks[i]) < priority(operators.top())){
                while (priority(blocks[i]) < priority(operators.top())){
                    if(priority(operators.top()) == 2)
                        break;
                    blocks.push_back(operators.top());
                    operators.pop();
                    if(operators.empty())
                        break;
                }
                operators.push(blocks[i]);
            }
        }
    }
    while (!operators.empty()){
        blocks.push_back(operators.top());
        operators.pop();
    }
//    for(int i = 0; i < blocks.size(); i++){
//        std::cout<<blocks[i]<<"\n";
//    }
//    std::cout<<"\n";
//    std::cout<<blocks.size()<<"\n";
    blocks.erase(blocks.begin(), blocks.begin() + size);

}

void Expression::build_tree() {

    expression.root = new Expr_tree::Node (blocks[blocks.size() - 1], 0);
    Expr_tree::Node* temp = expression.root;
    for(int i = blocks.size() - 2; i >= 0; i--){
        if(temp->right == nullptr && priority(temp->value) != -1){
//            std::cout<<blocks[i]<<" hjjh;\n";
            temp->right =  new Expr_tree::Node (blocks[i], 1);
            temp->right->father = temp;
            temp = temp->right;
        }
        else if(temp->left == nullptr && priority(temp->value) != -1 && priority(temp->value) != 5){
//            std::cout<<blocks[i]<<" fgfggsd\n";
            temp->left =  new Expr_tree::Node (blocks[i], 0);
            temp->left->father = temp;
            temp = temp->left;
        }
        else{
//            std::cout<<blocks[i]<<" sdfsd\n";
            temp = temp->father;
            i++;
        }
    }

}

void Expression::count() {

    parse();
    std::cout<<parsed<<"\n";

    transform_to_polish();

    for(int i = 0; i < blocks.size(); i++){
        std::cout<<blocks[i]<<" ";
    }
    std::cout<<"\n";


    for(int i = 0; i < blocks.size(); i++){
        std::cout<<blocks[i]<<" ";
    }
    std::cout<<"\n";
    build_tree();
    std::cout<<"tree is built\n";
    expression.print_all_tree();


}
