#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	Value = 0;	
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(num << _RawBitLiteral);
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(num * (1 << _RawBitLiteral)));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	Value = (other.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->Value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout <<"Destructor called" <<std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (Value);
}

void	Fixed::setRawBits(int const raw)
{
	Value = raw;
}

float	Fixed::toFloat() const //固定小数点値を浮動小数点に変換
{
	return (static_cast<float>(this->Value) / (1 << _RawBitLiteral));
}

int	Fixed::toInt() const //固定小数点値を整数に変換
{
	return (this->Value >> _RawBitLiteral);
}

//<< a
std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
	os << fixed.toFloat();
	return (os);
}
