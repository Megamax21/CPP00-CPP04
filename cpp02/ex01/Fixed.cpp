/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:59:22 by ml-hote           #+#    #+#             */
/*   Updated: 2026/03/26 16:01:30 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fp_val = other._fp_val;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_fp_val = other._fp_val;
	return (*this);
}

Fixed::Fixed(const int i)
{
	this->_fp_val = i << this->_fractional_bits;// >> this->_fractional_bits;
}
Fixed::Fixed(const float f)
{
	this->_fp_val = round(f * (1 << this->_fractional_bits));
}

float Fixed::toFloat( void ) const 
{
	return (float)this->_fp_val / (1 << this->_fractional_bits);
}

int Fixed::toInt( void ) const 
{
	return (int)this->_fp_val >> this->_fractional_bits;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fp_val);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fp_val = raw;
}
