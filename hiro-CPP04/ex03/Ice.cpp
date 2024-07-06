/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:36:44 by hiono             #+#    #+#             */
/*   Updated: 2024/06/28 18:03:48 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << "Ice " << _type << " is construced" << "\n";
}

Ice::Ice(const Ice &rhs): AMateria("ice")
{
	(void)rhs;
}

Ice &Ice::operator=(const Ice &rhs)
{
	(void)rhs;
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice " << _type << " is destruced" << "\n";
}

Ice 	*Ice::clone() const
{
	Ice *clone = new Ice();
	return clone;
}

void	Ice::use(ICharacter &target)
{
	std::cout << "\033[1;31m* shoots an ice bolt at " << target.getName() << " *\033[0m" << "\n";
}
