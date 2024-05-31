/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:15:11 by tday              #+#    #+#             */
/*   Updated: 2024/05/26 15:39:46 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Phonebook.hpp"
#include <cctype>    // std::toupper

/*
	Summary
	Transforms all characters in the given string to uppercase.
	The function iterates through each character of the string, converting them
	using the `std::toupper` function, which is safe for unsigned char values.

	Inputs
	[std::string &] str: Reference to the string that will be modified to
		uppercase.

	Outputs
	Modifies the input string by converting all of its characters to uppercase.
*/
void makeUpper(std::string &str)
{
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}

/*
	Summary
	Entry point for the PhoneBook application. This function initializes a
	PhoneBook object and enters a loop where it repeatedly displays a menu,
	reads user input, converts the input to uppercase for command matching,
	and executes the corresponding actions based on the command ('ADD',
	'SEARCH', 'EXIT'). The loop continues until the user enters 'EXIT',
	which breaks the loop and ends the program. If an unrecognized command
	is entered, it displays an "Invalid command!" error message.

	Inputs
	None directly; interacts with the user through the standard input to
		receive commands.

	Outputs
	Executes functions associated with adding contacts, searching contacts,
	or exiting the program.
	Prints messages to the console based on user actions and command validity.
*/
int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
	{
        phoneBook.print_menu();
        std::getline(std::cin, command);
		makeUpper(command);
        if (command == "ADD")
            phoneBook.add_contact();
        else if (command == "SEARCH")
            phoneBook.search();
        else if (command == "EXIT")
            break;
        else
            std::cout 	<< RED "Invalid command!" << std::endl
						<< std::endl;
    }
    return (0);
}
