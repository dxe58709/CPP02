#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	Value = 0;	
}

//コピーコンストラクタ
Fixed::Fixed(const Fixed &othre)
{
	std::cout << "Copy constructor called" << std::endl;
	Value = (othre.getRawBits());
}

//コピー代入演算子
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->Value = other.getRawBits();
	return (*this);
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

Fixed::~Fixed()
{
	std::cout <<"Destructor called" <<std::endl;
}
