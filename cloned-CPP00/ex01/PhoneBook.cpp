/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:32:56 by atang             #+#    #+#             */
/*   Updated: 2024/07/22 16:31:31 by atang            ###   ########.fr       */
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

void PhoneBook::press_enter() const
{
    std::cout << C "\nPress enter to return to the main menu..." RST << std::endl;
    std::cin.get();
}

bool PhoneBook::is_numeric(const std::string& str) const
{
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
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

	std::cout << "\nEnter first name: ";
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
		std::cout << G "\nContact successfully added to Phonebook!\n" RST;
	}
	press_enter();
}

void PhoneBook::search_contacts()
/*
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
*/
{
    std::cout << "\nEnter the index: ";
    std::string input;
    std::getline(std::cin, input);

    if (is_numeric(input))
    {
        int index = std::stoi(input);
        if (index >= 0 && index < 8 && !contacts[index].is_empty())
        {
			std::cout << B "\nContact Index: " RST<< index << std::endl;
			std::cout << std::endl;
            contacts[index].display_info();
        }
        else
        {
            std::cout << RED "\nInvalid index entered (empty or outside maximum number of contacts)" RST<< std::endl;
        }
    }
    else
    {
        std::cout << RED "\nInvalid input entered" RST << std::endl;
    }
	press_enter();
}

std::string	PhoneBook::truncate(const	std::string& str, size_t width) const
{
	if (str.length() >width)
		return str.substr(0, width - 1) + ".";
	else
		return str;
}

void PhoneBook::printContacts() const
{
	std::cout << std::endl;
	std::cout << "    ----------|----------|----------|---------- \n";
	std::cout << B "         Index" RST "|" B "First Name" RST "| " B "Last Name" RST "|" B "  Nickname\n" RST;
    std::cout << "    ----------|----------|----------|---------- \n";
	for (size_t i = 0, filled_index = 0; i < contacts.size(); ++i)
	{
        const Contact& contact = contacts[i];
        if (!contact.is_empty())
		{
			std::cout 	<< "    " << std::setw(10) << filled_index++ << '|'
						<< std::setw(10) << truncate(contact.first_name, 10) << '|' 
						<< std::setw(10) << truncate(contact.last_name, 10) << '|'
						<< std::setw(10) << truncate(contact.nickname, 10) << "\n";
		}
    }
}
