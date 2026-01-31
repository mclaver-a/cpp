/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:47:50 by mclaver-          #+#    #+#             */
/*   Updated: 2025/12/03 18:47:51 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
    std::cout << "----- TEST EMPTY ARRAY -----\n";
    Array<int> empty;

    try {
        std::cout << empty[0] << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
    }

    std::cout << "\n----- TEST NORMAL ARRAY -----\n";
    Array<int> numbers(5);

    for (int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;

    for (int i = 0; i < numbers.size(); i++)
        std::cout << numbers[i] << " ";

    std::cout << "\n\n----- TEST COPY CONSTRUCTOR -----\n";
    Array<int> copy(numbers);

    numbers[0] = 999;  // modify original

    std::cout << "original[0] = " << numbers[0] << "\n";
    std::cout << "copy[0]     = " << copy[0] << "\n";

    std::cout << "\n----- TEST OUT OF RANGE -----\n";
    try {
        std::cout << numbers[42];
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
    }

    try {
        std::cout << numbers[-1];
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}
