/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:13:27 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/23 21:27:12 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria(const string &type) : type(type) {
	cout << GREEN_BB << "AMateria constructor called for type " << type << RESET << endl;
}

AMateria::AMateria(const AMateria &copy) : type(copy.type) {
	cout << GREEN << "AMateria copy constructor called for type " << type << RESET << endl;
}

AMateria &AMateria::operator=(const AMateria &copy) {
	cout << GREEN << "AMateria copy assignment operator called for type " << type << RESET << endl;
	if (this != &copy)
		type = copy.type;
	return (*this);
}

AMateria::~AMateria() {
	cout << RED_BB << "AMateria destructor called for type " << type << RESET << endl;
}

const string &AMateria::getType() const {
	return (type);
}

//AMateria is abstract and cannot be instantiated
//clone() is implmented in derived classes to `return new AMateria(*this);`

void AMateria::use(ICharacter &target) {
	cout << GREEN << "AMateria type " << type << " used on " << target.getName() << RESET << endl;
}

