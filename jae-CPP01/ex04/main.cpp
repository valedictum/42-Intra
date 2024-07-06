/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeshin <jaeshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:37:43 by jaeshin           #+#    #+#             */
/*   Updated: 2023/10/08 22:59:50 by jaeshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		Replace replace(argv[1], argv[2], argv[3]);
		replace.replace();
		return (0);
	}
	std::cout << "Wrong input" << std::endl;
	return (1);
}
