/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mclaver- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:48:00 by mclaver-          #+#    #+#             */
/*   Updated: 2025/12/03 18:48:01 by mclaver-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdexcept>

template <typename T>
class Array
{
private:
    int _size;
    T*  _array;

public:
    Array() : _size(0), _array(NULL) {}

    Array(unsigned int n) : _size(n), _array(new T[n]) {}

    ~Array() { delete[] _array; }

    Array(const Array &src) : _size(src._size)
    {
        _array = new T[_size];
        for (int i = 0; i < _size; i++)
            _array[i] = src._array[i];
    }

    Array &operator=(const Array &src)
    {
        if (this != &src)
        {
            delete[] _array;
            _size = src._size;
            _array = new T[_size];
            for (int i = 0; i < _size; i++)
                _array[i] = src._array[i];
        }
        return *this;
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= _size)
            throw std::out_of_range("Index out of range!");
        return _array[index];
    }

    const T &operator[](int index) const
    {
        if (index < 0 || index >= _size)
            throw std::out_of_range("Index out of range!");
        return _array[index];
    }

    int size() const { return _size; }
};
