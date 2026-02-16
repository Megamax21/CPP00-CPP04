/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:43:14 by ml-hote           #+#    #+#             */
/*   Updated: 2026/02/16 23:04:25 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"
/*
	Zombie();
	~Zombie();
	std::string get_name();
	void set_name(std::string);
	*/

Zombie::Zombie()
{
	this->name = "";
}

Zombie::~Zombie()
{
	std::cout << "Obliterated " << this->name << std::endl;
}

std::string	Zombie::get_name()
{
	return (this->name);
}

void	Zombie::set_name(std::string name)
{
	
}