#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

// My First Class in Orthodox Canonical Form
class Fixed
{
private:
	int	_fp_val;
	static const int _fractional_bits = 8;
public:
	Fixed() {this->_fp_val = 0; std::cout << "Default constructor called" << std::endl;}; // Default constructor 
	Fixed(const Fixed& other); // Copy Constructor
	Fixed& operator=(const Fixed& other); // Copy assignment operator overload
	~Fixed() {std::cout << "Destructor called" << std::endl;}; // Destructor

	Fixed(const int i);
	Fixed(const float f);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;
};

#endif