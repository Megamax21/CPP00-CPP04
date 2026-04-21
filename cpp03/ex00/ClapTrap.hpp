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
	ClapTrap();
	ClapTrap(std::string name); // Constructor
	~ClapTrap(); // Destructor
	ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator overload
	ClapTrap(const ClapTrap& other); // Copy Constructor

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};
#endif