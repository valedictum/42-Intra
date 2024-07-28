/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:31:17 by atang             #+#    #+#             */
/*   Updated: 2024/07/28 15:59:04 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


/*
	Constructor for the Contact class which initialises all member variables to 
	empty strings
*/

Contact::Contact(void) : first_name (""), last_name (""), nickname (""), phone_number(""), darkest_secret("") {}  

/*
	bool which returns true if any of the contact files are empty, otherwise false
*/


bool	Contact::is_empty() const
{
	return first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty();
}

std::string Contact::get_info(const std::string& field) const
{
        if (field == "first_name")
		{
            return first_name;
        }
		else if (field == "last_name")
		{
            return last_name;
        }
		else if (field == "nickname")
		{
            return nickname;
        }
		else if (field == "phone_number")
		{
            return phone_number;
        }
		else if (field == "darkest_secret")
		{
            return darkest_secret;
        }
		else
		{
            return "Invalid field";
        }
    }

/*
	Displays contact information
*/

void	Contact::display_info() const
{
	std::cout << Y "First Name: " RST << first_name << "\n";
    std::cout << Y << "Last Name: " RST << last_name << "\n";
    std::cout << Y "Nickname: " RST << nickname << "\n";
    std::cout << Y "Phone Number: " RST << phone_number << "\n";
    std::cout << Y "Darkest Secret: " RST << darkest_secret << "\n";
}

/*
	Displays contact summary information (index, first name, last name, nickname), taking a constant reference 
	to a vector of Contact objects as a parameter
	- iterates over the contact vector and prints the above for each non-empty contact
*/

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
