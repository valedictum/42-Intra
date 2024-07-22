/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:32:56 by atang             #+#    #+#             */
/*   Updated: 2024/07/22 00:36:21 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
PhoneBook::PhoneBook(void)
{
	//std::cout << "PhoneBook constructor called" << std::endl;
	return;
}
*/

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
	std::cout << std::endl;
	std::cout << B << "               Welcome to Phonebook!" RST << std::endl;
	std::cout << "             What would you like to do:" << std::endl;
	std::cout << G << "               ADD" << RST << ", " << Y << "SEARCH" << RST << ", or " << RED << "EXIT" << RST << "?" << std::endl;
	std::cout << std::endl;
	std::cout << "> ";
}

void PhoneBook::add_contact()
{
	Contact	new_contact;

	std::cout << "Enter first name: ";
	std::getline(std::cin, new_contact.first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, new_contact.last_name);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, new_contact.nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, new_contact.phone_number);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, new_contact.darkest_secret);

	if (new_contact.is_empty())
	{
		std::cout << RED "\nContact NOT added - entry required for ALL fields\n" RST;
	}
	else
	{
		contacts[oldest_index] = new_contact;
		oldest_index = (oldest_index + 1) % contacts.size();
		std::cout << G "Contact successfully added to Phonebook!\n" RST;
	}
}

void PhoneBook::search_contacts()
{
	std::cout << "\nEnter the index: ";
	int index;
	std::cin >> index;
	std::cin.ignore();
	if (index >= 0 && index < 8 && !contacts[index].is_empty())
		contacts[index].display_info();
	else
		std::cout << RED "\nInvalid index entered" RST << std::endl;
}

void PhoneBook::printContacts() const
{
	std::cout << std::endl;
	std::cout << "    ----------|----------|----------|---------- \n";
	std::cout << "         Index|First Name| Last Name|  Nickname \n";
    std::cout << "    ----------|----------|----------|---------- \n";
	for (size_t i = 0, filled_index = 0; i < contacts.size(); ++i)
	{
        const Contact& contact = contacts[i];
        if (!contact.is_empty())
		{
			std::cout 	<< "    " << std::setw(10) << filled_index++ << '|'
						<< std::setw(10) << contact.first_name << '|' 
						<< std::setw(10) << contact.last_name << '|'
						<< std::setw(10) << contact.nickname << "\n";
		}
    }
}
