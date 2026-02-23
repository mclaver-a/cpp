#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>
#include <iterator>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    void run(int ac, char **av);

private:
    void sortVector(std::vector<int>& v);
    void sortDeque(std::deque<int>& d);
    template <typename T>
    void fordJohnson(T& container);
};

#endif
