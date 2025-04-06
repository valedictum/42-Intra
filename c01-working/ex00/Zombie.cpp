/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:43:14 by atang             #+#    #+#             */
/*   Updated: 2025/03/29 22:15:28 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std:: string name) : name(name) {} // Constructor

Zombie::~Zombie() // Destructor
{
    std::cout << R << name << " is destroyed." RST << std::endl; 
}

void Zombie::announce() const // Announce function
{
    std::cout << G << name << ": BraiiiiiiinnnzzzZ" RST << std::endl; 
}