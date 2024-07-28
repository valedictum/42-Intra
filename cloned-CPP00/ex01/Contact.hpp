/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:08:46 by atang             #+#    #+#             */
/*   Updated: 2024/07/29 08:11:37 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
#define	CONTACT_HPP

#include <iostream>
#include <string>
#include <vector> // for std::vector (dynamic array that can resize itself automatically)

# define RST    "\033[0m"      /* Reset to default color */
# define RED    "\033[1;31m"   /* Bold Red */
# define G      "\033[1;32m"   /* Bold Green */
# define Y      "\033[1;33m"   /* Bold Yellow */
# define B      "\033[1;34m"   /* Bold Blue */
# define M      "\033[1;35m"   /* Bold Magenta */
# define C      "\033[1;36m"   /* Bold Cyan */
# define W      "\033[1;37m"   /* Bold White */

/*
	- access specifiers: public (members are accessible from outside class),
	private (members cannot be accessed or viewed from outside class), and
	protected (members cannot be accessed from outside the class but they can be 
	accessed in inherited cases)
	- by default, all members of a class are private if you don't specify an 
	access specifier
	- attributes = variables within a class, methods = functions that belong 
	to a class
	- encapsulation is to make sure that sensitive data is hidden from 
	users - you must declare variables/attributes as private (if you want 
	others to read or modify the value of a private member, you can set public 
	get and set methods)
	- end class definition with ';' 
	- const is used to ensure that the fucntion does NOT modify the object's state
	i.e these functions do not modify the Contact object's data members (to ensure data 
	integrity and to prevent accidental modifications)
*/

class	Contact // Class keyword used to create a class called Contact
{
	public: // Access specifier
		Contact(); // Constructor for creating new Contact object
		void		set_info();
		void		add_contact();
		void		display_info() const;
		static void display_summary(const std::vector<Contact>& contacts);
		void		display_contacts () const;
		bool		is_empty() const;
		void		display_info_summary() const; 
		std::string get_info(const std::string& field) const;
		void		printContacts() const;
		std::string	truncate(const std::string& str, size_t	width);
		void 		set_first_name(const std::string& name);
		void 		set_last_name(const std::string& name);
		void 		set_nickname(const std::string& nick);
		void 		set_phone_number(const std::string& number);
		void 		set_darkest_secret(const std::string& secret);

	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif
