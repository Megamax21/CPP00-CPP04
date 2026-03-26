/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:27:41 by ml-hote           #+#    #+#             */
/*   Updated: 2026/03/26 21:08:21 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>


std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}

static void	printComparisons(const Fixed& a, const Fixed& b)
{
	std::cout << "Comparisons" << std::endl;
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "a < b  : " << (a < b) << std::endl;
	std::cout << "a > b  : " << (a > b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;
	std::cout << std::endl;
}

static void	printArithmetic(const Fixed& a, const Fixed& b)
{
	std::cout << "Arithmetic" << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;
	std::cout << std::endl;
}

static void	printIncrements(Fixed value)
{
	std::cout << "Increment / Decrement" << std::endl;
	std::cout << "start          : " << value << std::endl;
	std::cout << "++value        : " << ++value << std::endl;
	std::cout << "after ++value  : " << value << std::endl;
	std::cout << "value++        : " << value++ << std::endl;
	std::cout << "after value++  : " << value << std::endl;
	std::cout << "--value        : " << --value << std::endl;
	std::cout << "after --value  : " << value << std::endl;
	std::cout << "value--        : " << value-- << std::endl;
	std::cout << "after value--  : " << value << std::endl;
	std::cout << std::endl;
}

static void	printMinMax(Fixed& a, Fixed& b)
{
	std::cout << "min / max" << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	Fixed a(10.5f);
	Fixed b(2);
	Fixed c;

	std::cout << "Assignment" << std::endl;
	c = a;
	std::cout << "a = " << a << ", c = " << c << std::endl;
	std::cout << std::endl;

	printComparisons(a, b);
	printArithmetic(a, b);
	printIncrements(a);
	printMinMax(a, b);

	const Fixed ca(1.25f);
	const Fixed cb(1.5f);
	std::cout << "const min = " << Fixed::min(ca, cb) << std::endl;
	std::cout << "const max = " << Fixed::max(ca, cb) << std::endl;
	return (0);
}