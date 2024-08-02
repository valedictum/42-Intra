/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:31:17 by atang             #+#    #+#             */
/*   Updated: 2024/08/02 12:24:18 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
	Constructor for the Contact class which initialises all member variables to 
	empty strings
*/

Contact::Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

/*
	bool which returns true if any of the contact files are empty, otherwise false
*/

bool	Contact::is_empty() const
{
	return first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty();
}


std::string Contact::getInfo(const std::string& field) const
{
    if (field == "first_name")
        return first_name;
    else if (field == "last_name")
        return last_name;
    else if (field == "nickname")
        return nickname;
    else if (field == "phone_number")
        return phone_number;
    else if (field == "darkest_secret")
        return darkest_secret;
    else
        return "Invalid field";
}

/*
	Displays contact information
*/

/*
-> OLD DISPLAY_INFO
void	Contact::display_info() const
{
	std::cout << Y "First Name: " RST << first_name << "\n";
    std::cout << Y << "Last Name: " RST << last_name << "\n";
    std::cout << Y "Nickname: " RST << nickname << "\n";
    std::cout << Y "Phone Number: " RST << phone_number << "\n";
    std::cout << Y "Darkest Secret: " RST << darkest_secret << "\n";
}
*/

// NEW DISPLAY_INFO
void Contact::displayInfo() const
{
    std::cout << "First Name: " << first_name << "\n";
    std::cout << "Last Name: " << last_name << "\n";
    std::cout << "Nickname: " << nickname << "\n";
    std::cout << "Phone Number: " << phone_number << "\n";
    std::cout << "Darkest Secret: " << darkest_secret << "\n";
}

/*
	Displays contact summary information (index, first name, last name, nickname), taking a constant reference 
	to a vector of Contact objects as a parameter
	- iterates over the contact vector and prints the above for each non-empty contact
*/

/*
-> OLD DISPLAY_SUMMARY
void Contact::display_summary(const std::vector<Contact>& contacts)
{
    std::cout << "Index  | First Name  | Last Name   | Nickname   \n";
    std::cout << "----------------------------------------------\n";

    for (size_t i = 0; i < contacts.size(); ++i)
	{
        const Contact& contact = contacts[i];
        if (!contact.is_empty())
        {
            std::cout << i << "      | "
                    << contact.first_name << "      | "
                    << contact.last_name << "      | "
                    << contact.nickname << "      \n";
        }
    }
}
*/

/*
-> OLD SET_INFO

void Contact::set_info()
{
    std::cout << "\nEnter first name: ";
    std::getline(std::cin, first_name);
    std::cout << "Enter last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone_number);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkest_secret);

    if (is_empty()) {
        std::cout << "\nContact NOT added - entry required for ALL fields\n";
    } else {
        std::cout << "\nContact successfully added to Phonebook!\n";
    }
}
*/

// NEW SET_INFO
void Contact::setInfo()
{
    std::cout << "Enter first name: ";
    std::getline(std::cin, first_name);
    std::cout << "Enter last name: ";
    std::getline(std::cin, last_name);
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone_number);
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkest_secret);
}

/*
void Contact::set_first_name(const std::string& name)
{
    first_name = name;
}

void Contact::set_last_name(const std::string& name) {
    last_name = name;
}

void Contact::set_nickname(const std::string& nick) {
    nickname = nick;
}

void Contact::set_phone_number(const std::string& number) {
    phone_number = number;
}

void Contact::set_darkest_secret(const std::string& secret) {
    darkest_secret = secret;
}
*/