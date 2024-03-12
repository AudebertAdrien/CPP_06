/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:41:22 by motoko            #+#    #+#             */
/*   Updated: 2024/03/12 16:42:23 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main()
{
	Data *test = new Data;

	uintptr_t seria_test;
	Data *retest;


    test->n = 5;
	std::cout << "Data address : " << test << " with value " << test->n << std::endl;
	seria_test = Serializer::serialize(test);

	std::cout << "Serialize : " << seria_test << std::endl;
	retest = Serializer::deserialize(seria_test);

	std::cout << "Adresse after deserialize : " << retest << " with value " << retest->n << std::endl;

    delete test;
	return 0;
}
