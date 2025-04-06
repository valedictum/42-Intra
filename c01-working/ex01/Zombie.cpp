/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:42:14 by atang             #+#    #+#             */
/*   Updated: 2025/03/09 17:42:14 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << G << name << "Unnamed zombie created" << RST << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << G << name << " zombie created" << RST << std::endl;
}

Zombie::~Zombie()
{
    std::cout << R << name << " zombie destroyed" << RST << std::endl;
}

void Zombie::setName(const std::string &newName)
{
    name = newName;
}

void Zombie::announce() const // Announce function
{
    std::cout << B << name << ": BraiiiiiiinnnzzzZ" RST << std::endl; 
}