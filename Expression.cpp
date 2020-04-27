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

    if(op == "log" || op == "sin" || op == "cos" || op == "tan" || op == "ctg")
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

bool Expression::valid_parentheses(std::string expr) {

    std::stack <std::string> par;
    std::string sign;
    for(int i = 0; i < expr.length(); i++){
        sign = expr[i];
        if(expr[i] == '(')
            par.push(sign);
        if(expr[i] == ')') {
            if (par.empty())
                return false;
            if(par.top() == "(")
                par.pop();
            else
                return false;
        }
    }
    return par.empty();

}

std::string Expression::const_expr(Expr_tree exprTree) {

    if(exprTree.root->value == "+" && exprTree.root->left->value == "^" && exprTree.root->right->value == "^"
        && exprTree.root->left->right->value == "2" && exprTree.root->right->right->value == "2"
        && exprTree.root->left->left->value == "cos" && exprTree.root->right->left->value == "sin"
        && exprTree.root->left->left->right->value == exprTree.root->right->left->right->value )
        return "1";
    if(exprTree.root->value == "+" && exprTree.root->left->value == "^" && exprTree.root->right->value == "^"
       && exprTree.root->left->right->value == "2" && exprTree.root->right->right->value == "2"
       && exprTree.root->left->left->value == "sin" && exprTree.root->right->left->value == "cos"
       && exprTree.root->left->left->right->value == exprTree.root->right->left->right->value )
        return "1";
    if(exprTree.root->value == "cos" && exprTree.root->right->value == "0")
        return "1";
    if(exprTree.root->value == "sin" && exprTree.root->right->value == "0")
        return "0";
    if(exprTree.root->value == "log" && exprTree.root->right->value == "1")
        return "0";
    if(exprTree.root->value == "*" &&
        ((exprTree.root->right->value == "0" && priority(exprTree.root->left->value) == -1)
        || (exprTree.root->left->value == "0" && priority(exprTree.root->right->value) == -1)))
        return "0";
    if(exprTree.root->value == "/" &&
       ((exprTree.root->right->value == "0" && !exprTree.root->left->variable)
        || (exprTree.root->left->value == "0" && !exprTree.root->right->variable)))
        return "0";
    if(exprTree.root->value == "-" && exprTree.root->left->value == exprTree.root->right->value)
        return "0";
    if(exprTree.root->value == "/" && exprTree.root->left->value == exprTree.root->right->value
        && !exprTree.root->left->variable)
        return "1";
    if(exprTree.root->value == "/" && (exprTree.root->left->value == "-" + exprTree.root->right->value ||
            exprTree.root->right->value == "-" + exprTree.root->left->value)
            && !exprTree.root->left->variable)
        return "-1";
    if(exprTree.root->value == "+" && (exprTree.root->left->value == "-" + exprTree.root->right->value ||
                                       exprTree.root->right->value == "-" + exprTree.root->left->value))
        return "0";
    if(exprTree.root->value == "^" &&
       (exprTree.root->right->value == "0" && priority(exprTree.root->left->value) == -1))
        return "1";
    if(exprTree.root->value == "^" &&
       (exprTree.root->left->value == "1" && priority(exprTree.root->right->value) == -1))
        return "1";
    if(exprTree.root->value == "^" &&
       (exprTree.root->right->value == "0" && exprTree.root->left->value == "0"))
        return "1";
    if(exprTree.root->value == "^" &&
       (exprTree.root->left->value == "0" && priority(exprTree.root->right->value) == -1))
        return "0";
    return "2";

}

void Expression::simplify(Expr_tree exprTree) {

    if(priority(exprTree.root->value) == -1){
        return;
    }
    Expr_tree left_sub, right_sub ;
    left_sub.root = exprTree.root->left;
    right_sub.root = exprTree.root->right;
//    std::cout<<"fsdafdfs"<<std::endl;
    if(left_sub.root != nullptr) {
        simplify(left_sub);
    }
    if(right_sub.root != nullptr) {
        simplify(right_sub);
    }
//    std::cout<<"kkhgg"<<std::endl;


    if(const_expr(exprTree) != "2"){
        exprTree.root->value =  const_expr((exprTree));
        exprTree.root->left = nullptr;
        exprTree.root->right = nullptr;

    }



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

    expression.root = new Expr_tree::Node (blocks[blocks.size() - 1], 0, false);
    Expr_tree::Node* temp = expression.root;
    bool variable;
    for(int i = blocks.size() - 2; i >= 0; i--){
        variable = priority(blocks[i]) == -1 && (int(blocks[i][0]) >= 65 || (int(blocks[i][0]) == '-' && int(blocks[i][1]) >= 65));
        if(temp->right == nullptr && priority(temp->value) != -1){
//            std::cout<<blocks[i]<<" hjjh;\n";
            temp->right =  new Expr_tree::Node (blocks[i], 1, variable);
            temp->right->father = temp;
            temp = temp->right;
        }
        else if(temp->left == nullptr && priority(temp->value) != -1 && priority(temp->value) != 5){
//            std::cout<<blocks[i]<<" fgfggsd\n";
            temp->left =  new Expr_tree::Node (blocks[i], 0, variable);
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

void Expression::define_variables() {

   define_interactive(expression.root);

}

void Expression::define_interactive(Expr_tree::Node *node) {

    if(node == nullptr)
        return;
    if(node->variable ){
        if(variables.find(node->value) == variables.end()) {
            std::cout << "Enter the value of variable: "<<node->value<<"\n";
            std::string var;
            std::cin>>var;
            variables.insert({node->value, var});
        }
        node->value = variables[node->value];
    }
    define_interactive(node->left);
    define_interactive(node->right);

}

void Expression::output_tree() {

    blocks.clear();

    output_node(expression.root);

}

void Expression::output_node(Expr_tree::Node *node) {

    if(node == nullptr)
        return;
    output_node(node->left);
    output_node(node->right);
    blocks.emplace_back(node->value);

}

double Expression::count(bool& is_valid) {

    std::stack <double> numbers;
    double num_1, num_2;
    for(int i = 0; i < blocks.size(); i++){
        if(priority(blocks[i]) == -1){
            num_1 = std::stod(blocks[i]);
            numbers.push(num_1);
        }
        if(blocks[i] == "+"){
            num_1 = numbers.top();
            numbers.pop();
            num_2 = numbers.top();
            numbers.pop();
            numbers.push(num_2 + num_1);
        }
        if(blocks[i] == "-"){
            num_1 = numbers.top();
            numbers.pop();
            num_2 = numbers.top();
            numbers.pop();
            numbers.push(num_2 - num_1);
        }
        if(blocks[i] == "*"){
            num_1 = numbers.top();
            numbers.pop();
            num_2 = numbers.top();
            numbers.pop();
            numbers.push(num_2 * num_1);
        }
        if(blocks[i] == "/"){
            num_1 = numbers.top();
            numbers.pop();
            num_2 = numbers.top();
            numbers.pop();
            if(num_1 == 0){
                std::cout<<"You can`t divide by 0\n";
                is_valid = false;
                return 0;
            }
            numbers.push(num_2 / num_1);
        }
        if(blocks[i] == "^"){
            num_1 = numbers.top();
            numbers.pop();
            num_2 = numbers.top();
            numbers.pop();
            numbers.push(pow(num_2, num_1));
        }
        if(blocks[i] == "log"){
            num_1 = numbers.top();
            numbers.pop();
            if(num_1 <= 0){
                std::cout<<"Logarithm argument can't be <= 0\n";
                is_valid = false;
                return 0;
            }
            numbers.push(log(num_1));
        }
        if(blocks[i] == "cos"){
            num_1 = numbers.top();
            numbers.pop();
            numbers.push(cos(num_1));
        }
        if(blocks[i] == "sin"){
            num_1 = numbers.top();
            numbers.pop();
            numbers.push(sin(num_1));
        }
        if(blocks[i] == "tan"){
            num_1 = numbers.top();
            numbers.pop();
            numbers.push(tan(num_1));
        }
        if(blocks[i] == "ctg"){
            num_1 = numbers.top();
            numbers.pop();
            if(num_1 == 0){
                std::cout<<"Ctg is undefined in 0-point\n";
                is_valid = false;
                return 0;
            }
            numbers.push(1 / tan(num_1));
        }

    }
    return numbers.top();


}

void Expression::count_interactive() {


    parse();
    if(!valid_parentheses(parsed)){
        std::cout<<"Your expression has invalid parentheses\n";
        return;
    }
    std::cout<<parsed<<"\n";

    transform_to_polish();

    for(int i = 0; i < blocks.size(); i++){
        std::cout<<blocks[i]<<" ";
    }
    std::cout<<"\n";
    build_tree();
    std::cout<<"tree is built\n";
    expression.print_all_tree();

    std::cout<<"Now we will simplify our tree\n";
    simplify(expression);
    expression.print_all_tree();

    define_variables();
    std::cout<<"This is our tree without variables\n";
    expression.print_all_tree();
    simplify(expression);
    output_tree();
    for(int i = 0; i < blocks.size(); i++){
        std::cout<<blocks[i]<<" ";
    }
    std::cout<<"\n";
    bool is_valid = true;
    double result = count(is_valid);
    if(!is_valid){
        std::cout<<"Your expression is unvalid, please enter the valid once\n";
    } else{
        std::cout<<"The result of your expression is: "<<result<<"\n";
    }



}
