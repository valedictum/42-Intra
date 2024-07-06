/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:55:17 by hiono             #+#    #+#             */
/*   Updated: 2024/06/27 18:50:40 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Cat " << _type << " is constructed" << "\n";
}

Cat::Cat(const Cat &rhs)
{
	_type = rhs.getType();
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat " << _type << " is destructed" << "\n";
}

void	Cat::makeSound() const
{
	std::cout << "MEOWWWWWW" << "\n";
}
