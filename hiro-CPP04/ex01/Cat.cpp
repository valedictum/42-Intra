/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:55:17 by hiono             #+#    #+#             */
/*   Updated: 2024/06/28 17:29:49 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Cat " << _type << " is constructed" << "\n";
	_brain = new Brain();
}

Cat::Cat(const Cat &rhs)
{
	_type = rhs.getType();
	_brain = new Brain(*rhs.getBrain());
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		_type = rhs.getType();
		delete _brain;
		_brain = new Brain(*rhs.getBrain());
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat " << _type << " is destructed" << "\n";
	delete _brain;
}

void	Cat::makeSound() const
{
	std::cout << "MEOWWWWWW" << "\n";
}

Brain	*Cat::getBrain() const
{
	return _brain;
}

void	Cat::setBrain(Brain *brain)
{
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, brain->getIdea(i));
}
