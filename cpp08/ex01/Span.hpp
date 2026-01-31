/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:02:54 by mclaver-          #+#    #+#             */
/*   Updated: 2025/12/14 13:02:55 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <iostream>
#include <iterator>

class Span
{
    private:
        unsigned int    N;
        std::vector<int> numbers;

    public:
        Span(void);
        Span(unsigned int newN);
        ~Span();

        Span & operator = (const Span &src);

        // Single number
        void    addNumber(int nbr);

        // Range of iterators
        template <typename InputIt>
        void    addNumber(InputIt first, InputIt last)
        {
            size_t count = std::distance(first, last);

            if (numbers.size() + count > N)
                throw std::out_of_range("Span is full");

            numbers.insert(numbers.end(), first, last);
        }

        long    shortestSpan(void);
        long    longestSpan(void);

        // Helper
        void    printVector(void);
};

#endif
