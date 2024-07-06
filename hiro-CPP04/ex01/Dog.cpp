/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:55:17 by hiono             #+#    #+#             */
/*   Updated: 2024/06/28 17:29:31 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Dog " << _type << " is constructed" << "\n";
	_brain = new Brain();
}

Dog::Dog(const Dog &rhs)
{
	_type = rhs.getType();
	_brain = new Brain(*rhs.getBrain());
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
	{
		_type = rhs.getType();
		delete _brain;
		_brain = new Brain(*rhs.getBrain());
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog " << _type << " is destructed" << "\n";
	delete _brain;
}

void	Dog::makeSound() const
{
	std::cout << "WOWWWWWWWWWW" << "\n";
}

Brain	*Dog::getBrain() const
{
	return _brain;
}

void	Dog::setBrain(Brain *brain)
{
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, brain->getIdea(i));
}
