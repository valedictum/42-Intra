/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:53:13 by hiono             #+#    #+#             */
/*   Updated: 2024/06/26 15:27:39 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain is constructed" << "\n";
}

Brain::Brain(Brain &rhs)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = rhs._ideas[i];
}

Brain &Brain::operator=(Brain &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain is destructed" << "\n";
}

std::string Brain::getIdea(size_t index) const
{
	if (100 <= index)
		return NULL;
	return _ideas[index];
}

void	Brain::setIdea(size_t index, std::string idea)
{
	if (100 <= index)
		return;
	_ideas[index] = idea;
}
