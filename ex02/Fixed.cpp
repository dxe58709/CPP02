#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	Value = 0;	
}

Fixed::Fixed(const int num)
{
	//std::cout << "Int constructor called" << std::endl;
	setRawBits(num << _RawBitLiteral);
}

Fixed::Fixed(const float num)
{
	//std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(num * (1 << _RawBitLiteral)));
}

Fixed::Fixed(const Fixed &other)
{
	//std::cout << "Copy constructor called" << std::endl;
	Value = (other.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->Value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	//std::cout <<"Destructor called" <<std::endl;
}

int	Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (Value);
}

void	Fixed::setRawBits(int const raw)
{
	Value = raw;
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(this->Value) / (1 << _RawBitLiteral));
}

int	Fixed::toInt() const
{
	return (this->Value >> _RawBitLiteral);
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
	os << fixed.toFloat();
	return (os);
}

// 比較演算子: >, <, >=, <=, == and !=.
bool Fixed::operator>(const Fixed &other) const
{
	return (Value > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (Value < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other)const 
{
	return (Value >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other)const 
{
	return (Value <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other)const 
{
	return (Value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other)const 
{
	return (Value != other.getRawBits());
}

// 算術演算子: +, -, *, and /.
Fixed Fixed::operator+(const Fixed &other)const 
{
	Fixed result(this->toFloat() + other.toFloat());
	return (result);
}

Fixed Fixed::operator-(const Fixed &other)const 
{
	Fixed result(this->toFloat() - other.toFloat());
	return (result);
}

Fixed Fixed::operator*(const Fixed &other)const 
{
	Fixed result(this->toFloat() * other.toFloat());
	return (result);
}
/*
Fixed operator/(const Fixed &other) const {
        if (other.getRawBits() == 0)
            throw DivisionByZeroError();
        // ここで割り算処理を行う
        return Fixed();
    }
    int getRawBits() const { return 0; }  // ダミーのメソッド
}

Fixed Fixed::operator/(const Fixed &other)const 
{ 
    if (other.getRawBits() == 0)
        throw std::runtime_error("Division by zero!");
    return Fixed(this->toFloat() / other.toFloat()); 
}
*/

// インクリメント/デクリメント演算子（前置き）
Fixed& Fixed::operator++() {
    Value++;
    return *this;
}

Fixed& Fixed::operator--() {
    Value--;
    return *this;
}

// インクリメント/デクリメント演算子（後置き）
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    Value++;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    Value--;
    return temp;
}

// 静的メンバ関数: min と max
Fixed& Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}
