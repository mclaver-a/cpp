#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <climits>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    // Vector Implementation
    void sortVector(std::vector<int>& container);
    std::vector<int> fordJohnsonVec(std::vector<int>& container);
    
    // Deque Implementation
    void sortDeque(std::deque<int>& container);
    std::deque<int> fordJohnsonDeq(std::deque<int>& container);

    // Helpers
    bool isAllPosInt(int ac, char **av);
    std::vector<size_t> generateJacobsthal(size_t n);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void execute(int ac, char **av);
};

#endif
