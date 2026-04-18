#ifndef ABS_Animal_HPP
#define ABS_Animal_HPP

#include <string>
#include <iostream>

class ABS_Animal
{
protected:
	std::string	type;
	ABS_Animal();
	ABS_Animal(const ABS_Animal& other);
public:
	ABS_Animal& operator=(const ABS_Animal& other);
	virtual ~ABS_Animal();

	const std::string& getType() const;
	virtual void makeSound() const = 0;
};

#endif