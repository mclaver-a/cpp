#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->_vec = other._vec;
        this->_deq = other._deq;
    }
    return *this;
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t n) {
    std::vector<size_t> jacob;
    if (n == 0) return jacob;
    jacob.push_back(1); // J(1)
    if (n == 1) return jacob;
    jacob.push_back(3); // J(2)
    while (true) {
        size_t next = jacob.back() + 2 * jacob[jacob.size() - 2];
        if (next >= n) break;
        jacob.push_back(next);
    }
    return jacob;
}

//VECTOR IMPLEMENTATION
std::vector<int> PmergeMe::fordJohnsonVec(std::vector<int>& v) {
    if (v.size() <= 1) return v;

    int extra = -1;
    bool hasExtra = false;
    if (v.size() % 2 != 0) {
        extra = v.back();
        v.pop_back();
        hasExtra = true;
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < v.size(); i += 2) {
        if (v[i] < v[i+1]) pairs.push_back(std::make_pair(v[i+1], v[i]));
        else pairs.push_back(std::make_pair(v[i], v[i+1]));
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) mainChain.push_back(pairs[i].first);
    mainChain = fordJohnsonVec(mainChain);

    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        // Match the pend element to its main chain buddy
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].first) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }

    // Insert first pend element
    mainChain.insert(mainChain.begin(), pend[0]);

    // Jacobsthal insertion logic
    std::vector<size_t> jacobIdx = generateJacobsthal(pend.size());
    size_t lastInserted = 1;

    for (size_t i = 1; i < jacobIdx.size(); ++i) {
        for (size_t j = jacobIdx[i]; j > lastInserted; --j) {
            if (j - 1 < pend.size()) {
                std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[j-1]);
                mainChain.insert(it, pend[j-1]);
            }
        }
        lastInserted = jacobIdx[i];
    }
    // Handle remaining
    for (size_t i = lastInserted + 1; i <= pend.size(); ++i) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i-1]);
        mainChain.insert(it, pend[i-1]);
    }

    if (hasExtra) {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), extra);
        mainChain.insert(it, extra);
    }
    return mainChain;
}

//DEQUE IMPLEMENTATION
std::deque<int> PmergeMe::fordJohnsonDeq(std::deque<int>& d) {
    if (d.size() <= 1) return d;

    int extra = -1;
    bool hasExtra = false;
    if (d.size() % 2 != 0) {
        extra = d.back();
        d.pop_back();
        hasExtra = true;
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < d.size(); i += 2) {
        if (d[i] < d[i+1]) pairs.push_back(std::make_pair(d[i+1], d[i]));
        else pairs.push_back(std::make_pair(d[i], d[i+1]));
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) mainChain.push_back(pairs[i].first);
    mainChain = fordJohnsonDeq(mainChain);

    std::deque<int> pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (mainChain[i] == pairs[j].first) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }

    mainChain.push_front(pend[0]);
    std::vector<size_t> jacobIdx = generateJacobsthal(pend.size());
    size_t lastInserted = 1;

    for (size_t i = 1; i < jacobIdx.size(); ++i) {
        for (size_t j = jacobIdx[i]; j > lastInserted; --j) {
            if (j - 1 < pend.size()) {
                std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[j-1]);
                mainChain.insert(it, pend[j-1]);
            }
        }
        lastInserted = jacobIdx[i];
    }
    for (size_t i = lastInserted + 1; i <= pend.size(); ++i) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pend[i-1]);
        mainChain.insert(it, pend[i-1]);
    }
    if (hasExtra) {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), extra);
        mainChain.insert(it, extra);
    }
    return mainChain;
}

void PmergeMe::execute(int ac, char **av) {
    for (int i = 1; i < ac; ++i) {
        std::string s = av[i];
        if (s.empty() || s.find_first_not_of("0123456789") != std::string::npos) {
            std::cerr << "Error" << std::endl; return;
        }
        long val = std::atol(av[i]);
        if (val < 0 || val > INT_MAX) { std::cerr << "Error" << std::endl; return; }
        _vec.push_back(static_cast<int>(val));
        _deq.push_back(static_cast<int>(val));
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i) std::cout << _vec[i] << " ";
    std::cout << std::endl;

    clock_t startVec = clock();
    _vec = fordJohnsonVec(_vec);
    clock_t endVec = clock();

    clock_t startDeq = clock();
    _deq = fordJohnsonDeq(_deq);
    clock_t endDeq = clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < _vec.size(); ++i) std::cout << _vec[i] << " ";
    std::cout << std::endl;

    double timeV = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
    double timeD = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " << timeV << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " << timeD << " us" << std::endl;
}
