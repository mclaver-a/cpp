#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN &other) { *this = other; }
RPN &RPN::operator=(const RPN &other) {
    if (this != &other) this->_stack = other._stack;
    return *this;
}

void RPN::calculate(const std::string &expression) {
    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (isspace(c)) continue;

        if (isdigit(c)) {
            _stack.push(c - '0');
        } 
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (_stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return;
            }
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();

            if (c == '+') _stack.push(a + b);
            else if (c == '-') _stack.push(a - b);
            else if (c == '*') _stack.push(a * b);
            else if (c == '/') {
                if (b == 0) {
                    std::cerr << "Error" << std::endl; // Division by zero
                    return;
                }
                _stack.push(a / b);
            }
        } 
        else {
            std::cerr << "Error" << std::endl;
            return;
        }
    }

    if (_stack.size() != 1) {
        std::cerr << "Error" << std::endl;
    } else {
        std::cout << _stack.top() << std::endl;
    }
}
