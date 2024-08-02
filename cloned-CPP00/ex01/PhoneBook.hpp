/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:33:14 by atang             #+#    #+#             */
/*   Updated: 2024/07/29 22:49:39 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
#define	PHONEBOOK_HPP

#include "Contact.hpp"
//#include <vector> // For std::vector container
#include <string> // For std::string class
#include <iostream>
#include <iomanip> // For manipulation of output formatting
//#include <sstream> // For std::stringstream
//#include <cctype>  // For ::isdigit()
#include <cstdlib> // For ::atoi()

#define MAX_CONTACTS 8

# define RST    "\033[0m"      /* Reset to default color */
# define RED    "\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */

/*
class	PhoneBook
{
	public:

		//std::vector<Contact> contacts;
		int			oldest_index;
		PhoneBook();
		void		add_contact();
		void		search_contacts();
		void		print_menu();
		void		print_search_menu();
		void		printContacts() const;
		std::string	truncate(const std::string& str, size_t	width) const;
		bool 		is_numeric(const std::string& str) const;
		void 		press_enter() const;

	private:
		std::vector<Contact> contacts;
};
*/

class PhoneBook
{
    public:
        PhoneBook();
        void add_contact();
        void search_contacts() const;
        void print_menu() const;
        void printContacts() const;
		void displaySummary() const;

    private:
        Contact contacts[MAX_CONTACTS];
        int contactCount;
        int oldestIndex;

        std::string truncate(const std::string& str, size_t width) const;
        bool is_numeric(const std::string& str) const;
        void press_enter() const;
};

#endif
