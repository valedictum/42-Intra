/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:27:28 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/09 13:23:16 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) 
{
	std::cout << "Harl has been created." << std::endl;
}

Harl::~Harl( void ) 
{
	std::cout << "Harl has been detroyed." << std::endl;
}

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
	std::string	arrFuncString[4] = {"debug", "info", "warning", "error"};
	void	(Harl::*complainList[4])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for	(int i = 0; i < 4; i++)
	{
		if (arrFuncString[i] == level)
		{
			(this->*complainList[i])();
			return ;
		}
	}
}
