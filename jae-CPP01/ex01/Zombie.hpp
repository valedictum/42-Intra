/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:30:09 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/07 18:16:25 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string	name;

public:
	Zombie();
	Zombie( std::string name );
	~Zombie( void );

	void	announce( void );
	void	setName( std::string name );
};

Zombie*	zombieHorde( int N, std::string name );

#endif
