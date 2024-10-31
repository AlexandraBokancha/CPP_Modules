#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <sstream>
# include <cstdlib>


class RPN
{
    public:
        // Type definition for operation functions
        typedef void (RPN::*Operations)();
        
        // Constructors, Destructor, Assignment Operator
        RPN();
        RPN(const RPN& other);
        RPN &operator=(const RPN &other);
        ~RPN();
        
        // Main functions
        void evaluateExpression(const std::string & expressionStr);
        void pushToStack(int nb);
        
        // Mathematical operations
        void addition();
        void subtraction();
        void division();
        void multiplication();

        // Exception classes
        class NotEnoughValues: public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class DivisionByZero: public std::exception{
            public:
                virtual const char* what() const throw();
        };
    
    private:
        // Stack for storing values
        std::stack<int> _stack;
};

#endif

