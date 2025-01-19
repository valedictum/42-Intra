/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:43:14 by atang             #+#    #+#             */
/*   Updated: 2025/01/19 16:16:03 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std:: string name) : name(name)
{
    // Constructor
}

Zombie::~Zombie() // Destructor
{
    std::cout << R << name << " is destroyed." RST << std::endl; 
}

void Zombie::announce() const
{
    std::cout << G << name << ": BraiiiiiiinnnzzzZ" RST << std::endl; 
}