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

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
    //test 1 (vector)
	std::vector<int> vec;
	for (int i = 1; i <= 5; i++)
		vec.push_back(i);

	std::vector<int>::const_iterator it = easyfind(vec, 4);
	if (it != vec.end())
		std::cout << "Found in vector: " << *it << std::endl;
	else
		std::cout << "Not found in vector" << std::endl;

	//test 2 (list)
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	std::list<int>::const_iterator lit = easyfind(lst, 20);
	if (lit != lst.end())
		std::cout << "Found in list: " << *lit << std::endl;
	else
		std::cout << "Not found in list" << std::endl;

	return 0;
}
