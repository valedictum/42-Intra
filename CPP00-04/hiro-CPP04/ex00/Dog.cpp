/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:55:17 by hiono             #+#    #+#             */
/*   Updated: 2024/06/27 18:50:57 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog " << _type << " is constructed" << "\n";
}

Dog::Dog(const Dog &rhs)
{
	_type = rhs.getType();
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog " << _type << " is destructed" << "\n";
}

void	Dog::makeSound() const
{
	std::cout << "WOWWWWWWWWWW" << "\n";
}
