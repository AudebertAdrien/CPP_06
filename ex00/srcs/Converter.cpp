/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:03:25 by motoko            #+#    #+#             */
/*   Updated: 2024/03/11 16:30:58 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <limits>
#include <cmath>
#include "Converter.hpp"

Converter::Converter(void)
{
	std::cout << "Converter default constructor called" << std::endl;
}

Converter::Converter(Converter const &converter)
{
	std::cout << "Converter constructor by copy called" << std::endl;
	*this = converter;
}

Converter::~Converter(void)
{
	std::cout << "Converter destructor called" << std::endl;
}

Converter	&Converter::operator=(Converter const &converter)
{
	std::cout << "Converter operator= constructor called" << std::endl;
	this->_type = converter._type;
	this->_c_converted_value = converter._c_converted_value;
	this->_i_converted_value = converter._i_converted_value;
	this->_f_converted_value = converter._f_converted_value;
	this->_d_converted_value = converter._d_converted_value;
	return *this;
}

bool Converter::_isInt(std::string in)
{
	unsigned int	i;

	i = 0;
	if ((in[i] == '-' || in[i] == '+') && in.length() > 1)
		i++;
	for (; i < in.length(); i++)
	{
		if (!isdigit(in[i]))
			return false;
	}
	return true;
}

bool Converter::_isFloat(std::string in)
{
	unsigned int	i;
	bool			asPoint = false;
	bool			asF = false;

	i = 0;
	if (in == "inff" || in == "-inff" || in == "+inff" || in == "nanf")
		 return true;
	if ((in[i] == '-' || in[i] == '+') && in.length() > 1)
		i++;
	for (; i < in.length(); i++)
	{
		if (!isdigit(in[i]) && in[i] != 'f' && in[i] != '.')
			return false;
		if (in[i] == '.' && asPoint)
			return false;
		else if (in[i] == '.')
			asPoint = true;
		if (in[i] == 'f' && asF)
			return false;
		else if (in[i] == 'f')
			asF = true;
	}
	if (in[in.length() - 1] != 'f')
		return false;
	if (!asPoint)
		return false;
	return true;
}

bool Converter::_isDouble(std::string in)
{
	unsigned int	i;
	bool			asPoint = false;

	i = 0;
	if (in == "inf" || in == "-inf" || in == "+inf" || in == "nan")
		 return true;
	if ((in[i] == '-' || in[i] == '+') && in.length() > 1)
		i++;
	for (; i < in.length(); i++)
	{
		if (!isdigit(in[i]) && in[i] != '.')
			return false;
		if (in[i] == '.' && asPoint)
			return false;
		else if (in[i] == '.')
			asPoint = true;
	}
	if (!asPoint)
		return false;
	return true;
}

void	Converter::init(std::string input_str)
{
	if (input_str.length() == 1 && isalpha(input_str[0]) && isprint(input_str[0]))
	{
		this->_type = CHAR;
		this->_c_converted_value = input_str[0];
	}
	else if (this->_isInt(input_str))
	{
		this->_type = INT;
		std::stringstream ss(input_str);
		ss >> this->_i_converted_value;
	}
	else if (this->_isFloat(input_str))
	{
		this->_type = FLOAT;
		_f_converted_value = strtof(input_str.c_str(), NULL);
	}
	else if (this->_isDouble(input_str))
	{
		this->_type = DOUBLE;
		_d_converted_value = strtod(input_str.c_str(), NULL);
	}
	else
		this->_type = NOT_FOUND;
}

std::string	Converter::toChar(void) const
{
	char	c;

	switch (this->_type)
	{
		case CHAR:
			return "'" + std::string(1, this->_c_converted_value) + "'";
			break ;
		case INT:
			c = static_cast<char>(_i_converted_value);
			break ;
		case FLOAT:
			if (isnan(_f_converted_value)
					|| _f_converted_value == std::numeric_limits<float>::infinity()
					|| _f_converted_value == -std::numeric_limits<float>::infinity())
				return "Impossible";
			c = static_cast<char>(_f_converted_value);
			break ;
		case DOUBLE:
			if (isnan(_d_converted_value)
					|| _d_converted_value == std::numeric_limits<double>::infinity()
					|| _d_converted_value == -std::numeric_limits<double>::infinity())
				return "Impossible";
			c = static_cast<char>(_d_converted_value);
			break ;
		case NOT_FOUND:
			return "Impossible";
			break ;
	}
	if (isprint(c))
		return "'" + std::string(1, c) + "'";
	else
		return "Impossible";
}

std::string	Converter::toInt(void) const
{
	std::string out;
	std::stringstream ss;

	switch (this->_type)
	{
		case CHAR:
			ss << static_cast<int>(_c_converted_value);
			break ;
		case INT:
			ss << _i_converted_value;
			break ;
		case FLOAT:
			if (isnan(_f_converted_value)
					|| _f_converted_value == std::numeric_limits<float>::infinity()
					|| _f_converted_value == -std::numeric_limits<float>::infinity())
				return "Impossible";
			ss << static_cast<int>(_f_converted_value);
			break ;
		case DOUBLE:
			if (isnan(_d_converted_value)
					|| _d_converted_value == std::numeric_limits<double>::infinity()
					|| _d_converted_value == -std::numeric_limits<double>::infinity())
				return "Impossible";
			ss << static_cast<int>(_d_converted_value);
			break ;
		case NOT_FOUND:
			return "Impossible";
			break ;
	}
	ss >> out;
	return out;
}

std::string	Converter::toFloat(void) const
{
	std::string out;
	std::stringstream ss;

	switch (this->_type)
	{
		case CHAR:
			ss << static_cast<float>(_c_converted_value);
			break ;
		case INT:
			ss << _i_converted_value;
			break ;
		case FLOAT:
			ss << static_cast<float>(_f_converted_value);
			break ;
		case DOUBLE:
			ss << static_cast<float>(_d_converted_value);
			break ;
		case NOT_FOUND:
			return "Impossible";
			break ;
	}
	ss >> out;
	if (out.find('.') == std::string::npos && out != "-inf" && out != "inf" && out != "nan")
            out.append(".0");
	return out + "f";
}

std::string	Converter::toDouble(void) const
{
	std::string out;
	std::stringstream ss;

	switch (this->_type)
	{
		case CHAR:
			ss << static_cast<double>(_c_converted_value);
			break ;
		case INT:
			ss << _i_converted_value;
			break ;
		case FLOAT:
			ss << static_cast<double>(_f_converted_value);
			break ;
		case DOUBLE:
			ss << static_cast<double>(_d_converted_value);
			break ;
		case NOT_FOUND:
			return "Impossible";
			break ;
	}
	ss >> out;
	if (out.find('.') == std::string::npos && out != "-inf" && out != "inf" && out != "nan")
            out.append(".0");
	return out;
}
