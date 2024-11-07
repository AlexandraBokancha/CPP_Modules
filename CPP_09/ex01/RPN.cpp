#include "RPN.hpp"

// Default constructor
RPN::RPN(void){
    //std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
RPN::RPN(const RPN &other){
    //std::cout << "Copy constructor called" << std::endl;
    this->_stack = other._stack;
}

// Assignment operator overload
RPN &RPN::operator=(const RPN &other){
   // std::cout << "Assignment operator called" << std::endl;
    if (this != &other)
        this->_stack = other._stack;
    return (*this);
}

// Destructor
RPN::~RPN(void){
   // std::cout << "Destructor called" << std::endl;
}

void RPN::pushToStack(int nb){
    _stack.push(nb);
}

void RPN::multiplication(){
    if (_stack.size() < 2)
        throw RPN::NotEnoughValues();
    int right = _stack.top();
    _stack.pop();
    int left = _stack.top();
    _stack.pop();
    pushToStack(left * right);
}

void RPN::division(){
    if (_stack.size() < 2)
        throw RPN::NotEnoughValues();
    int right = _stack.top();
    if (right == 0)
        throw RPN::DivisionByZero();
    _stack.pop();
    int left = _stack.top();
    _stack.pop();
    pushToStack(left / right);
}

void RPN::subtraction(){
    if (_stack.size() < 2)
        throw RPN::NotEnoughValues();
    int right = _stack.top();
    _stack.pop();
    int left = _stack.top();
    _stack.pop();
    pushToStack(left - right);
}

void RPN::addition(){
    if (_stack.size() < 2)
        throw RPN::NotEnoughValues();
    int right = _stack.top();
    _stack.pop();
    int left = _stack.top();
    _stack.pop();
    pushToStack(left + right);
}

/*
    To evaluate an expression in RPN, a stack-based algorithm is commonly used. 
    Here’s how it works:

1. Start with an empty stack.
2. Scan the expression from left to right.
3. If the current token is an operand, push it onto the stack.
4. If the current token is an operator, pop the top two operands from the stack, 
    apply the operator to them, and push the result back onto the stack.
5. Continue this process until all tokens have been processed.
6. The final result is the value remaining on the stack.

*/
void RPN::evaluateExpression(const std::string & expressionStr){
    if (expressionStr.empty() == true){
        throw std::runtime_error("Error: expression is empty");
    }
    std::stringstream ss(expressionStr);
    std::string val;
    Operations fnPtr[] = {
        &RPN::addition,
        &RPN::subtraction,
        &RPN::division,
        &RPN::multiplication
    };
    std::string tokens[] = {
        "+",
        "-",
        "/",
        "*"
    };
    bool    operationFound = false;
    while (ss >> val){
        if (val.size() == 1 && isdigit(*val.c_str())){
            pushToStack(atoi(val.c_str()));
        }
        else
        {
            for (int i = 0; i < 4; ++i){
                operationFound = false;
                if (val == tokens[i]){
                    (this->*fnPtr[i])();
                    operationFound = true;
                    break ;
                }
            }
            if (!operationFound){
                throw std::runtime_error("Error: value is not valid");
            }
        }
    }
    std::cout << "Result: " << _stack.top() << std::endl;
}

const char* RPN::NotEnoughValues::what() const throw(){
    return "\033[31mNot enough values on stack for the requested operation\033[0m";
}

const char* RPN::DivisionByZero::what() const throw(){
    return "\033[31mDivision by zero encountered\033[0m";
}
