/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:03:01 by mclaver-          #+#    #+#             */
/*   Updated: 2025/12/14 13:03:02 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int newN) : N(newN)
{
    numbers.reserve(newN);
}

Span::~Span() {}

Span & Span::operator = (const Span &src)
{
    if (this != &src)
    {
        N = src.N;
        numbers = src.numbers;
    }
    return *this;
}

void Span::addNumber(int nbr)
{
    if (numbers.size() >= N)
        throw std::out_of_range("Span is full");
    numbers.push_back(nbr);
}

long Span::shortestSpan()
{
    if (numbers.size() < 2)
        throw std::out_of_range("Span is too short");

    std::vector<long> sorted(numbers.begin(), numbers.end());
    std::sort(sorted.begin(), sorted.end());

    long minSpan = std::numeric_limits<long>::max();
    for (size_t i = 0; i < sorted.size() - 1; ++i)
    {
        long diff = sorted[i + 1] - sorted[i];
        minSpan = std::min(minSpan, diff);
    }
    return minSpan;
}

long Span::longestSpan()
{
    if (numbers.size() < 2)
        throw std::out_of_range("Span is too short");

    std::vector<long> sorted(numbers.begin(), numbers.end());
    std::sort(sorted.begin(), sorted.end());

    return sorted.back() - sorted.front();
}

void Span::printVector(void)
{
    std::vector<int> tmp = numbers;
    std::sort(tmp.begin(), tmp.end());

    std::cout << "Numbers: ";
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}
