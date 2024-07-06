/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:21:40 by hiono             #+#    #+#             */
/*   Updated: 2024/06/26 18:22:02 by hiono            ###   ########.fr       */
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

void		Animal::makeSound() const
{
	if (_type == "Cat")
		std::cout << "Miaooowwwwww" << "\n";
	else if (_type == "Dog")
		std::cout << "Wooooof" << "\n";
	else
		std::cout << "No onomatopoia for this animal" << "\n";
}

std::string	Animal::getType() const
{
	return _type;
}

void		Animal::setType(std::string type)
{
	_type = type;
}
