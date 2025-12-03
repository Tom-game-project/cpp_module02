#include "Fixed.hpp"
#include <iostream>

// Orthodox Canonical Form

Fixed::Fixed ():_fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed () {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	// other.getRawBits() を呼ぶことで出力例の挙動を再現します
	// 単に this->_fixedPointValue = other._fixedPointValue; でも機能的には同じですが、
	// 課題の出力要件によっては getRawBits のログが必要な場合があります。
	this->_fixedPointValue = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;

	// 1. 自己代入チェック (Self-assignment check)
	// アドレスが同じなら、コピー処理をスキップしてそのまま返す
	if (this == &other) {
		// do nothing
	} else {
		// 2. 値のコピー
		// Exercise 00の出力例に従い、getRawBits()経由で値を取得する
		this->_fixedPointValue = other.getRawBits();
	}

	// 3. 自分自身への参照を返す
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

