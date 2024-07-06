/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:21:40 by hiono             #+#    #+#             */
/*   Updated: 2024/06/27 19:00:08 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "blank";
	std::cout << "WrongAnimal " << _type << " is constructed" << "\n";
}

WrongAnimal::WrongAnimal(std::string type)
{
	_type = type;
	std::cout << "WrongAnimal " << _type << " is constructed" << "\n";
}

WrongAnimal::WrongAnimal(WrongAnimal &rhs)
{
	_type = rhs.getType();
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal " << _type << " is destructed" << "\n";
}

void		WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal " << _type << "cannot make sound..." << "\n";
}

std::string	WrongAnimal::getType() const
{
	return _type;
}

void		WrongAnimal::setType(std::string type)
{
	_type = type;
}
