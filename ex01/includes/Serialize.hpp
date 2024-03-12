/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:26:44 by tlorne            #+#    #+#             */
/*   Updated: 2024/03/12 16:21:50 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <exception>
# include <cstdlib>
# include <stdint.h>

# include "Data.hpp"

class Serializer
{
private:
            Serializer();
            Serializer(Serializer const & copy);
            Serializer &   operator=(Serializer const & rhs);
            ~Serializer();

public:
            static uintptr_t   serialize(Data *data);
            static Data *      deserialize(uintptr_t ptr);
};

#endif
