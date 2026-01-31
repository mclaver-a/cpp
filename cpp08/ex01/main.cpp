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

#include "Span.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>

int main()
{
    try
    {
        // Subject Test
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Range Test
        std::vector<int> v(42000);
        std::generate(v.begin(), v.end(), rand);

        Span bigSpan(42000);
        bigSpan.addNumber(v.begin(), v.end());

        std::cout << "Big shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Big longest span: " << bigSpan.longestSpan() << std::endl;

        // Exception Test
        try
        {
            bigSpan.addNumber(42);
        }
        catch (const std::exception &e)
        {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
