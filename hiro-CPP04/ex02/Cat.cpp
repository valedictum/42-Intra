/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:55:17 by hiono             #+#    #+#             */
/*   Updated: 2024/06/28 17:31:53 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): AAnimal("Cat")
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
	std::cout << "MEOWWWW" << "\n";
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
