/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_2.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:07:21 by ml-hote           #+#    #+#             */
/*   Updated: 2026/02/04 18:07:22 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*	renew_contacts
	When contact list is full in phone book :
	shift all contacts right and move the last one to the front
	so the oldest contact is always at index 0	
*/
void	PhoneBook::renew_contacts(void)
{
	Contact temp = this->contacts[7];
	for (int i = 7; i > 0; i--)
		this->contacts[i] = this->contacts[i - 1];
	this->contacts[0] = temp;
	for (int j = 0; j < 8; j++)
		this->contacts[j].set_id(j + 1);
	this->contacts[0].set_existing(false);
}

/*The contact fields are: first name, last name, nickname, phone number, and
darkest secret.*/
void	PhoneBook::fill_contact(void)
{
	int	id;
	
	id = get_free_id();
	if (id == -1)
	{
		id = 0;
		this->renew_contacts();
	}
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string darkest_secret;
	std::cout << "First name : ";
	std::getline(std::cin, first_name);
	std::cout << "Last name : ";
	std::getline(std::cin, last_name);
	std::cout << "Nickname : ";
	std::getline(std::cin, nickname);
	std::cout << "Phone number : ";
	std::getline(std::cin, phone_number);
	std::cout << "Darkest secret : ";
	std::getline(std::cin, darkest_secret);
	this->contacts[id].set_contact(first_name, last_name,
		nickname, phone_number, darkest_secret);
}
