/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:26:49 by tlorne            #+#    #+#             */
/*   Updated: 2024/01/09 16:26:51 by tlorne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

uintptr_t	Serializer::serialize(Data *data)
{
	return (reinterpret_cast<uintptr_t>(data));
}

Data*	Serializer::deserialize(uintptr_t ptr)
{
	return (reinterpret_cast<Data*>(ptr));
}
