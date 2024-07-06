/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:21:40 by hiono             #+#    #+#             */
/*   Updated: 2024/06/27 18:56:51 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	_type = "blank";
	std::cout << "Animal " << _type << " is constructed" << "\n";
}

Animal::Animal(std::string type)
{
	_type = type;
	std::cout << "Animal " << _type << " is constructed" << "\n";
}

Animal::Animal(const Animal &rhs)
{
	_type = rhs.getType();
}

Animal	&Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal " << _type << " is destructed" << "\n";
}

void	Animal::makeSound() const
{
	std::cout << "Animal " << _type << "cannot make sound..." << "\n";
}

std::string	Animal::getType() const
{
	return _type;
}

void	Animal::setType(std::string type)
{
	_type = type;
}
