/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:36:24 by atang             #+#    #+#             */
/*   Updated: 2024/07/14 21:53:43 by sentry           ###   ########.fr       */
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
			//phoneBook.printContacts();
		}
		else if (command == "SEARCH")
		{
		//	phoneBook.search_contacts();
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
	/*
	// Access attributes and set values
	contact1.first_name = "This";
	contact1.last_name = "Person";
	contact1.phone_number = "0123456789";
	contact1.darkest_secret = "Likes Nickelback";
	// Print attribute values
	std::cout << "First name: " << contact1.first_name <<std::endl;
	std::cout << "Last name: " << contact1.last_name <<std::endl;
	std::cout << "Phone Number: " << contact1.phone_number <<std::endl;
	std::cout << "Darkest Secret: " << contact1.darkest_secret <<std::endl;
    */
	return(0);
}

