/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 15:36:44 by hiono             #+#    #+#             */
/*   Updated: 2024/06/28 18:04:13 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << "Cure " << _type << " is construced" << "\n";
}

Cure::Cure(const Cure &rhs): AMateria("cure")
{
	(void)rhs;
}

Cure &Cure::operator=(const Cure &rhs)
{
	(void)rhs;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure " << _type << " is destruced" << "\n";
}

Cure 	*Cure::clone() const
{
	Cure *clone = new Cure();
	return clone;
}

void	Cure::use(ICharacter &target)
{
	std::cout << "\033[1;31m* heals " << target.getName() << "'s wounds *\033[0m" << "\n";
}
