/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atang <atang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:08:46 by atang             #+#    #+#             */
/*   Updated: 2024/07/07 15:47:41 by atang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONTACT_HPP
#define	CONTACT_HPP

#include <iostream>

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

	//private://
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif
