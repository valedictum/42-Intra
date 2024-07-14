/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sentry <sentry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:31:17 by atang             #+#    #+#             */
/*   Updated: 2024/07/10 22:22:16 by sentry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : first_name (""), last_name (""), nickname (""), phone_number(""), darkest_secret("") {}  
{
	//std::cout << "Contact constructor called" << std::endl;
	return;
}

/*
Contact::Contact(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}
*/
