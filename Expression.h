//
// Created by Win10Pro on 13.04.2020.
//

#ifndef LAB_4_TREES__EXPRESSION_H
#define LAB_4_TREES__EXPRESSION_H

#include "Expr_tree.h"
#include <map>
#include <stack>
#include <vector>
#include <string>

class Expression {

private:

    //Auxiliary

    static std::string minus_spaces(std::string& expr);
    std::string extra_spaces(std::string& expr);
    static double my_pow(double& base, int& power);
    static int priority(std::string& op);


    //Body of expression

    std::string input;
    std::vector <std::string> blocks{};
    std::string parsed;
    std::map <std::string, std::string> variables {};
    std::stack <std::string> operators {};
//    std::string polish_input;
    Expr_tree expression;

    //Transforming

    void parse();
    void transform_to_polish();
    void build_tree();


public:

    Expression (std::string& input);
    void count();

};


#endif //LAB_4_TREES__EXPRESSION_H
