/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:29:57 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/07 17:17:03 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	jZombie = Zombie("Jae Zombie");
	Zombie*	ftZombie = newZombie("42 Zombie");

	randomChump("dog Zombie");
	jZombie.announce();
	ftZombie->announce();
	delete ftZombie;
	return (0);
}
