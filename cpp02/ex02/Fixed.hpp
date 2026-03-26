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
	~Fixed() {std::cout << "Destructor called" << std::endl;}; // Destructor

	Fixed(const int i);
	Fixed(const float f);

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );

	float	toFloat( void ) const;
	int		toInt( void ) const;

	//>, <, >=, <=, ==, and !=
	// Assignment Operators Overload :
	Fixed&	operator=(const Fixed& other); // Copy assignment operator overload
	bool	operator<(const Fixed& other) const;
	bool	operator>(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;
	// The 4 arithmetic operators: +, -, *, and /.
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;
	// The 4 incremental operators: ++ --
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
/*
• A static member function min that takes two references to fixed-point numbers as
parameters, and returns a reference to the smallest one.
• A static member function min that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the smallest one.
• A static member function max that takes two references to fixed-point numbers as
parameters, and returns a reference to the greatest one.
• A static member function max that takes two references to constant fixed-point
numbers as parameters, and returns a reference to the greatest one.
*/
	static Fixed&	min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

#endif