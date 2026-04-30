/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ml-hote <ml-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 03:12:04 by ml-hote           #+#    #+#             */
/*   Updated: 2026/04/30 16:05:24 by ml-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "=== Test 1: Basic dynamic dispatch ===" << std::endl;
	Animal* zoo[4];
	zoo[0] = new Dog();
	zoo[1] = new Cat();
	zoo[2] = new Dog();
	zoo[3] = new Cat();

	for (int i = 0; i < 4; ++i)
	{
		std::cout << "Type: " << zoo[i]->getType() << " | Sound: ";
		zoo[i]->makeSound();
	}

	std::cout << std::endl;
	std::cout << "=== Test 2: Base object behavior ===" << std::endl;
	Animal base;
	std::cout << "Type: " << base.getType() << " | Sound: ";
	base.makeSound();

	std::cout << std::endl;
	std::cout << "=== Test 3: Deletion through ABS_Animal* (virtual destructor) ===" << std::endl;
	for (int i = 0; i < 4; ++i)
		delete zoo[i];

	return 0;
}