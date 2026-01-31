/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:18:40 by mclaver-          #+#    #+#             */
/*   Updated: 2025/11/20 18:18:45 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		data;
	uintptr_t	raw;
	Data		*ptr;

	data.name = "Jupiter";
	std::cout << "Data &: " << &data << "\n";
	raw = Serializer::serialize(&data);
	std::cout << "RAW &: " << &raw << "\n";
	ptr = Serializer::deserialize(raw);
	std::cout << "PTR &: " << &ptr << "\n";
	if (ptr == &data)
		std::cout << "Data Name: " << ptr->name << "\n";
	return (0);
}
