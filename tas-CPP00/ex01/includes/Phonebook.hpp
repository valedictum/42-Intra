/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tday <tday@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:09:33 by tday              #+#    #+#             */
/*   Updated: 2024/05/05 18:58:22 by tday             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <limits> // std::numeric_limits

/* class */

/*
	Summary
	the PhoneBook class stores and manages up to eight Contact instances.
	it offers methods to add new contacts, search for existing contacts, and
	display a menu for user interactions.
*/
class PhoneBook
{
public:
    PhoneBook(); // constructor
	void print_menu();
    void add_contact();
	void print_search_menu() const;
    void search() const;

private:
    Contact contacts[8];
    int oldest_index;
};

#endif
