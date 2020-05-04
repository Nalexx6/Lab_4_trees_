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

    //Count demo

    void define_variables(std::vector<std::string>& values);
    void define_node(Expr_tree::Node* node, std::vector<std::string>& values);

    //Simplification

    void simplify(Expr_tree& exprTree);
    Expr_tree const_expr(Expr_tree exprTree);

    //Validation

    static bool valid_parentheses(std::string expr);

    //Differentiation

    std::vector <std::string> all_variables;
    bool existed(std::string value);
    std::string find_variables(bool demo);
    void find_node(Expr_tree::Node* node);
    Expr_tree copy_tree(Expr_tree exprTree);
    void copy_node(Expr_tree::Node* node, Expr_tree::Node* copy_n);
    Expr_tree derivative(Expr_tree exprTree,std::string& variable);


public:

    explicit Expression (std::string& input);

    //Interactive

    void count_interactive();
    void differentiation_interactive();

    //Demo

    void count_demo(std::vector<std::string>& values);
    void differentiation_demo();
};


#endif //LAB_4_TREES__EXPRESSION_H
