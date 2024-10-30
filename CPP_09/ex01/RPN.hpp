#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <sstream>
# include <cstdlib>


class RPN
{
    private:

        std::stack<int> _stack;

    public:

        RPN(void);
        RPN(const RPN& other);
        RPN &operator=(const RPN &other);
        ~RPN();
        
        typedef void (RPN::*Operations)();
        
        void evaluateExpression(const std::string & expressionStr);
        void pushToStack(int nb);
        
        void addition();
        void subtraction();
        void division();
        void multiplication();

        class NotEnoughValues: public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class DivisionByZero: public std::exception{
            public:
                virtual const char* what() const throw();
        };
};

#endif

