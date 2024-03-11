/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:01:35 by motoko            #+#    #+#             */
/*   Updated: 2024/03/11 16:02:59 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
    NOT_FOUND,
}	t_type;

class Converter {

	public:
		Converter(void);
		Converter(Converter const &converter);
		~Converter(void);
		Converter	&operator=(Converter const &converter);

		void		init(std::string input_str);

		std::string	toChar(void) const;
		std::string	toInt(void) const;
		std::string	toFloat(void) const;
		std::string	toDouble(void) const;

	private:
		t_type	_type;
		char	_c_converted_value;
		int		_i_converted_value;
		float	_f_converted_value;
		double	_d_converted_value;

		bool	_isInt(std::string);
		bool	_isFloat(std::string);
		bool	_isDouble(std::string);

};

#endif
