/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:33:30 by ml-hote           #+#    #+#             */
/*   Updated: 2026/04/21 11:33:16 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called !" << std::endl;
	this->atk = 30;
	this->ep = 100;
	this->hp = 100;
}

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap constructor called !" << std::endl;
	this->atk = 30;
	this->ep = 100;
	this->hp = 100;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);  // Call base class assignment operator
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " raises its metal hand part waiting for an high fives" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap Destructor] " << this->name << " / Derived class cleanup" << std::endl;
}