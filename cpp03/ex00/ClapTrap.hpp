#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string	name;
	int			hp;
	int			ep;
	int			atk;
public:
	ClapTrap(std::string name); // Constructor
	~ClapTrap() { std::cout << "A Claptrap called " << this->name << " was destroyed" << std::endl; }; // Destructor
	ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator overload
	ClapTrap(const ClapTrap& other); // Copy Constructor

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};
#endif