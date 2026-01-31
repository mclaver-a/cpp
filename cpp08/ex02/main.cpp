/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:00:29 by mclaver-          #+#    #+#             */
/*   Updated: 2025/12/14 13:00:31 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include "MutantStack.hpp"
#include <list>
#include <iostream>
#include <cassert>

void print_test_header(const std::string& title) {
    std::cout << "\n=== " << title << " ===\n";
}

template<typename Container>
void print_container(const std::string& name, const Container& c) {
    std::cout << name << ": ";
    for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main() {
    {
        std::cout << "\n=== " << "Test 1: Basic push and forward iteration" << " ===\n";

        MutantStack<int> mstack;
        std::list<int> list;

        for (int i = 0; i < 5; ++i) {
            mstack.push(i);
            list.push_back(i);
        }

        print_container("MutantStack", mstack);
        print_container("std::list", list);

        // Verify both containers have same elements in same order
        MutantStack<int>::iterator mit = mstack.begin();
        std::list<int>::iterator lit = list.begin();
        for (; mit != mstack.end() && lit != list.end(); ++mit, ++lit) {
            assert(*mit == *lit);
        }
    }

    {
        std::cout << "\n=== " << "Test 2: Reverse iteration" << " ===\n";

        MutantStack<int> mstack;
        std::list<int> list;

        for (int i = 0; i < 5; ++i) {
            mstack.push(i);
            list.push_back(i);
        }

        std::cout << "MutantStack (reverse): ";
        for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << "\n";

        std::cout << "std::list (reverse): ";
        for (std::list<int>::reverse_iterator rit = list.rbegin(); rit != list.rend(); ++rit) {
            std::cout << *rit << " ";
        }
        std::cout << "\n";

    }

    {
        std::cout << "\n=== " << "Test 3: Const iteration" << " ===\n";

        const MutantStack<int> mstack;
        for (int i = 0; i < 5; ++i) {
            const_cast<MutantStack<int>&>(mstack).push(i);  // Need const_cast because mstack is const
        }

        const std::list<int> list = {0, 1, 2, 3, 4};

        std::cout << "Const MutantStack: ";
        for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";

        std::cout << "Const std::list: ";
        for (std::list<int>::const_iterator it = list.begin(); it != list.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "\n";

    }

    return 0;
}
