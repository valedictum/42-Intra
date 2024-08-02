/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tquemato <tquemato@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:55:37 by tquemato          #+#    #+#             */
/*   Updated: 2024/07/19 22:54:23 by tquemato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal() : type("Rando") {
	cout << YELLOW_BB << "A Random animal " << type << " is born by default!" << RESET << endl;
}

AAnimal::AAnimal(const AAnimal &copy) : type(copy.type) {
	cout << YELLOW_BB << "A clone of AAnimal " << type << " is born!" << RESET << endl;

}

AAnimal &AAnimal::operator=(const AAnimal &copy) {
	cout << YELLOW_BB << "A clone of AAnimal " << type << " is assigned!" << RESET << endl;
	if (this!= &copy)
		type = copy.type;
	return (*this);
}

AAnimal::~AAnimal() {
	cout << RED_BB << "The animal " << type << " is dead!" << RESET << endl;
}

void AAnimal::makeSound() const {
	cout << YELLOW_BB << "Weowww coof coof!" << RESET << endl;
}

string AAnimal::getType() const {
	return (type);
}