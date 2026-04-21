/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:33:30 by ml-hote           #+#    #+#             */
/*   Updated: 2026/04/21 14:10:49 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called !" << std::endl;
	this->atk = 20;
	this->ep = 50;
	this->hp = 100;
}

ScavTrap::ScavTrap() 
{
	this->name = "ScavTrap";
	std::cout << "A ScavTrap was born" << std::endl;
	this->atk = 20;
	this->ep = 50;
	this->hp = 100;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);  // Call base class assignment operator
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap '" << this->name << "' is now in Gate Keeper mode !" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap Destructor] " << this->name << " / Derived class cleanup" << std::endl;
}