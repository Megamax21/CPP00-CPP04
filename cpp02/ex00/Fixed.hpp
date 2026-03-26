#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

/*
• Private members:
◦ An integer to store the fixed-point number value.
◦ A static constant integer to store the number of fractional bits. Its value
will always be the integer literal 8.
• Public members:
◦ A default constructor that initializes the fixed-point number value to 0.
◦ A copy constructor.
◦ A copy assignment operator overload.
◦ A destructor.
◦ A member function int getRawBits( void ) const;
that returns the raw value of the fixed-point value.
◦ A member function void setRawBits( int const raw );
that sets the raw value of the fixed-point number
*/


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

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif