/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 00:48:08 by tday              #+#    #+#             */
/*   Updated: 2024/05/25 00:48:08 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

/*
	Summary
	Initializes a new Contact instance with empty values for first name,
	last name, nickname, phone number, and darkest secret.
	This ensures that all contact fields start in a defined state.

	Inputs
	None.

	Outputs
	None.
*/
Contact::Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

/*
	Summary
	Prompts the user to enter personal information for a contact, including
	first name, last name, nickname, phone number, and darkest secret.
	Each piece of information is input by the user and stored in the respective
	member variables.

	Inputs
	None directly; reads input from the standard input stream.

	Outputs
	Updates the contact's personal information fields based on user input.
*/
void Contact::set_info()
{
	std::cout	<< std::endl
				<< BLUE "================== New Contact ==================" << std::endl
   				<< CYAN "     Enter First Name:     " BLUE "> " RESET;
    std::getline(std::cin, first_name);
    std::cout	<< CYAN "     Enter Last Name:      " BLUE "> " RESET;
    std::getline(std::cin, last_name);
    std::cout	<< CYAN "     Enter Nickame:        " BLUE "> " RESET;
    std::getline(std::cin, nickname);
    std::cout	<< CYAN "     Enter Phone Number:   " BLUE "> " RESET;
    std::getline(std::cin, phone_number);
    std::cout	<< CYAN "     Enter Darkest Secret: " BLUE "> " RESET;
    std::getline(std::cin, darkest_secret);
	std::cout	<< BLUE "=================================================" RESET << std::endl
				<< std::endl;
}

/*
	Summary
	Displays a contact's field name and value formatted within a line.
	The field value is aligned  to ensure all lines are of equal length based on
	the specified maximum length. The parameters use 'const std::string&',
	indicating that they are references to the strings, allowing efficient passing
	without copying and ensuring that the function does not modify the original
	string values.

	Inputs
	[const std::string&] field_name: The name of the field to display.
		Passing by reference avoids copying.
	[const std::string&] field_value: The value of the field to display.
		Marked as 'const' to prevent modification.
	[int] max_length: The maximum length to which the field value should be padded.

	Outputs
	Prints the formatted field name and value to the console.
*/
void Contact::display_field(const std::string& field_name, const std::string& field_value, int max_length) const
{
    int field_length = field_value.length();
    std::cout << BLUE "==   " CYAN << field_name << ": " RESET << field_value;
    if (field_length <= max_length) {
        for (int i = max_length - field_length; i > 0; i--) {
            std::cout << " ";
        }
    }
    std::cout << BLUE "==" RESET << std::endl;
}

/*
	Summary
	Prompts the user to press enter to return to the main menu and waits for the
	user to press a key. This function ensures that the program pauses until the
	user acknowledges the prompt by pressing a key, providing a simple way to
	pause the flow of the program until user interaction.

	Inputs
	None.

	Outputs
	Prints a prompt to the console and waits for a key press.
*/
void Contact::wait_for_keypress() const
{
    std::cout << "Press enter to return to menu..." << std::endl;
    std::cin.get(); // Wait for the user to press enter key
}

/*
	Summary
	Displays detailed information about a contact.The function calculates the 
	length to center the contact's name in the header and adjusts the display
	based on the combined length of the first and last names. The function
	also waits for a key press before returning to the main menu.

	Inputs
	None.

	Outputs
	Prints the contact's detailed information to the console and waits for a
	key press.
*/
void Contact::display_info() const
{
	int name_length = first_name.length() + last_name.length() + 3;
	int	line_length = (49 - name_length) / 2;

	std::cout << std::endl;

	if (line_length >= 0)
	{
		std::cout << BLUE;
		for (int i = 0; i < line_length; i++)
			std::cout << "=";

		std::cout <<  " " << first_name << " " << last_name << " ";

		for (int i = 0; i < line_length; i++)
			std::cout << "=";

		if (name_length % 2 == 0)
			std::cout << "=";

		std::cout << RESET << std::endl;
	}
	else
		std::cout <<  BLUE << first_name << " " << last_name << RESET << std::endl;

	std::cout << BLUE "==                                             ==" RESET << std::endl;

	display_field("First Name", first_name, 30);
    display_field("Last Name", last_name, 31);
    display_field("Nickname", nickname, 32);
    display_field("Phone Number", phone_number, 28);
    display_field("Darkest Secret", darkest_secret, 26);

	std::cout << BLUE "==                                             ==" RESET << std::endl;

	std::cout	<< BLUE "=================================================" RESET << std::endl
				<< std::endl;
	wait_for_keypress();
}

/*
	Summary
	Centers and prints a given text string within a specified width.
	If the text is shorter than the width, it adds padding to both sides to center
	the text. If the text fits exactly or is longer than the width, it prints the
	text as is, adding a space after the text only if the text length is exactly
	9 characters.

	Inputs
	[std::string] text: The text to be centered and printed.
	[int] width: The total width within which the text should be centered.

	Outputs
	Prints the centered text to the console.
*/
void Contact::print_centered(std::string text, int width)
{
    int padding = (width - text.length()) / 2;
    if (padding > 0)
        std::cout << std::setw(padding) << "" << text << std::setw(padding + (width - text.length()) % 2) << "";
	else if (text.length() == 9)
		std::cout << text << " ";
	else
        std::cout << text;
}

/*
	Summary
	Displays a summary of a contact's information in a row format with indexed columns.
	It includes the contact's index number, first name, last name, and nickname.
	Each name is truncated to fit within a specified width of 10 characters, adding an
	ellipsis if the name exceeds 9 characters to indicate truncation.

	Inputs
	[int] index: The index of the contact in the phonebook, displayed at the start of
		the summary row.

	Outputs
	Prints the contact's summary information to the console, formatted within columns.
*/
void Contact::display_summary(int index) const
{
	int width = 10;

    std::cout << BLUE "==|" RESET << "    " << index << "     " << BLUE "|" RESET;
    print_centered((first_name.length() > 9 ? first_name.substr(0, 9) + "." : first_name), width);
	std::cout << BLUE "|" RESET;
    print_centered((last_name.length() > 9 ? last_name.substr(0, 9) + "." : last_name), width);
	std::cout << BLUE "|" RESET;
    print_centered((nickname.length() > 9 ? nickname.substr(0, 9) + "." : nickname), width);
	std::cout << BLUE "|==" RESET << std::endl;
}

/*
	Summary
	Checks if any of the contact's fields are empty.This function is used to determine
	if the contact has incomplete information.

	Inputs
	None.

	Outputs
	Returns true if any of the fields are empty, otherwise returns false.
*/
bool Contact::is_empty() const
{
    return first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty();
}
