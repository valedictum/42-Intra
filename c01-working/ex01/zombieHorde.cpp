/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:28:25 by atang             #+#    #+#             */
/*   Updated: 2025/03/29 22:25:01 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (NULL); // Return nullptr if invalid input 
    
    Zombie  *horde = new Zombie[N];
    
    for (int i = 0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return horde; // returns pointer to the first zombie 
}
