/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:06:03 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/23 22:24:10 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice") {
	cout << CYAN_BB << "Ice constructor called" << RESET << endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy) {
	cout << CYAN << "A copy of the Ice materia has been created" << RESET << endl;
}

Ice &Ice::operator=(const Ice &copy) {
	cout << CYAN << "Ice copy assignment operator called" << RESET << endl;
	if (this != &copy)
		AMateria::operator=(copy);
	return (*this);
}

Ice::~Ice() {
	cout << RED_BB << "Ice destructor called" << RESET << endl;
}

Ice *Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter &target) {
	cout << CYAN_BB << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}
