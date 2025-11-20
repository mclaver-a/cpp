/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:56:07 by mclaver-          #+#    #+#             */
/*   Updated: 2025/11/18 20:56:08 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: " << *argv << " <literal>\n";
		return (1);
	}
	ScalarConvert::convert(argv[1]);
	return (0);
}
