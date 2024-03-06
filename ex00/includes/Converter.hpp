/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:03:33 by motoko            #+#    #+#             */
/*   Updated: 2024/03/06 15:41:15 by motoko           ###   ########.fr       */
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

		/* == Getter == */
		char	getC() const;
		int		getN() const;
		float	getF() const;
		double	getD() const;
		
		/* == Display == */
		void	printChar(void) const;
		void	printInt(void) const;
		void	printFloat(void) const;
		void	printDouble(void) const;

	private:
		char 	_c;
		int		_n;
		float	_f;
		double	_d;
};

std::ostream& operator<<(std::ostream &o, const Converter &rhs);

#endif
