#include "PmergeMe.hpp"

int main(int ac, char **av) {
    if (ac < 2) {
        std::cerr << "Error: Provide a sequence of positive integers." << std::endl;
        return 1;
    }
    PmergeMe p;
    p.execute(ac, av);
    return 0;
}
