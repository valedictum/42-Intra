/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:26:08 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/08 13:27:49 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( void ) {}

HumanB::HumanB( std::string name )
{
	this->name = name;
}

HumanB::~HumanB( void )
{
	std::cout << "HumanB has been died." << std::endl;
}

void	HumanB::setWeapon( Weapon &newWeapon )
{
	this->weapon = &newWeapon;
}

void	HumanB::attack( void )
{
	std::cout << this->name << " attacks with their " \
		<< this->weapon->getType() << std::endl;
}
