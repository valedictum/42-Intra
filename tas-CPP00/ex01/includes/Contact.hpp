/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:10:15 by tday              #+#    #+#             */
/*   Updated: 2024/05/25 01:24:23 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

/* libraries */
#include <iostream>	// std::cout, std::cin, std::endl
#include <string>	// std::string
#include <iomanip>	// std::setw

/* colours */
# define RESET	"\033[0m"
# define GRAY	"\033[1;30m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define MGNTA	"\033[1;35m"
# define CYAN	"\033[1;36m"
# define WHITE	"\033[1;37m"

/* class */

/*
	Summary
	the Contact class encapsulates personal information for individual contacts, 
	and provides methods to set, display, and verify the presence of this
	information.
*/
class Contact
{
	public:
		Contact(); // constructor
		void set_info();
		void display_info() const;
		void display_summary(int index) const;
		bool is_empty() const;
		static void print_centered(std::string text, int width);
	private:
		void display_field(const std::string& fieldName, const std::string& fieldValue, int maxLength) const;
		void wait_for_keypress() const;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
};

#endif
