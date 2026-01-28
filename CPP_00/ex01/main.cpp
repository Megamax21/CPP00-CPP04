/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 00:41:43 by ml-hote           #+#    #+#             */
/*   Updated: 2026/01/28 18:52:07 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	PhoneBook my_phonebook;
	while (my_phonebook.phone_book_loop() == 0);
	return (0);
}