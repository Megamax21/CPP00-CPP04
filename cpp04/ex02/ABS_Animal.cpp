/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ABS_Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 03:12:04 by ml-hote           #+#    #+#             */
/*   Updated: 2026/03/27 13:50:58 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ABS_Animal.hpp"

ABS_Animal::ABS_Animal()
{
	this->type = "ABS_Animal";
	std::cout << "ABS_Animal default constructor called" << std::endl;
}

ABS_Animal::ABS_Animal(const ABS_Animal& other)
{
	this->type = other.type;
	std::cout << "ABS_Animal copy constructor called" << std::endl;
}

ABS_Animal& ABS_Animal::operator=(const ABS_Animal& other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	std::cout << "ABS_Animal copy assignment operator called" << std::endl;
	return (*this);
}

ABS_Animal::~ABS_Animal()
{
	std::cout << "ABS_Animal destructor called" << std::endl;
}

const std::string& ABS_Animal::getType() const
{
	return (this->type);
}
