/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiono <hiono@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:24:19 by hiono             #+#    #+#             */
/*   Updated: 2024/06/28 16:55:21 by hiono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() :_name("aaaa")
{
	std::cout << "Character " << _name << " is constructed" << "\n";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_trash[i] = NULL;
}

Character::Character(std::string name) :_name(name)
{
	std::cout << "Character " << _name << " is constructed" << "\n";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_trash[i] = NULL;
}

Character::Character(const Character &rhs)
{
	_name = rhs.getName();
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		if (rhs.getInventory(i))
			_inventory[i] = rhs.getInventory(i)->clone();
	}
	for (int i = 0; i < 100; i++)
	{
		_trash[i] = NULL;
		if (rhs.getTrash(i))
			_trash[i] = rhs.getTrash(i)->clone();
	}
}

Character &Character::operator=(const Character &rhs)
{
	if (this == &rhs)
		return *this;
	_name = rhs.getName();
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		if (rhs.getInventory(i))
			_inventory[i] = rhs.getInventory(i)->clone();
	}
	for (int i = 0; i < 100; i++)
	{
		_trash[i] = NULL;
		if (rhs.getTrash(i))
			_trash[i] = rhs.getTrash(i)->clone();
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character " << _name << " is destructed" << "\n";
	clearInventory();
	clearTrash();
}

std::string const &Character::getName() const
{
	return _name;
}

AMateria *Character::getInventory(int index) const
{
	if (index < 0 || 3 < index)
	{
		std::cout << "\033[1;31mInvalid index for inventory. It should be 0 to 3\033[0m" << "\n";
		return NULL;
	}
	return _inventory[index];
}

AMateria *Character::getTrash(int index) const
{
	if (index < 0 || 99 < index)
	{
		std::cout << "\033[1;31mInvalid index for trash. It should be 0 to 99\033[0m" << "\n";
		return NULL;
	}
	return _trash[index];
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			continue ;
		_inventory[i] = m;
		return ;
	}
	std::cout << "\033[1;31mCharacter " << _name << "'s inventory is full and cannot store " << m->getType() << "\033[0m" << "\n";
}

void Character::unequip(int idx)
{
	if (idx < 0 || 3 < idx)
	{
		std::cout << "\033[1;31mInvalid index for inventory. It should be 0 to 3\033[0m" << "\n";
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << "\033[1;31mCharacter " << _name << " does not set materia in inventory " << idx << "\033[0m" << "\n";
		return ;
	}
	for (int i = 0; i < 100; i++)
	{
		if (_trash[i])
			continue ;
		_trash[i] = _inventory[i];
		_inventory[i] = NULL;
		return ;
	}
	std::cout << "\033[1;31mCharacter " << _name << "'s trahs is full\033[0m" << "\n";
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || 3 < idx)
	{
		std::cout << "\033[1;31mInvalid index for inventory. It should be 0 to 3\033[0m" << "\n";
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << "\033[1;31mCharacter " << _name << " does not set materia in inventory " << idx << "\033[0m" << "\n";
		return ;
	}
	_inventory[idx]->use(target);
}

void Character::clearInventory()
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
			continue ;
		delete _inventory[i];
		_inventory[i] = NULL;
	}
}

void Character::clearTrash()
{
	for (int i = 0; i < 100; i++)
	{
		if (!_trash[i])
			continue ;
		delete _trash[i];
		_trash[i] = NULL;
	}
}

