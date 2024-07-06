/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:55:19 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/09 12:23:45 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::string	input;
	Harl 		harl;

	do
	{
		std::cout << "Enter a complaint level: ";
		std::cin >> input;
		harl.complain(input);
	} while (input != "exit");
	return (0);
}
