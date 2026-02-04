/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_1.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:04:39 by ml-hote           #+#    #+#             */
/*   Updated: 2026/02/04 18:06:58 by ml-hote          ###   ########.fr       */
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