/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:49:39 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/23 22:24:17 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("cure") {
	cout << BLUE << "Cure constructor called" << RESET << endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy) {
	cout << BLUE << "A copy of the Cure materia has been created" << RESET << endl;
}

Cure &Cure::operator=(const Cure &copy) {
	cout << BLUE << "Cure copy assignment operator called" << RESET << endl;
	if (this != &copy)
		AMateria::operator=(copy);
	return (*this);
}

Cure::~Cure() {
	cout << RED_BB << "Cure destructor called" << RESET << endl;
}

Cure *Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter &target) {
	cout << BLUE << "* heals " << target.getName() << "'s wounds *" << endl;
}
