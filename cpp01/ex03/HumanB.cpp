/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 19:13:52 by ml-hote           #+#    #+#             */
/*   Updated: 2026/03/24 11:16:06 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB()
{
	this->name = "defaultName";
	this->weapon = NULL;
}

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
	std::cout << "Destroyed " << this->name << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void	HumanB::setName(std::string name)
{
	this->name = name;
}

Weapon	*HumanB::getWeapon(void)
{
	return (this->weapon);
}

std::string	HumanB::getName(void)
{
	return (this->name);
}

void HumanB::attack()
{
	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon" << std::endl;
}
