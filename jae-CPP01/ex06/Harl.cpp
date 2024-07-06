/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:27:28 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/09 13:35:54 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {}

Harl::~Harl( void ) {}

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
}

void	Harl::complain( std::string level )
{
	std::string	arrFuncString[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	// void	(Harl::*complainList[4])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int			i;
	for	(i = 0; i < 4; i++)
	{
		if (arrFuncString[i] == level)
			break ;
	}
	switch (i)
	{
		case 0:
			this->debug();
			this->error();
			break;
		case 1:
			this->info();
			this->error();
			break;
		case 2:
			this->warning();
			this->error();
			break;
		case 3:
			this->error();
			this->error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
