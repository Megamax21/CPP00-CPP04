#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string	name;

public:
	Zombie();
	~Zombie();
	std::string get_name();
	void set_name(std::string name);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
#endif