/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:02:35 by mclaver-          #+#    #+#             */
/*   Updated: 2025/12/14 13:02:36 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <iterator>
#include <stack>

template <class T>
class MutantStack : public std::stack<T>
{
    public:
    MutantStack(void) {};
    MutantStack(const MutantStack<T> &src) : std::stack<T>(src) {};
    ~MutantStack(void) {};
    MutantStack<T> &operator=(const MutantStack<T> &other)
	{
		if (this == &other)
			return (*this);
		std::stack<T>::operator=(other);
		return (*this);
	}


	//explain why these are necessary with template classes
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	//what does stack use as its default underlying container?
	iterator begin(void)
	{
	    return (std::stack<T>::c.begin());
	}
	iterator end(void)
	{
	    return (std::stack<T>::c.end());
	}

	const_iterator begin(void) const
	{
	    return (std::stack<T>::c.begin());
	}
	const_iterator end(void) const
	{
	    return (std::stack<T>::c.end());
	}

	reverse_iterator rbegin(void)
	{
	    return (std::stack<T>::c.rbegin());
	}
	reverse_iterator rend(void)
	{
	    return (std::stack<T>::c.rend());
	}

	const_reverse_iterator rbegin(void) const
	{
	    return (std::stack<T>::c.rbegin());
	}
	const_reverse_iterator rend(void) const
	{
	    return (std::stack<T>::c.rend());
	}
};

#endif
