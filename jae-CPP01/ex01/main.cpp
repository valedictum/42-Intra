/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:29:57 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/11 14:28:59 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		n = 5;
	Zombie*	zombies = zombieHorde(n, "jaejun");
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}
