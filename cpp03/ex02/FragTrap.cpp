/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 21:33:30 by ml-hote           #+#    #+#             */
/*   Updated: 2026/03/27 01:31:43 by ml-hote          ###   ########.fr       */
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
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " raises its metal hand part waiting for an high fives" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap Destructor] " << this->name << " / Derived class cleanup" << std::endl;
}