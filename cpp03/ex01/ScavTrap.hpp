#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap 
{
public:
	ScavTrap(std::string name);
	ScavTrap();
	ScavTrap(const ScavTrap& other);
	~ScavTrap();
	void	guardGate();
	ScavTrap& operator=(const ScavTrap& other);
};
#endif