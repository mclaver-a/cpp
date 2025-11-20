/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:55:46 by mclaver-          #+#    #+#             */
/*   Updated: 2025/11/18 20:55:47 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <cmath>
#include <cctype>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>


class ScalarConvert
{
    private:
        ScalarConvert();                                    //Constructor
        ScalarConvert(const ScalarConvert &src);            //Copy Constructor
        ScalarConvert &operator=(const ScalarConvert &src); //Operator Overload
        ~ScalarConvert();                                   //Destructor

        void static convchar(double val, std::string &str);
        void static convint(double val, std::string &str);
        void static convfloat(double val, std::string &str);
        void static convdouble(double val, std::string &str);

    public:
        void static convert(const std::string &str);
};
