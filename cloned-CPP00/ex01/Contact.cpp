/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:31:17 by atang             #+#    #+#             */
/*   Updated: 2024/07/21 15:49:43 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : first_name (""), last_name (""), nickname (""), phone_number(""), darkest_secret("") {}  
	//std::cout << "Contact constructor called" << std::endl;
	//return;

/*
Contact::Contact(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}
*/

bool	Contact::is_empty() const
{
	return first_name.empty() || last_name.empty() || nickname.empty() || phone_number.empty() || darkest_secret.empty();
}

void	Contact::display_info() const
{
	std::cout << Y "\nFirst Name: " RST << first_name << "\n";
    std::cout << Y << "Last Name: " RST << last_name << "\n";
    std::cout << Y "Nickname: " RST << nickname << "\n";
    std::cout << Y "Phone Number: " RST << phone_number << "\n";
    std::cout << Y "Darkest Secret: " RST << darkest_secret << "\n";
}


void Contact::display_info_summary() const 
{
    std::cout << "\nFirst Name: " << first_name << "\n";
    std::cout << "Last Name: " << last_name << "\n";
    std::cout << "Nickname: " << nickname << "\n";
}

void Contact::display_summary(const std::vector<Contact>& contacts)
{
    std::cout << "Index  | First Name  | Last Name   | Nickname   \n";
    std::cout << "----------------------------------------------\n";

    for (size_t i = 0; i < contacts.size(); ++i)
	{
        const Contact& contact = contacts[i];
        std::cout << i << "      | "
                  << contact.first_name << "      | "
                  << contact.last_name << "      | "
                  << contact.nickname << "      \n";
    }
}
