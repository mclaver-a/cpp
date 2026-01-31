/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:46:52 by mclaver-          #+#    #+#             */
/*   Updated: 2025/12/03 18:46:53 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T>
void print(const T &x)
{
	std::cout << x << " ";
}

void	inc(int &x)
{
	x += 10;
}

int	main(void)
{
	int	tab[5] = {0, 1, 2, 3, 4};

	std::cout << "int array: ";
	iter(tab, 5, print<const int>);
	std::cout << "\n";

	iter(tab, 5, inc);
	std::cout << "int array after increment: ";
	iter(tab, 5, print<const int>);
	std::cout << "\n";

	std::string arr[5] = {"hello", "my", "name", "is", "jeff"};
	std::cout << "string array: ";
	iter(arr, 5, print<const std::string>);
	std::cout << "\n";
}
