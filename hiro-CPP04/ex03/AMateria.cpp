/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:05:24 by hiono             #+#    #+#             */
/*   Updated: 2024/06/27 16:59:24 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() :_type("not defined")
{
	std::cout << "AMateria " << _type << " is constructed" << "\n";
}

AMateria::AMateria(const AMateria &rhs)
{
	_type = rhs.getType();
}

AMateria &AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria " << _type << " is destructed" << "\n";
}

AMateria::AMateria(std::string const &type)
{
	_type = type;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
