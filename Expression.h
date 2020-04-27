//
// Created by Win10Pro on 13.04.2020.
//

#ifndef LAB_4_TREES__EXPRESSION_H
#define LAB_4_TREES__EXPRESSION_H

#include "Expr_tree.h"
#include <map>
#include <stack>
#include <cmath>

class Expression {

private:

    //Auxiliary

    static std::string minus_spaces(std::string& expr);
    static std::string extra_spaces(std::string& expr);
    static double my_pow(double& base, int& power);
    static int priority(std::string& op);


    //Body of expression

    std::string input;
    std::vector <std::string> blocks{};
    std::string parsed;
    std::map <std::string, std::string> variables {};
    std::stack <std::string> operators {};
    Expr_tree expression;

    //Transforming

    void parse();
    void transform_to_polish();
    void build_tree();

    //Counting expression

    void define_variables();
    void define_interactive(Expr_tree::Node* node);
    void output_tree();
    void output_node(Expr_tree::Node* node);
    double count(bool& is_valid);

    //Simplification

    void simplify(Expr_tree exprTree);
    std::string const_expr(Expr_tree exprTree);

    //Validation

    static bool valid_parentheses(std::string expr);


public:

    Expression (std::string& input);
    void count_interactive();

};


#endif //LAB_4_TREES__EXPRESSION_H
