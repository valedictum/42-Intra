/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:10:41 by hiono             #+#    #+#             */
/*   Updated: 2024/06/28 18:13:33 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_memory[i] = NULL;
	std::cout << "MateriaSource is constructed" << "\n";
}

MateriaSource::MateriaSource(const MateriaSource &rhs)
{
	clearMemories();
	for (int i = 0; i < 4; i++)
	{
		_memory[i] = NULL;
		if (rhs.getMemory(i))
			_memory[i] = rhs.getMemory(i)->clone();
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

MateriaSource::~MateriaSource()
{
	clearMemories();
	std::cout << "MateriaSource is destructed" << "\n";
}
	
AMateria	*MateriaSource::getMemory(int idx) const
{
	if (idx < 0 || 3 < idx)
	{
		std::cout << "\033[1;31mInvalid index for memory. It should be 0 to 3\033[0m" << "\n";
		return NULL;
	}
	return _memory[idx];
}

void		MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_memory[i])
			continue ;
		_memory[i] = m; 
		if (_memory[i])
		return ;
	}
	std::cout << "\033[1;31mMemories are full in MemorySource\033[0m" << "\n";
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_memory[i] || _memory[i]->getType() != type)
			continue ;
		return _memory[i]->clone();
	}
	std::cout << "\033[1;31mCannot find type " << type << " in memories\033[0m" << "\n";
	return 0;
}

void	MateriaSource::clearMemories()
{
	for (int i = 0; i < 4; i++)
	{
		if (!_memory[i])
			continue ;
		delete _memory[i];
		_memory[i] = NULL;
	}
}
