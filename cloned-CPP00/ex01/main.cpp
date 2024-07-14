/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:36:24 by atang             #+#    #+#             */
/*   Updated: 2024/07/10 22:56:44 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	//Contact		contact1; // Create an object of Contact
	PhoneBook	phoneBook; // Create an object of PhoneBook

	phoneBook.print_menu();
	std::string command;
	std::getline(std::cin, command);
	if (command == "ADD")
		phoneBook.add_contact();
	//if (command == "SEARCH")
	//	phoneBook.search_contacts();
	if (command == "EXIT")
		exit(0);
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

