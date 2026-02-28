#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(const RPN& other) { *this = other; }
RPN& RPN::operator=(const RPN& other) {
    if (this != &other) this->_stack = other._stack;
    return *this;
}

void RPN::calculate(const std::string& expr) {
    for (size_t i = 0; i < expr.length(); ++i) {
        if (isspace(expr[i])) continue;
        if (isdigit(expr[i])) {
                        if (i + 1 < expr.length() && isdigit(expr[i + 1])) {
                std::cerr << "Error" << std::endl; // Found a number >= 10
                return;
            }
            _stack.push_back(expr[i] - '0');
        }
        else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/') {
            if (_stack.size() < 2) { std::cerr << "Error" << std::endl; return; }
            int b = _stack.back(); _stack.pop_back();
            int a = _stack.back(); _stack.pop_back();
            if (expr[i] == '+') _stack.push_back(a + b);
            else if (expr[i] == '-') _stack.push_back(a - b);
            else if (expr[i] == '*') _stack.push_back(a * b);
            else if (expr[i] == '/') {
                if (b == 0) { std::cerr << "Error" << std::endl; return; }
                _stack.push_back(a / b);
            }
        } else { std::cerr << "Error" << std::endl; return; }
    }
    if (_stack.size() != 1) std::cerr << "Error" << std::endl;
    else std::cout << _stack.back() << std::endl;
}
