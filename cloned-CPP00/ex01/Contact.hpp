/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:08:46 by atang             #+#    #+#             */
/*   Updated: 2024/07/21 15:51:41 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
#define	CONTACT_HPP

#include <iostream>
#include <string>
#include <vector>

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
	protected (members cannot be accessed fro outside the class but they can be 
	accessed in inherited cases)
	- by default, all members of a class are private if you don't specify an 
	access specifier
	- encapsulation is to make sure that sensitive data is hidden from 
	users - you must declare variables/attributes are private (if you want 
	others to read or moidfy the value of a private memener, you can set public 
	get and set methods) 
	- when variables are declared within a class, they are called attributes
	- methods are functions that belong to the class
	- end class definition with ';' 
*/

class	Contact // Class keyword used to create a class called Contact
{
	public: // Access specifier (members (attributes and methods) of the class are accessible from outside the class)
		Contact();
		//~Contact();
		void		set_info();
		void		display_info() const;
		static void display_summary(const std::vector<Contact>& contacts);
		void		display_contacts () const;
		bool		is_empty() const;
		void		display_info_summary() const; 
		//void 	wait_for_keypress(); const

	//private://
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif
