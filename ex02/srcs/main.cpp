/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:55:14 by motoko            #+#    #+#             */
/*   Updated: 2024/03/12 16:55:15 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "BaseA.hpp"
#include "BaseB.hpp"
#include "BaseC.hpp"
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
	Base *ret;
	int num = rand() % 100;

	if (num < 33)
	{
		std::cout << "Base A generate" << std::endl;
		ret = new BaseA;
	}
	else if (num < 66)
	{
		std::cout << "Base B generate" << std::endl;
		ret = new BaseB;
	}
	else
	{
		std::cout << "Base C generate" << std::endl;
		ret = new BaseC;
	}
	return (ret);
}

void	identify(Base *p)
{
	std::cout << "Identify by ptr" << std::endl;
	if (dynamic_cast<BaseA*>(p))
		std::cout << "It's a base A" << std::endl;
	if (dynamic_cast<BaseB*>(p))
		std::cout << "It's a base B" << std::endl;
	if (dynamic_cast<BaseC*>(p))
		std::cout << "It's a base C" << std::endl;
}

void	identify(Base & p)
{
	std::cout << "Identify by ref" << std::endl;
	if (dynamic_cast<BaseA*>(&p))
		std::cout << "A";
	if (dynamic_cast<BaseB*>(&p))
		std::cout << "B";
	if (dynamic_cast<BaseC*>(&p))
		std::cout << "C";
}

int         main()
{
    srand(time(NULL));
    int i = 0;
    while (i < 100)
    {
    	std::cout << "Test :" << i << std::endl;
		Base *ptr = generate();
		Base &ref = *ptr;
		identify(ptr);
		identify(ref);
		std::cout << std::endl;
		std::cout << std::endl;
        i++;
		delete ptr;
    }
}
