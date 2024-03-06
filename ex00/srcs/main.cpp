/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:27:16 by motoko            #+#    #+#             */
/*   Updated: 2024/03/06 16:58:09 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#include "Converter.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cout << "error: need one argument!" << std::endl;
		return EXIT_FAILURE;
	}

	Converter c;

	try {
		
		c.init(argv[1]);

		std::cout << c << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Error: "<< e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}
