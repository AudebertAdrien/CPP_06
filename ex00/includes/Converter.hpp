/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:03:33 by motoko            #+#    #+#             */
/*   Updated: 2024/03/06 17:12:47 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE    "\033[94m"
#define YELLOW  "\033[93m"
#define MAGENTA "\033[95m"

class Converter {
	public:
		Converter();
		Converter(Converter const &src);
		Converter& operator=(Converter const &src);
		~Converter();

		void	init(std::string str);

		/* == is what it is == */
		bool	isChar(void) const;

		/* == Getter == */
		char	getC() const;
		int		getN() const;
		float	getF() const;
		double	getD() const;

		/* == Setter == */
		void	setC(char c);
		void	setN(int n);
		void	setF(float f);
		void	setD(double d);
		
		/* == Display == */
		void	printChar(void) const;
		void	printInt(void) const;
		void	printFloat(void) const;
		void	printDouble(void) const;

		class ConverterExecption : public std::exception {
			virtual const char* what() const throw() { 
				return "Unknown type"; 
			}
		};

	private:
		char 		_c;
		int			_n;
		float		_f;
		double		_d;

		std::string	_str;
};

std::ostream& operator<<(std::ostream &o, const Converter &rhs);

#endif
