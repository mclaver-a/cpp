#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <list>
#include <string>

class RPN {
private:
    std::list<int> _stack;
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    void calculate(const std::string& expr);
};

#endif
