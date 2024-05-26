/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:43:07 by tday              #+#    #+#             */
/*   Updated: 2024/05/04 13:43:07 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>	// cout, endl
#include <cctype>	// toupper

/*
	Summary
	Main function for a command-line application that takes arguments and
	prints them in uppercase. If no arguments are provided, it prints a specific
	error message. For each argument provided, the function converts all
	characters to uppercase and prints them separated by spaces.

	Inputs
	[int] argc: The count of command line arguments passed to the program.
	[char **] argv: An array of C-style strings representing the command line
		arguments.

	Outputs
	Prints the command line arguments in uppercase or an error message if no
	arguments are provided.
*/
int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j] != '\0'; j++)
				std::cout << (char)toupper(argv[i][j]);
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}