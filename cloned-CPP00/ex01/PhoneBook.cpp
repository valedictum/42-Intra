/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:32:56 by atang             #+#    #+#             */
/*   Updated: 2024/07/28 16:01:41 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
	Constructor for the PhoneBook class which initialises the oldest_index to 0
	and resizes the contacts vector to 8 elements
*/

PhoneBook::PhoneBook() : oldest_index (0)
{
	contacts.resize(8);
}

/*
	Displays message prompting user to press enter to return to the main menu
	and waits for enter to be pressed before continuing
*/

void PhoneBook::press_enter() const
{
    std::cout << C "\nPress enter to return to the main menu..." RST << std::endl;
    std::cin.get();
}

/*
	Bool that checks if a given string is numeric (true if numeric, false otherwise)
*/

bool PhoneBook::is_numeric(const std::string& str) const
{
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

/*
	Prints main menu of the Phonebook program displaying options to ADD a contact, 
	SEARCH for a specific contact, or EXIT the program.
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

/*
	Adds a new contact to phonebook. 
	- all fields are prompted for entry and storage in
	the new Contact object 
	- if any field is left empty, the contact is NOT added (error message displayed)
	- if all fields are filled, the contact is added to the phonebook at the oldest available index
	- oldest_index is updated to the next position in a circular manner
	- success message is displayed if contact has been successfully added
	- prompt to press enter to return to the main menu
*/

void PhoneBook::add_contact()
{
	Contact	new_contact; // new Contact object created

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

/*
	Search for a contact in the phonebook based on provided index (with validated input)
	- if index invalid (empty, out-of-range, or non-numeric), appropriate error message is displayed
	- after the search, user is prompted to press enter to return to the main menu
*/

void PhoneBook::search_contacts()
{
    std::cout << "\nEnter the index: ";
    std::string input;
    std::getline(std::cin, input); // reads a lone of text from std::cin and stores in input variable

    if (is_numeric(input)) // digit check
    {
        int index = std::stoi(input); // conversion of input string to integer index
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

/*
	Truncates a given string to a specified width (returns substring starting from index 0 to (width -1)) and adds "."
	OR returns original string without truncation if shorter than specified width
	- const does not modify the state of the PhoneBook object
*/

std::string	PhoneBook::truncate(const	std::string &str, size_t width) const
{
	if (str.length() > width)
		return str.substr(0, width - 1) + ".";
	else
		return str;
}

/*
	Prints the contacts in the phonebook in a table style displaying index, first name, last name, and nickname of each
	contact
	- loops through contacts in phonebook and, if not empty, outputs the field values with a width of 10 characters (truncated 
	with "." if > 10 characters)
*/

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
