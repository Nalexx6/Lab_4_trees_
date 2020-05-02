# Lab_4_trees_
~Lab_4 is 3 combined tasks: tree strucure(any sons can be), binary tree structure with threading, expression tree structure.2 modes provided: interactive and demo.
~About tree: adding element is defined by path to father element, deleting element also by path to it.
You can delete remaining subtree from memory or return it. Output of tree: for every node outputing value and path to it.
~About binary tree: adding element the same as in binary search tree, outputing and deleting the same as in tree structure above.
Your can thread your tree: make "null" pointers to be pointed on elements that are higher in tree;
~About expression tree: this is tree for rendering expressions: real variables functions. Accessible functions: +, -, *, /, ^, sin, cos, tan, ctg, log.
Firstly normal wiew of expression is changed to polish notation of it. From this form we are building tree: operators in nodes and operand in leafes.
Validation is provided by 3 criterias: valid parentheses, argument of log > 0, and dividing by 0.
Simplification of tree is possible by reduction of constant subexpressions. Differentiation of expression by exact variable also provided.
