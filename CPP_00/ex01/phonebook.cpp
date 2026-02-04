/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:58:16 by ml-hote           #+#    #+#             */
/*   Updated: 2026/02/04 18:07:10 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	PhoneBook::check_if_contact(void)
{
	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i].get_existing() == true)
			return (1);
	}
	return (0);
}

std::string	PhoneBook::get_short_str(std::string s)
{
	std::string shortened_str;
	
	shortened_str = s;
	if (shortened_str.length() > 10)
	{
		shortened_str.resize(10);
		shortened_str.shrink_to_fit();
		shortened_str[9] = '.';
	}
	else
	{
		for (int i = shortened_str.length(); i < 10; i++)
			shortened_str += " ";
	}
	return (shortened_str);
} 

int	PhoneBook::show_list(void)
{
	if (this->check_if_contact() == 0)
	{
		std::cout << "No contact created yet ! Use the `ADD` command !" << std::endl;
		return (1);
	}
	std::cout << std::endl << "|----------|----------|----------|----------|" << std::endl;
	std::cout << "|  index   |first name|last  name| nickname |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i].get_existing() == true)
		{
			std::cout << "|    " << this->contacts[i].get_id() << "     |"
				<< this->get_short_str(this->contacts[i].get_first_name());
			std::cout << "|" << this->get_short_str(this->contacts[i].get_last_name());
			std::cout << "|" << this->get_short_str(this->contacts[i].get_nickname())
				<< "|" << std::endl;
			std::cout << "|----------|----------|----------|----------|" << std::endl;
		}
	}
	std::cout << std::endl;
	return (0);
}

int	PhoneBook::present_contact(int id)
{
	int id_free;
	
	id_free = this->get_free_id();
	if (id_free == -1)
		id_free = 8;
	if (id < 1 || id > id_free)
	{
		std::cout << "Value must be between 1 and " << id_free << std::endl;
		return (0);
	}
	else
	{
		id--;
		std::cout << "This is " << this->contacts[id].get_first_name()
			<< " \"" << this->contacts[id].get_nickname() << "\" "
			<< this->contacts[id].get_last_name() << std::endl;
		std::cout << "You can call them at : "
			<< this->contacts[id].get_phone_number() << std::endl;
		std::cout << "And their darkest secret is : " << std::endl
			<< this->contacts[id].get_darkest_secret() << std::endl;
	}
	return (1);
}

int	PhoneBook::is_digit(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}
	return (0);
}
