/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:32:56 by atang             #+#    #+#             */
/*   Updated: 2024/07/13 19:08:50 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	//std::cout << "PhoneBook constructor called" << std::endl;
	return;
}

void PhoneBook::print_menu()
{
	std::cout << std::endl;
	std::cout << "******************  "  B "Phonebook" RST"  ********************" << std::endl;
	std::cout << "**                                               **" << std::endl;
	std::cout << "**            " G "ADD" RST" - Add new contact              **" << std::endl;
	std::cout << "**      " Y "SEARCH" RST" - Display a specific contact      **" << std::endl;
	std::cout << "**           " RED "EXIT" RST" - Exit the program             **" << std::endl;
	std::cout << "**                                               **" << std::endl;
	std::cout << "***************************************************" << std::endl;
	std::cout << B << "              Welcome to Phonebook!" RST << std::endl;
	std::cout << "            What would you like to do:" << std::endl;
	std::cout << G << "              ADD" << RST << ", " << Y << "SEARCH" << RST << ", or " << RED << "EXIT" << RST << std::endl;
	std::cout << "> ";
}

void PhoneBook::add_contact()
{
	Contact newContact;
	std::cout << "Enter first name: ";
	std::getline(std::cin, contacts[oldest_index].first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, contacts[oldest_index].last_name);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, contacts[oldest_index].phone_number);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, contacts[oldest_index].darkest_secret);
	oldest_index = (oldest_index + 1) % 8;
	std::cout << "Contact added to PhoneBook\n";
}

/*
void PhoneBook::search_contacts()
{
	std::cout << "Enter the index: ";
	int index;
	std::cin >> index;
	std::cin.ignore();
	if (index >= 0 && index < 8)
		contacts[index].display_info();
	else
		std::cout << "Invalid index" << std::endl;
}
*/
