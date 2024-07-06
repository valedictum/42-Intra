/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:55:19 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/09 13:30:23 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl 		harl;

	if (argc == 2)
	{
		std::string strInput = argv[1];
		harl.complain(strInput);
		return (0);
	}
	std::cout << "Wrong Input." << std::endl;
	return (1);
}
