/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:55:27 by mclaver-          #+#    #+#             */
/*   Updated: 2025/11/18 20:55:29 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"

//private
void ScalarConvert::convchar(double val, std::string &str)
{
    if (val >= std::numeric_limits<unsigned char>::min()
		&& val <= std::numeric_limits<unsigned char>::max())
	{
		char c(static_cast<char>(val));
		str = "Non Displayable";
		if (std::isprint(c))
			str = (std::string("'") + c + "'");
	}
}

void ScalarConvert::convint(double val, std::string &str)
{
    if (val >= std::numeric_limits<int>::min()
        && val <= std::numeric_limits<int>::max())
    {
        std::ostringstream oss;
        oss << static_cast<int>(val);
        str = oss.str();
    }
}

void ScalarConvert::convfloat(double val, std::string &str)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << static_cast<float>(val) << "f";
    str = oss.str();
}

void ScalarConvert::convdouble(double val, std::string &str)
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(1) << static_cast<double>(val);
    str = oss.str();
}

//public
void ScalarConvert::convert(const std::string &str)
{
    std::string char_str("impossible");
	std::string int_str("impossible");
	std::string float_str("impossible");
	std::string double_str("impossible");
	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		float_str = str;
		double_str = str.substr(0, str.length() - 1);
	}
	else if (str == "-inf" || str == "+inf" || str == "nan")
	{
		float_str = str + "f";
		double_str = str;
	}
	else
	{
		char *end(0);
		double value(std::strtod(str.c_str(), &end));
		if (*end == 'f' && *(end + 1) == '\0') // 12f
			value = static_cast<float>(value);
		else if (*end != '\0')
		{
			if (str.length() == 1 && std::isprint(str[0])) // 12abc
				value = static_cast<double>(str[0]);
			else // abc
				value = std::numeric_limits<double>::quiet_NaN();
		}
		if (!std::isnan(value))
		{
			convchar(value, char_str);
			convint(value, int_str);
			convfloat(value, float_str);
			convdouble(value, double_str);
		}
	}
	std::cout << "char: " << char_str << "\n";
	std::cout << "int: " << int_str << "\n";
	std::cout << "float: " << float_str << "\n";
	std::cout << "double: " << double_str << "\n";

}
