/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:36:24 by atang             #+#    #+#             */
/*   Updated: 2024/07/29 22:49:41 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cstdlib> // C++ version of stdlib.h for exit()

/*
	&str (reference to string object) as changes made to str parameter inside 
	fn will directly affect the original string passed to the fn (as opposed 
	to *str where changes made to *str would require dereferencing the pointer 
	to access and modify the original string object) i.e. operating on the 
	ORIGINAL std::string object without needing to return a new string 
*/

static void	makeUpper(std::string	&str) 
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		str[i] = std::toupper((unsigned char)str[i]);
	}
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	PhoneBook	phoneBook; // Create an instance of PhoneBook

	while (true)
	{
		phoneBook.print_menu(); // Display menu options
		std::string command; // Declare string variable to store user command
		std::getline(std::cin, command); // Get user input from console
		makeUpper(command);
		if (command == "ADD")
		{
			phoneBook.add_contact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.printContacts(); // Display all contacts
			phoneBook.search_contacts();
		}
		else if (command == "EXIT")
		{
			exit(0);
		}
		else
		{
			std::cout << std::endl;
			std::cout << RED "Invalid command entered!" RST << std::endl; 
			std::cout << "Please choose from: ADD, SEARCH, or EXIT" <<std::endl;
			std::cout << std::endl;
		}
	}
	return(0);
}
