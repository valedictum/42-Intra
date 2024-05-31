/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:15:00 by tday              #+#    #+#             */
/*   Updated: 2024/05/25 23:15:00 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"

/*
	Summary
	Initializes a new PhoneBook instance with the oldest_index set to 0.
	This index is used to track the position of the oldest contact when adding
	new contacts once the phonebook is full.

	Inputs
	None.

	Outputs
	None.
*/
PhoneBook::PhoneBook() : oldest_index(0) {}

/*
	Summary
	Displays the main menu options for the PhoneBook application, which include
	adding a new contact, searching existing contacts, and exiting the
	application. The function uses ANSI color codes for visual enhancement.

	Inputs
	None.

	Outputs
	Prints the menu to the console.
*/
void PhoneBook::print_menu()
{
  std::cout	<< BLUE "=================== Phonebook ===================" << std::endl
			<< "==                                             ==" << std::endl
			<< "==       " CYAN "ADD" RESET"    - Add a new contact.           " BLUE "==" << std::endl
			<< "==       " CYAN "SEARCH" RESET" - Display contact info.        " BLUE "==" << std::endl
			<< "==       " CYAN "EXIT" RESET"   - Exit phonebook.              " BLUE "==" << std::endl
			<< "==                                             ==" << std::endl
			<< "=================================================" << std::endl
			<< "> " RESET;
}

/*
	Summary
	Adds a new contact to the phonebook. If the contact details are not empty,
	it stores the contact in the next available slot and updates the index to
	the oldest contact. If there are already 8 contacts it overwrites the oldest
	contact and displays a message. If the details are incomplete, it displays a
	message and does not add the contact.

	Inputs
	None.

	Outputs
	Modifies the contacts array by adding or updating a contact.
	Prints a message to the console if a contact is overwritten or the contact
	information is incomplete.
*/
void PhoneBook::add_contact()
{
    Contact newContact;
    newContact.set_info();

    if (!newContact.is_empty())
	{
		if (!contacts[oldest_index].is_empty())
			std::cout << RED "Oldest contact deleted due to memory constraints." RESET << std::endl << std::endl;
        contacts[oldest_index] = newContact;
        oldest_index = (oldest_index + 1) % 8;
    }
	else
        std::cout << RED "Contact information incomplete, not added to phonebook." RESET << std::endl << std::endl;
}

/*
	Summary
	Displays a menu listing each contact's summary (index, first name, last name,
	and nickname) for the user to select from by entering an index. This function
	formats the contacts in a table view and prompts the user to input an index
	to view more detailed contact information.

	Inputs
	None.

	Outputs
	Prints a formatted table of contact summaries to the console.
*/
void PhoneBook::print_search_menu() const
{
    int width = 10;

    std::cout << std::endl
              << BLUE "=================== Contacts ====================" << std::endl
              << "==                                             ==" << std::endl
              << "==" CYAN "   Enter the index to view contact details   " BLUE "==" << std::endl
              << "==                                             ==" << std::endl
              << "==|-------------------------------------------|==" << std::endl
              << "==|" RESET;
    Contact::print_centered("Index", width);
    std::cout << BLUE "|" RESET;
    Contact::print_centered("First Name", width);
    std::cout << BLUE "|" RESET;
    Contact::print_centered("Last Name", width);
    std::cout << BLUE "|" RESET;
    Contact::print_centered("Nickname", width);
    std::cout << BLUE "|==" << std::endl
              << "==|-------------------------------------------|==" RESET << std::endl;

    for (int i = 0; i < 8; ++i)
    {
        if (!contacts[i].is_empty())
            contacts[i].display_summary(i);
    }

    std::cout << BLUE "=================================================" << std::endl
              << "> " RESET;
}

/*
	Summary
	Displays a list of contact summaries and prompts the user to enter an index
	to view detailed information for a specific contact. It validates the input
	and shows contact details if the index is valid and the contact is not empty.
	Error messages are displayed for invalid inputs or empty contacts.

	Inputs
	None.

	Outputs
	Prints either contact details or an error message to the console.
*/
void PhoneBook::search() const
{
	print_search_menu();

    int index;
   	if (!(std::cin >> index)) // handle incorrect input
	{
        std::cin.clear();  // Clear the error flag on std::cin
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore the rest of the invalid input
        std::cout << RED "Invalid input. Please enter a valid integer." RESET << std::endl << std::endl;
		return;
    }
	else
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
        if (index >= 0 && index < 8 && !contacts[index].is_empty())
            contacts[index].display_info();
        else
            std::cout << RED "Invalid index or contact is empty." RESET << std::endl << std::endl;
    }
}
