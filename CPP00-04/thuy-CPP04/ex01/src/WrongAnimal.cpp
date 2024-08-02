/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 00:14:35 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/19 15:09:54 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	cout << MAGENTA_BB << "A WrongAnimal type " << type << " has been born by default!" << RESET << endl;
	type = "WrongAnimal"; //Maybe use this->
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : Animal(copy) {
	cout << MAGENTA_BB << "A WrongAnimal type " << type << " has been born from a copy!" << RESET << endl;
	type = copy.type; //Maybe use this->
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
	cout << MAGENTA_BB << "A clone of a WrongAnimal type " << type << " has been assigned!" << RESET << endl;
	if (this != &copy)
        type = copy.type; //Maybe use this->
    return (*this);
}

WrongAnimal::~WrongAnimal() {
	cout << RED_BB << "A WrongAnimal type " << type << " has been destructed!" << RESET << endl;
}

void WrongAnimal::makeSound() const {
	cout << MAGENTA_BB << "NEEEEIiiiiiiiighhheeeeeheeeeheeeeheee!" << RESET << endl;
}