/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:01:03 by motoko            #+#    #+#             */
/*   Updated: 2024/03/11 16:01:22 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

int     main(int argc, char const **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of parameters." << std::endl;
		std::cout << "Usage: 1 parameter max." << std::endl;
		return 1;
	}

	Converter	converter;
	converter.init(std::string(argv[1]));

	std::cout << "char: " << converter.toChar() << std::endl;
	std::cout << "int: " << converter.toInt() << std::endl;
	std::cout << "float: " << converter.toFloat() << std::endl;
	std::cout << "double: " << converter.toDouble() << std::endl;
	
	return 0;
}
