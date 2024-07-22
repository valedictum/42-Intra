/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:36:24 by atang             #+#    #+#             */
/*   Updated: 2024/07/22 15:55:13 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cstdlib>

static void	makeUpper(std::string	&str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		str[i] = std::toupper((unsigned char)str[i]);
	}
}

/*
void Contact::wait_for_keypress() const
{
    std::cout << "Press enter to return to menu..." << std::endl;
    std::cin.get(); // Wait for the user to press enter key
}
*/

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//Contact		contact1; // Create an object of Contact
	PhoneBook	phoneBook; // Create an object of PhoneBook

	while (true)
	{
		phoneBook.print_menu();
		std::string command;
		std::getline(std::cin, command);
		makeUpper(command);
		if (command == "ADD")
		{
			phoneBook.add_contact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.printContacts();
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
		//wait_for_keypress();
	}
	return(0);
}

