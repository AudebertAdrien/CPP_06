/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:09:12 by motoko            #+#    #+#             */
/*   Updated: 2024/03/06 17:19:30 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter() {
	std::cout << "Converter default constructor called" << std::endl;
	_c = '\0';
	_n = 0;
	_f = 0.0f;
	_d = 0.0;
}

Converter::Converter(Converter const &src) {
	std::cout << "Converter constructor by copy called" << std::endl;
	*this = src;
}

Converter& Converter::operator=(Converter const &src) {
	std::cout << "Converter operator= constructor called" << std::endl;

	if (this != &src) {
	}

	return (*this);
}

Converter::~Converter() {
	std::cout << "Converter destructor called" << std::endl;
}

void	Converter::init(std::string str) {
	std::cout << str << std::endl;
	this->_str = str;
}

/* == is what it is == */
bool	Converter::isChar(void) const {
	return (this->_str.length() == 1 && isalpha(this->_str[0]) && isprint(this->_str[0]));	
}

/* == Getter == */
char	Converter::getC() const {
	return (this->_c);
}

int		Converter::getN() const {
	return (this->_n);
}

float	Converter::getF() const {
	return (this->_f);
}

double	Converter::getD() const {
	return (this->_d);
}

/* == Setter == */
void	Converter::setC(char c) {
	this->_c = c;
}

void		Converter::setN(int n) {
	this->_n = n;
}

void	Converter::setF(float f) {
	this->_f = f;
}

void	Converter::setD(double d) {
	this->_d = d;
}

/* == Display == */
void	Converter::printChar(void) const {
	std::cout << this->getC() << std::endl;
}

void	Converter::printInt(void) const {
	std::cout << this->getN() << std::endl;
}

void	Converter::printFloat(void) const {
	std::cout << this->getF() << std::endl;
}

void	Converter::printDouble(void) const {
	std::cout << this->getD() << std::endl;
}

std::ostream& operator<<(std::ostream &o, const Converter &rhs) {
	o << "char: "; rhs.printChar();
	o << "int: "; rhs.printInt();
	o << "flat: "; rhs.printFloat();
	o << "double: "; rhs.printDouble();
	return (o);
}
