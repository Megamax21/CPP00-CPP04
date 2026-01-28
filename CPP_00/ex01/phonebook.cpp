/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:58:16 by ml-hote           #+#    #+#             */
/*   Updated: 2026/01/28 22:54:42 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "Welcome to your phone book" << std::endl;
	for (int i = 0; i < 8; i++)
		this->contacts[i].set_id(i + 1);
}

int	PhoneBook::phone_book_loop(void)
{
	std::string	prompt;
	int			selection;
	
	std::cout << "Input command (ADD/SEARCH/EXIT) : ";
	std::getline(std::cin, prompt);
	selection = get_prompt_value(prompt);
	switch (selection)
	{
	case 0:
		this->fill_contact();
		break;
	case 1:
		if (this->show_list() == 0)
			while (this->search_loop() == 0);
		break;
	case 2:
		return (1);
		break;
	default:
		break;
	}
	return (0);
}

int	PhoneBook::search_loop(void)
{
	std::string prompt;

	std::cout << "Enter ID : ";
	std::getline(std::cin, prompt);
	if (this->is_digit(prompt) == 1)
	{
		std::cout << "Not a valid value" << std::endl;
		return (0);
	}
	else
		return (this->present_contact(atoi(prompt.c_str())));
	return (0);
}

int	PhoneBook::get_prompt_value(std::string prompt)
{
	if (prompt == "ADD")
		return (0);
	else if (prompt == "SEARCH")
		return (1);
	else if (prompt == "EXIT")
		return (2);
	else
		return (-1);
}

int	PhoneBook::get_free_id(void)
{
	for (int i = 0; i < 8; i++)
	{
		if (this->contacts[i].get_existing() == false)
			return (i);
	}
	return (-1);
}

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
		id_free = 7;
	if (id < 1 || id > id_free)
	{
		std::cout << "Value must be betwin 1 and " << id_free << std::endl;
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
