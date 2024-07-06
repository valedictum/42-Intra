/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:23:30 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/08 13:27:45 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) \
	: name(name), weapon(weapon) {}

HumanA::~HumanA( void )
{
	std::cout << "HumanA has been died." << std::endl;
}

void	HumanA::attack( void )
{
	std::cout << this->name << " attacks with their " \
		<< this->weapon.getType() << std::endl;
}
