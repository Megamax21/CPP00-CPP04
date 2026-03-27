/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:33:30 by ml-hote           #+#    #+#             */
/*   Updated: 2026/03/27 01:24:34 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	std::cout << "A ClapTrap called "<< name <<" was born" << std::endl;
	this->atk = 0;
	this->ep = 10;
	this->hp = 10;
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Cloned a ClapTrap " << std::endl;
	this->atk = other.atk;
	this->ep = other.ep;
	this->hp = other.hp;
	this->name = other.name;
}


ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->atk = other.atk;
	this->ep = other.ep;
	this->hp = other.hp;
	this->name = other.name;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->ep > 0 && this->hp > 0)
	{
		this->ep --;
		std::cout << "ClapTrap " << this->name << " attacks "<< target <<", causing "<<
			this->atk <<" points of damage! ("<< this->ep <<" ep left)"<< std::endl;
	}
	else
		std::cout << this->name << " is out of energy or hit points !" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp >0)
	{
		this->hp -= amount;
		std::cout << this->name << " just took " << amount << " damages ! ";
		if (this->hp < 0)
		{
			std::cout << "And just broke !";
			this->hp = 0;
		}
		std::cout << std::endl;
	}
	else
		std::cout << this->name << " took "<< amount <<" damages but was already broken !" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->ep > 0 && this->hp > 0)
	{
		this->hp += amount;
		this->ep --;
		std::cout << this->name << " repairs himself for " << amount << " hp ! And still has " << this->ep << " energy points ! " << std::endl;
	}
	else
		std::cout << this->name << " tries repairing himself but can't because it is out of energy or hp !" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap Destructor] " << this->name << " was destroyed" << std::endl;
}

