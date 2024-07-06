/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:01:09 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/08 13:20:35 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) {
	std::cout << "default init" << std::endl;
}

Weapon::Weapon( std::string type )
{
	this->type = type;
}

Weapon::~Weapon( void )
{
	std::cout << "Weapon has been destroyed." << std::endl;
}

const std::string	Weapon::getType( void ) const
{
	return (this->type);
}

void	Weapon::setType( std::string newType )
{
	this->type = newType;
}
